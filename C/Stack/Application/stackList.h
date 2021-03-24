#ifndef STACKLIST_H_INCLUDED
#define STACKLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<string.h>


//Stack struct
typedef struct node {
    SDT val;
    struct node *next;
}stackNode;

typedef struct{
    stackNode *top;
    int size; //to save time complexity to constant instead of N times because of loop
    int stackIntialized; // to store if the stack initialized
}Stack;

//Stack Functions
void initStack(Stack *ps){
    ps->top = NULL;
    ps->size = 0;
    ps->stackIntialized =1;
}

SDT getTop(Stack *ps){
    return ps->top->val;
}

int getSize(Stack *ps){
    return ps->size;
}

void clearStack(Stack *ps){
    for(stackNode *temp=ps->top;ps->top!=NULL;temp=ps->top){
        ps->top=ps->top->next;
        free(temp);
    }
    ps->size=0; // was in for waste of time
}

int isEmpty(Stack *ps){
    return ps->top == NULL;
}

int isFull(Stack *ps){ //list has no specific size so isFall is false always --> return 0
    return 0;
}

int isInitialized(Stack *ps){ // =isTopInStack()
    if (ps->stackIntialized ==1)
        return 1;
    else
        return 0;
}

void push(Stack *ps,SDT val){
    stackNode *pn = (stackNode*)malloc(sizeof(stackNode)); //creating a node and point to it by *pn
    pn->next=ps->top;
    ps->top = pn;
    ps->top->val=val;
    ps->size++;
}

SDT pop(Stack *ps){
    stackNode *temp = ps->top;
    ps->top=temp->next;
    SDT popVal = temp->val;
    free(temp);
    ps->size--;
    return popVal;
}

void dispStack(Stack *ps,void (*pf)(SDT)){
        printf("\n\n-------STACK-------\n\n");
    for(stackNode *temp = ps->top;temp!=NULL;temp=temp->next){
        (*pf)(temp->val);
        printf("-------------------\n");
    }printf("\n\n\n");

}

#endif // STACKLIST_H_INCLUDED
