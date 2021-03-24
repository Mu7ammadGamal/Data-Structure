#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 100

//Stack struct
typedef struct{
    SDT items[MAX_STACK];
    int top;
    int stackIntialized;
}Stack;

//Stack Functions
void initStack(Stack *ps){
    ps->top=0;
    ps->stackIntialized=1;
}

int getTop(Stack *ps){
    return ps->items[ps->top];
}

int getTopPos(Stack *ps){
    return ps->top;
}

int getFreeSpace(Stack *ps){
    return MAX_STACK-ps->top;
}

void clearStack(Stack *ps){
    ps->top=0;
}

int isEmpty(Stack *ps){
    return ps->top == 0;
}

int isFull(Stack *ps){
    return ps->top == MAX_STACK;
}

int isTopInStack(Stack *ps){
    return ps->top<MAX_STACK && ps->top >= 0; // true: if top in the stack
}

int isInitialized(Stack *ps){ // =isTopInStack()
    if (ps->stackIntialized ==1)
        return 1;
    else
        return 0;
}

int push(Stack *ps,SDT val){
    ps->items[ps->top++]=val;
    return ps->top; // to return the new top ready to push again
}

SDT pop(Stack *ps){
    return ps->items[--ps->top];
}

void dispStack(Stack *ps,void (*pf)(SDT)){
        printf("\n\n-------STACK-------\n\n");
    for(int i = ps->top-1;i>=0;i--){
        (*pf)(ps->items[i]);
        printf("-------------------\n");
    }printf("\n\n\n");

}
