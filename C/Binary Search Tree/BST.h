typedef int TDT;
typedef QDT TDT;

/** Special Cases at root node, leaves and in between that have 2 child or one **/

// Node Struct
typedef struct Tnode {
    TDT val;
    struct node *right;
    struct node *left;
}treeNode;

typedef struct{
    treeNode *root,*prevTemp,*nextL,*nextR;
    treeNode *temp;
    int size; //to save time complexity to constant instead of N times because of loop
    int treeIntialized; // to store if the stack initialized
    int depth;
}BST;

//Binary Search Tree Functions
void initTree(BST *pt){
    pt->root = NULL;
    pt->temp = NULL;
    pt->prevTemp = NULL;
    pt->nextL = pt->nextR = NULL;
    pt->size = 0;
    pt->depth = -1;
    pt->treeIntialized =1;
}

int isTreeInitialized(BST *pt){
    if (pt->treeIntialized ==1)
        return 1;
    else
        return 0;
}

treeNode* createNode(TDT val){
    treeNode *pn = (treeNode*) malloc(sizeof(treeNode));
    pn->right = pn->left = NULL;
    pn->val = val;
return pn;
}

// get longest depth for the node --> not for user
int getDepth(treeNode *ptr){
    int count = 0;

    //leaves
    if(ptr->left == NULL && ptr->right == NULL)
    {
       return 0;
    }


    if(ptr->left == NULL && ptr->right != NULL)
    {
        ptr = ptr->right;
        count+=1+getDepth(ptr);
    }

    else if(ptr->right == NULL && ptr->left != NULL)
    {
       ptr = ptr->left;
       count+=1+getDepth(ptr);
    }

    else if(ptr->left != NULL && ptr->right != NULL)
    {
      int left = 1+ getDepth(ptr->left);
      int right = 1+ getDepth(ptr->right);
      if(left>right){count+=left;}
      else{count+=right;}
    }
    return count;
}

// for user interface
int getNodeDepth(BST *pt, TDT val){
    pt->temp = pt->root;
    searchItem(pt,val);
    int size = getDepth(pt->temp);
    pt->temp = pt->root;
    return size;
}

int nodeBalancedFactor(BST *pt, TDT val)
{
    pt->temp = pt->root;
    searchItem(pt,val);
    treeNode *tempTemp = pt->temp;

    int leftDepth,rightDepth,lVal,rVal;
    if(tempTemp->left)
    {
        lVal = tempTemp->left->val;
        leftDepth = 1+getNodeDepth(pt,lVal);
    }
    else{leftDepth = 0;}

    if(tempTemp->right)
    {
        rVal = tempTemp->right->val;
        rightDepth = 1+getNodeDepth(pt,rVal);
    }
    else{rightDepth = 0;}

    pt->temp = pt->root;
    return leftDepth - rightDepth;
}
int isNodeBalanced(BST *pt, TDT val)
{
    int factor = nodeBalancedFactor(pt,val) ;
    return (factor==-1 || factor==0 || factor==1);
}

int isTreeBalanced(BST *pt)
{

    return isNodeBalanced(pt,pt->root->val);
}

void insertItem(BST *pt, TDT val){
    treeNode *prev;
    int depthCount;
    if(pt->temp == NULL)
        {
            pt->temp = createNode(val);
            if (pt->size ==0){pt->root = pt->temp;pt->prevTemp=pt->temp;}

        }

    else
        {
            while(pt->temp != NULL)
            {
                if(val<pt->temp->val) //left case
                {
                    prev = pt->temp;
                    pt->temp = pt->temp->left;
                }
                else //right case
                {
                    prev = pt->temp;
                    pt->temp = pt->temp->right;
                }

            }
            pt->temp = createNode(val);
            if(val<prev->val){prev->left=pt->temp;}
            else{prev->right=pt->temp;}
            pt->temp = pt->root;
            pt->prevTemp = pt->root;
        }
        pt->size++;


}

TDT minRight(BST *pt){
/**pre: pt->temp->right != NULL**/
TDT val;
pt->temp = pt->temp->right;
while(pt->temp->left != NULL)
    {
        pt->prevTemp=pt->temp;
        pt->temp = pt->temp->left;
    }
val = pt->temp->val;
//pt->temp = pt->root;
return val;
}

