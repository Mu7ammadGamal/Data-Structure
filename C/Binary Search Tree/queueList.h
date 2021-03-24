#ifndef QUEUELIST_H_INCLUDED
#define QUEUELIST_H_INCLUDED

typedef int QDT;
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//Queue struct
typedef struct node {
    QDT val;
    struct queue *next;
}queueNode;

typedef struct{
    queueNode *front;
    queueNode *rear;
    int size; //to save time complexity to constant instead of N times because of loop
    int queueIntialized; // to store if the queue initialized
}Queue;

//Queue Functions
void initQueue(Queue *pq){
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
    pq->queueIntialized = 1;
}

QDT getFront(Queue *pq){
    return pq->front->val;
}

QDT getRear(Queue *pq){
    return pq->rear->val;
}

int getSize(Queue *pq){
    return pq->size;
}

void clearQueue(Queue *pq){
    for(pq->rear=pq->front;pq->front!=NULL;pq->rear=pq->front)
        {
            pq->front=pq->front->next;
            free(pq->rear);
        }
    pq->size=0;
}

int isEmpty(Queue *pq){
    return pq->size == 0; //return !pq->size ;
}

int isFull(Queue *pq){ //list has no specific size so isFall is false always --> return 0
    return 0;
}

int isInitialized(Queue *pq){
    if (pq->queueIntialized ==1)
        return 1;
    else
        return 0;
}

void enQueue(Queue *pq,QDT val){
    queueNode *pn = (queueNode*)malloc(sizeof(queueNode)); //creating a node and point to it by *pn
    if((pq->front == NULL && pq->rear == NULL) || pq->size==0) // check if the first node will append
    {
        pq->front=pn;
        pq->rear=pn;
    }
     else // if will append on a existing node
     {
        pq->rear->next = pn;
        pq->rear = pn;
        pq->rear->next = NULL;
     }

     pq->rear->val = val;
     pq->size++;

}

QDT deQueue(Queue *pq){
    queueNode *temp = pq->front;
    QDT popVal = temp->val;
    if((pq->front->next == NULL && pq->rear->next == NULL) || pq->size==1)
    {
        pq->rear = NULL;
    }

    pq->front = pq->front->next;
    free(temp);
    pq->size--;
    return popVal;
}

void dispQueue(Queue *pq,void (*pf)(QDT)){
    printf("\n\nQueue: /");
    for(queueNode *temp = pq->front;temp!=NULL;temp=temp->next){
        (*pf)(temp->val);
    }printf("\n\n\n");

}





#endif // QUEUELIST_H_INCLUDED
