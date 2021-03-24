#include <stdio.h>
#include <stdlib.h>

#include"queueList.h"
typedef int QDT; // QDT --> Queue Data Type
#define MAX_QUEUE 10

void userDispQueue(QDT val){
    printf(" %d /",val);
}


int main()
{
    Queue q;
    QDT val;
    int c;

    do{
        printf("Select choice: \n\n");
        printf("1- Initialize a QUEUE \n");
        printf("2- en-QUEUE\n");
        printf("3- de-QUEUE\n");
        printf("4- Check Full QUEUE\n");
        printf("5- Check Empty QUEUE\n");
        printf("6- Display QUEUE\n");
        printf("7- Clear QUEUE\n");
        printf("0- Exit\n");
        printf("> ");
        scanf("%d",&c);
        printf("----------------------------------------------------\n");

        if(!isInitialized(&q)&& c!=1 && c!=0){
            printf(">> QUEUE isn't INITIALIZED\n");
            printf("----------------------------------------------------\n");}


        else{

            switch(c){
                case 1: //initialize case
                    if(!isInitialized(&q)){
                        initQueue(&q);
                        printf(">> QUEUE initialized Successfully...\n");}
                    else{printf(">> QUEUE is already INITIALIZED\n");}
                    break;

                case 2: //enQueue case
                    if(!isFull(&q)){
                        printf("Enter the value: ");
                        scanf("%d",&val);
                        enQueue(&q,val);
                        printf(">> %d appended Successfully...\n",val);}
                     else {printf(">> QUEUE is FULL\n");}
                    break;

                case 3: //deQueue case
                    if((!isEmpty(&q)&& isInitialized(&q)) || isFull(&q)){
                        printf(">> %d dequeued Successfully...\n", deQueue(&q));}
                    else{printf(">> QUEUE is EMPTY\n");}
                    break;

                case 4: //isFull case
                    isFull(&q)?printf(">> QUEUE is FULL\n"):printf(">> QUEUE isn't FULL\n");
                    break;

                case 5: //isEmpty case
                    isEmpty(&q)?printf(">> QUEUE is EMPTY\n"):printf(">> QUEUE isn't EMPTY\n");
                    break;

                case 6://display case
                    if((!isEmpty(&q) && isInitialized(&q)) || isFull(&q) ){
                        dispQueue(&q,&userDispQueue);}
                    else {printf(">> QUEUE is EMPTY\n");}
                    break;

                case 7:// clear case
                    clearQueue(&q);
                    printf(">> QUEUE Cleared Successfully...\n");
                break;

                default:
                    if(c!=0 && c>7)
                        printf(">> WRONG CHOICE\n");}



                if(c!=0){
                    printf(">> QUEUE SIZE: %d\n",getSize(&q));
                    if(!isEmpty(&q)){
                    printf(">> Front: %d index\n",getFront(&q));
                    printf(">> Rear: %d index\n",getRear(&q));}}
                else{printf(">> THANKS, ending..\n");}
                printf("----------------------------------------------------\n");





    }}while(c!=0);

}
