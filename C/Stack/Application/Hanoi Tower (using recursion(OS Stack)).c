#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef char SDT; // SDT --> Stack Data Type
#include "stackList.h"


int moveDisks(int number,int start, int finish,int temp)
{
    static int steps=0;
    //Base Condition
    if (number==0)
        return;
    //Recursive Condition
    else
    {
        moveDisks(number-1,start,temp,finish);
        printf("\nStep: %d --> Move Disk no. %d\t --> \tfrom: %d\tto: %d\n",steps+1,number,start,finish);
        printf("-----------------------------------------------------");
        steps+=1;
        moveDisks(number-1,temp,finish,start);
    }

    return steps;
}

main(){
moveDisks(7,1, 3,2);





}
