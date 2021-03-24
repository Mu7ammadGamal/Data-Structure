#ifndef QUEUEARRAY_H_INCLUDED
#define QUEUEARRAY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//Queue queue
typedef struct queue{
    QDT items[MAX_QUEUE];
    int front;
    int rear;
    int size;
    int queueIntialized;
}Queue;

//Queue Functions
void initQueue(Queue *pq){
    pq->front=0;
    pq->rear=MAX_QUEUE-1;
    pq->size=0;
    pq->queueIntialized=1;
}

QDT getFront(Queue *pq){
    return pq->items[pq->front];
}

int getFrontPos(Queue *pq){
    return pq->front;
}

QDT getRear(Queue *pq){
    return pq->items[pq->rear];
}

int getRearPos(Queue *pq){
    return pq->rear;
}

int getFreeSpace(Queue *pq){
    return MAX_QUEUE-pq->size;
}

void clearQueue(Queue *pq){
    pq->front=0;
    pq->rear=MAX_QUEUE-1;
    pq->size=0;
}

int isEmpty(Queue *pq){
    return pq->size == 0;
}

int isFull(Queue *pq){
    return pq->size == MAX_QUEUE;
}

int isInitialized(Queue *pq){
    if (pq->queueIntialized ==1)
        return 1;
    else
        return 0;
}

int enQueue(Queue *pq,QDT val){
    pq->rear=(pq->rear+1)% MAX_QUEUE;
    pq->items[pq->rear]=val;
    pq->size++;
    return pq->rear; // to return the new rear pos ready to enQueue again
}

QDT deQueue(Queue *pq){
    QDT val=pq->items[pq->front];
    pq->front=(pq->front+1)% MAX_QUEUE;
    pq->size--;
    return val;
}

void dispQueue(Queue *pq,void (*pf)(QDT)){
    printf("\n\nQueue: /");
    for(int i=pq->front,s=0;s<pq->size;s++){ //s to stop the loop at the size , i to start from the front
        (*pf)(pq->items[i]);
        i=(i+1)%MAX_QUEUE;
    }printf("\n\n\n");

}



#endif // QUEUEARRAY_H_INCLUDED
