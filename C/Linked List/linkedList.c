#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linkedList.h"

void userDispList(LDT val){
    printf(" %d /",val);
}

int main()
{
    linkedList l;
    LDT val;
    int c,index;

    do{
        printf("Select choice: \n\n");
        printf("1- Initialize a LIST \n");
        printf("2- Append\n");
        printf("3- Insert\n");
        printf("4- Update\n");
        printf("5- Delete\n");
        printf("6- Check Full LIST\n");
        printf("7- Check Empty LIST\n");
        printf("8- Display LIST\n");
        printf("9- Clear LIST\n");
        printf("0- Exit\n");
        printf("> ");
        scanf("%d",&c);
        printf("----------------------------------------------------\n");

        if(!isInitialized(&l)&& c!=1 && c!=0){
            printf(">> LIST isn't INITIALIZED\n");
            printf("----------------------------------------------------\n");}


        else{

            switch(c){
                case 1: //initialize case
                    if(!isInitialized(&l)){
                        initList(&l);
                        printf(">> LIST initialized Successfully...\n");}
                    else{printf(">> LIST is already INITIALIZED\n");}
                    break;

                case 2: //append case
                    if(!isFull(&l)){
                        printf("Enter the value: ");
                        scanf("%d",&val);
                        append(&l,val);
                        printf(">> %d appended Successfully...\n",val);}
                     else {printf(">> LIST is FULL\n");}
                    break;

                case 3: //insert case
                    if(!isFull(&l))
                    {
                        printf("Enter the index: ");
                        scanf("%d",&index);
                        if(canInsert(&l,index))
                            {
                                printf("Enter the value: ");
                                scanf("%d",&val);
                                insertItem(&l,index,val);
                                printf(">> %d inserted Successfully at Index %d ...\n",val,index);
                            }
                            else{printf(">> INDEX is OUT of SIZE\n");}
                    }


                    else {printf(">> LIST is FULL\n");}
                    break;

                case 4: //update case
                    if((!isEmpty(&l) && isInitialized(&l)) || isFull(&l))
                        {
                            printf("Enter the index: ");
                            scanf("%d",&index);
                            if(canGetItem(&l,index))
                            {
                                printf("Enter the new value: ");
                                scanf("%d",&val);
                                updateItem(&l,index,val);
                                printf(">> Index: %d updated Successfully by Value: %d ...\n",index,val);
                            }
                            else{printf(">> INDEX is OUT of RANGE\n");}
                        }
                    else{printf(">> LIST is EMPTY\n");}
                    break;

                case 5: //delete case
                    if((!isEmpty(&l) && isInitialized(&l)) || isFull(&l))
                        {
                            printf("Enter the index: ");
                            scanf("%d",&index);
                            if(canDelete(&l,index))
                            {
                                printf(">> %d deleted Successfully...\n", deleteItem(&l,index));
                            }
                            else{printf(">> INDEX is OUT of RANGE\n");}

                        }
                    else{printf(">> LIST is EMPTY\n");}
                    break;

                case 6: //isFull case
                    isFull(&l)?printf(">> LIST is FULL\n"):printf(">> LIST isn't FULL\n");
                    break;

                case 7: //isEmpty case
                    isEmpty(&l)?printf(">> LIST is EMPTY\n"):printf(">> LIST isn't EMPTY\n");
                    break;

                case 8://display case
                    if((!isEmpty(&l) && isInitialized(&l)) || isFull(&l) ){
                        dispList(&l,&userDispList);}
                    else {printf(">> LIST is EMPTY\n");}
                    break;

                case 9:// clear case
                    clearList(&l);
                    printf(">> LIST Cleared Successfully...\n");
                break;

                default:
                    if(c!=0 && c>9)
                        printf(">> WRONG CHOICE\n");}



                if(c!=0)
                    {
                        printf(">> LIST Size: %d\n",getSize(&l));
                        printf(">> INDEX Pos: %d\n",getPos(&l));

                    }
                else{printf(">> THANKS, ending..\n");}
                printf("----------------------------------------------------\n");





    }}while(c!=0);

}
