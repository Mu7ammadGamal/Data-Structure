/** it is a simple evalution of postfix expression **/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
typedef double SDT; // SDT --> Stack Data Type
#include "stackList.h"

void userDispStack(SDT val){
    printf("         %.2lf        \n",val);
}

double calc(char sign,double top1,double top2){

    if(sign=='^')
        return pow(top2,top1);
    if(sign=='*')
        return top2*top1;
    if(sign=='/')
        return top2/top1;
    if(sign=='+')
        return top2+top1;
    if(sign=='-')
        return top2-top1;
}

double evalPostfix(char postfix[]){
    Stack s;
    initStack(&s);
    char c;
    double result=0,top1,top2;

    for(int i =0;(c = postfix[i])!='\0';i++){

        if(isspace(c))
        {
            continue;
        }

        if(isalnum(c)) // A:Z or 0:9
        {
          push(&s,c-48);
        }

        else if(!isalnum(c)) // +, -, *, /, $
        {
            top1=pop(&s);
            top2=pop(&s);
            result=calc(c,top1,top2);
            push(&s,result);
        }



    }
    return result;



}





void main(){
    char exp[]="2 3 7 * + 6 3 / 2 4 ^ * - 9 3 / + 1 -"; //--> 2+3*7-6/3*2^4+9/3-1
    //printf("Enter the expression: ");
    //scanf("%s",&exp);
    printf("Evaluation: %0.2lf",evalPostfix(exp));



}
