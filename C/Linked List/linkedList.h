typedef int LDT;

/** Special Cases at the head and end of the list **/

// Node Struct
typedef struct node {
    LDT val;
    struct node *next;
    struct node *prev;
}listNode;

typedef struct{
    listNode *temp;
    listNode *head, *end;
    int size; //to save time complexity to constant instead of N times because of loop
    int listIntialized; // to store if the stack initialized
    int currentPos;
}linkedList;

//linkedList Functions
void initList(linkedList *pl){
    pl->temp = NULL;
    pl->head = NULL;
    pl->end = NULL;
    pl->size = 0;
    pl->currentPos = -1;
    pl->listIntialized =1;
}

int isInitialized(linkedList *pl){
    if (pl->listIntialized ==1)
        return 1;
    else
        return 0;
}

LDT getItem(linkedList *pl, int index){
    /** pre-condition: list is initialized && not empty && index in range **/
    if(pl->currentPos-index>index)
        {
            pl->temp=pl->head;
            pl->currentPos = 0;
        }

    //if index before temp position
    if(index<pl->currentPos)
    {
        for(int i = pl->currentPos ;i>index ;i--)
        {
           pl->temp = pl->temp->prev;
        }
    }
    //if index after temp position
    else if(index>pl->currentPos)
    {
       for(int i = pl->currentPos;i<index;i++)
       {
          pl->temp = pl->temp->next;
       }
    }

    return pl->temp->val;
}

void updateItem(linkedList *pl,int index,LDT val){
    /** pre-condition: list is initialized && not empty && index in range **/
    //to select shortest path to accelerate the next stage (for loop)
    if(pl->currentPos-index > index)
        {
            pl->temp=pl->head;
            pl->currentPos = 0;
        }

    if( (pl->size-1)-pl->currentPos >( pl->size-1)- index)
        {
            pl->temp=pl->end;
            pl->currentPos = pl->size-1;
        }

    //if index before temp position
    if(index<pl->currentPos)
    {
        for(int i = pl->currentPos ;i>index ;i--)
        {
           pl->temp = pl->temp->prev;
        }
    }
    //if index after temp position
    else if(index>pl->currentPos)
    {
       for(int i = pl->currentPos;i<index;i++)
       {
          pl->temp = pl->temp->next;
       }
    }

    pl->temp->val = val;
    pl->currentPos = index;
}

int getSize(linkedList *pl){
    return pl->size;
}

int getPos(linkedList *pl){
    return pl->currentPos;
}

void clearList(linkedList *pl){
    /** pre-condition: list is initialized && not empty **/
    for(pl->temp = pl->head;pl->head != NULL;pl->temp = pl->head)
    {
        pl->head = pl->head->next;
        free(pl->temp);
    }
    pl->end = NULL;
    pl->size = 0;
    pl->currentPos = -1;


}

int isEmpty(linkedList *pl){
    return pl->size == 0;
}

int isFull(linkedList *pl){ //list has no specific size so isFall is false always --> return 0
    return 0;
}


void append(linkedList *pl,LDT val){
    /** pre-condition: list is initialized && not full **/

    listNode *pn = (listNode*)malloc(sizeof(listNode)); //creating a node and point to it by *pn
     // First Node Case
    if(pl->head == NULL)
    {
        pn->prev = NULL;
        pl->head = pn;
    }
    // Last Node Case
    else
    {
        pn->prev = pl->end;
        pl->end->next = pn; /** was a FUCKING error to forget this line
        that let the previous node's next ptr point to the new node**/
    }

    pl->end = pn;
    pl->end->val = val;
    pl->end->next = NULL;
    pl->end = pn;
    pl->temp = pl->end;
    pl->size++;
    pl->currentPos=pl->size-1;
}

int canDelete(linkedList *pl,int index){
    return (index>=0 && index<pl->size);
}

int canInsert(linkedList *pl,int index){
    return (index>=0 && index<=pl->size);
}
int canGetItem(linkedList *pl,int index){
    return (index>=0 && index<=pl->size);
}


void insertItem(linkedList *pl,int index,LDT val){
    /** pre-condition: list is initialized && not full && index in size **/
    listNode *pn = (listNode*)malloc(sizeof(listNode)); //creating a node and point to it by *pn

     //First node and the list empty
     if(index==0 && pl->head==NULL)
     {
        // u can call append func
        pn->prev = pn->next = NULL;
        pl->head = pl->end = pl->temp = pn;
        pl->temp->val = val;
        pl->size++;
        pl->currentPos=pl->size-1;
        return;
     }

     // First Node Case
    else if(index == 0)
    {
        pl->temp = pl->head;
        pl->head = pn;
    }
    // Last Node Case
    else if(index==pl->size)
    {
        pn->prev = pl->end;
        pn->next = pl->end->next;
        pl->end->next = pn;
        pl->end = pn;
        pl->temp = pn;
        pl->temp->val = val;
        pl->currentPos = index;
        pl->size++;
        return;
    }

    // in between
    else
    {
        //if distance from head is shorter than distance from temp position
        if(pl->currentPos-index>index)
        {
            pl->temp=pl->head;
            pl->currentPos = 0;
        }

        //if index before temp position
        if(index<pl->currentPos)
        {
            for(int i = pl->currentPos ;i>index ;i--)
            {
               pl->temp = pl->temp->prev;
            }
        }
        //if index after temp position
        else if(index>pl->currentPos)
        {
           for(int i = pl->currentPos;i<index;i++)
           {
              pl->temp = pl->temp->next;
           }
        }
    }
    pn->prev = pl->temp->prev;
    pn->next = pl->temp;
    pl->temp->prev = pn;
    if(index != 0){pn->prev->next = pn;} // special case
    pl->temp = pn;
    pl->currentPos = index;
    pl->temp->val = val;
    pl->size++;
}


LDT deleteItem(linkedList *pl,int index){
    /** pre-condition: list is initialized && not empty && index in range **/
    /** == pre-condition: index>=0 && index<size **/
    listNode *xPtr;
    LDT deletedVal;
    // First Node Case
    if(index==0)
    {
        xPtr = pl->head;
        pl->temp = pl->head->next;
        pl->head = pl->temp;
        pl->currentPos = index;

    }
    // Last Node Case
    else if(index==pl->size-1)
    {
        xPtr = pl->end;
        pl->temp = pl->end->prev;
        pl->end = pl->temp;
        pl->end->next = NULL;
        pl->currentPos = index-1;
    }


    // In Between Case
    else if(index>0 && index<pl->size-1)
    {
        //if distance from head is shorter than distance from temp position
        if(pl->currentPos-index>index)
        {
            pl->temp=pl->head;
            pl->currentPos = 0;
        }

        //if index before temp position
        if(index<pl->currentPos)
        {
            for(int i = pl->currentPos ;i>index ;i--)
            {
               pl->temp = pl->temp->prev;
            }
        }
        //if index after temp position
        else if(index>pl->currentPos)
        {
           for(int i = pl->currentPos;i<index;i++)
           {
              pl->temp = pl->temp->next;
           }
        }

        xPtr = pl->temp;
        pl->temp = pl->temp->next;
        xPtr->prev->next = pl->temp;
        pl->temp->prev = xPtr->prev;
        pl->currentPos = index;
    }

    deletedVal=xPtr->val;
    free(xPtr);
    pl->size--;
    return deletedVal;
}


void dispList(linkedList *pl,void (*pf)(LDT)){
    printf("\n\nList: /");
    for(listNode *p = pl->head;p!= NULL;p=p->next)
        {
            (*pf)(p->val);
        }
        printf("\n\n\n");
}
