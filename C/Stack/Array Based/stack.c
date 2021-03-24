#include <stdio.h>
#include <stdlib.h>
typedef int SDT; // SDT --> Stack Data Type
#include "stack.h"

#define MAX_STACK 5


void userDispStack(SDT val){
    printf("         %d        \n",val);
}




main()
{
    int c;
    Stack s;
    SDT val;
    do{
        printf("Select choice: \n\n");
        printf("1- Initialize a STACK \n");
        printf("2- Push in STACK\n");
        printf("3- Pop out STACK\n");
        printf("4- Check Full STACK\n");
        printf("5- Check Empty STACK\n");
        printf("6- Display STACK\n");
        printf("7- Clear STACK\n");
        printf("0- Exit\n");
        printf("> ");
        scanf("%d",&c);
        printf("----------------------------------------------------\n");

        if(!isInitialized(&s)&& c!=1 && c!=0){
            printf(">> STACK isn't INITIALIZED\n");
            printf("----------------------------------------------------\n");}


        else{

            switch(c){
                case 1: //initialize case
                    if(!isInitialized(&s)){
                        initStack(&s);
                        printf(">> STACK initialized Successfully...\n");}
                    else{printf(">> STACK is already INITIALIZED\n");}
                    break;

                case 2: //push case
                    if(!isFull(&s)){
                        printf("Enter the value: ");
                        scanf("%d",&val);
                        push(&s,val);
                        printf(">> %d pushed Successfully...\n",val);}
                     else {printf(">> STACK is FULL\n");}
                    break;

                case 3: //pop case
                    if((!isEmpty(&s)&& isInitialized(&s)) || isFull(&s)){
                        printf(">> %d popped Successfully...\n", pop(&s));}
                    else{printf(">> STACK is EMPTY\n");}
                    break;

                case 4: //isFull case
                    isFull(&s)?printf(">> STACK is FULL\n"):printf(">> STACK isn't FULL\n");
                    break;

                case 5: //isEmpty case
                    isEmpty(&s)?printf(">> STACK is EMPTY\n"):printf(">> STACK isn't EMPTY\n");
                    break;

                case 6://display case
                    if((!isEmpty(&s) && isInitialized(&s)) || isFull(&s) ){
                        dispStack(&s,&userDispStack);}
                    else {printf(">> STACK is EMPTY\n");}
                    break;

                case 7:// clear case
                    clearStack(&s);
                    printf(">> STACK Cleared Successfully...\n");
                break;

                default:
                    if(c!=0 && c>7)
                        printf(">> WRONG CHOICE\n");}



                if(c!=0){
                    printf(">> STACK Size: %d\n",MAX_STACK);
                    if(!isEmpty(&s)){
                    printf(">> Top position at: %d index\n",getTopPos(&s));
                    printf(">> Free Space: %d Blocks\n",getFreeSpace(&s));}}
                else{printf(">> THANKS, ending..\n");}
                printf("----------------------------------------------------\n");





    }}while(c!=0);

}