TDT maxLeft(BST *pt){
/**pre: pt->temp->left != NULL**/
TDT val;
pt->temp = pt->temp->left;
while(pt->temp->right != NULL)
    {
        pt->prevTemp=pt->temp;
        pt->temp = pt->temp->right;
    }
val = pt->temp->val;
return val;
}

int getTreeSize(BST *pt){
return pt->size;
}

void returnTemp(BST *pt){
pt->temp = pt->root;
}

int searchItem(BST *pt, TDT val){
    treeNode *prev;
    while(pt->temp != NULL)
            {
                if(val<pt->temp->val) //left case
                {
                    prev = pt->temp;
                    pt->temp = pt->temp->left;
                }
                else if(val>pt->temp->val) //right case
                {
                    prev = pt->temp;
                    pt->temp = pt->temp->right;
                }

                else //equal case
                {
                    //pt->temp=pt->root;
                    pt->prevTemp = prev;
                    return 1;
                }
            }
            //pt->temp=pt->root;
            pt->prevTemp = prev;
            return 0;
}

// Depth first traversal
void dispTree_IN_ORDER(BST *pt,void (*pf)(TDT)){ // LVR
    treeNode *prev=pt->temp; // to store every last node
    if(pt->temp->left != NULL)
    {
        pt->temp = pt->temp->left;
        dispTree_IN_ORDER(pt,pf);
    }

    (*pf)(prev->val); // to print value before going to the right side (LVR)

    if(prev->right != NULL)
    {
        pt->temp = prev->right;
        dispTree_IN_ORDER(pt,pf); // the second call will pass from first if condition and print the last prev value
    }
}

void dispTree_PRE_ORDER(BST *pt,void (*pf)(TDT)){ // VLR
    treeNode *prev=pt->temp; // to store every last node

    (*pf)(prev->val); // to print value of root value first (VLR)

    if(pt->temp->left != NULL)
    {
        pt->temp = pt->temp->left;
        dispTree_PRE_ORDER(pt,pf);
    }

    if(prev->right != NULL)
    {
        pt->temp = prev->right;
        dispTree_PRE_ORDER(pt,pf); // the second call will pass from first if condition and print the last prev value
    }
}

void dispTree_POST_ORDER(BST *pt,void (*pf)(TDT)){ // LRV
    treeNode *prev=pt->temp; // to store every last node
    if(pt->temp->left != NULL)
    {
        pt->temp = pt->temp->left;
        dispTree_POST_ORDER(pt,pf);
    }

    if(prev->right != NULL)
    {
        pt->temp = prev->right;
        dispTree_POST_ORDER(pt,pf); // the second call will pass from first if condition and print the last prev value
    }

    (*pf)(prev->val); // to print value of left then right before root (LRV)
}

//Level first traversal
void dispTree_LEVEL_FIRST_REC(treeNode *ptr,void (*pf)(TDT)){

}

void dispTree_LEVEL_FIRST(BST *pt,void (*pf)(TDT)){
    Queue q;
    initQueue(&q);
    if(pt->root){enQueue(&q,pt->root->val);}
    if(pt->root->left){enQueue(&q,pt->root->left->val);}
    if(pt->temp->right){ enQueue(&q,pt->root->right->val);}
    (*pf)(deQueue(&q));
    while(!isEmpty(&q))
    {
        searchItem(pt,getFront(&q));
        if(pt->temp->left){enQueue(&q,pt->temp->left->val);}
        if(pt->temp->right){enQueue(&q,pt->temp->right->val);}
        (*pf)(deQueue(&q));
        pt->temp = pt->root;
    }

}


void deleteItem(BST *pt, TDT val){
treeNode *curr;
            searchItem(pt,val);
            // case1: leaves
            if(pt->temp->right == NULL && pt->temp->left == NULL)
            {
                curr = pt->temp;
                if(curr->val<pt->prevTemp->val){pt->prevTemp->left = NULL;}
                else{pt->prevTemp->right = NULL;}
                free(curr);
                pt->temp = pt->root;
                pt->prevTemp = pt->root;
                pt->size--;
                return;
            }

            // case2: root has a subtree and Balanced Tree
            else
            {

                TDT tempVal;
                curr = pt->temp;
                if(curr->left != NULL)
                {
                   tempVal =  maxLeft(pt);
                }

                else if(curr->right != NULL)
                {
                    tempVal =  minRight(pt);
                }
                pt->temp = pt->root;
                pt->prevTemp = pt->root;
                deleteItem(pt,tempVal);
                curr->val = tempVal;

            }
}
