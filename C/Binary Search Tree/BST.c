#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "queueList.h"
#include "BST.h"

void userDispTree(TDT val){
    printf(" %d /",val);
}

int main()
{
    BST t;
    BST *p = &t;
    initTree(p);
    insertItem(p,5);
    insertItem(p,9);
    insertItem(p,10);
    insertItem(p,7);
    insertItem(p,8);
    insertItem(p,6);
    insertItem(p,3);
    insertItem(p,4);
    insertItem(p,1);
    insertItem(p,2);
    insertItem(p,12);
    insertItem(p,11);
    insertItem(p,13);


    printf("\nTree is: \n\n");
    dispTree_IN_ORDER(p,&userDispTree);
    printf("\n\n");
}
