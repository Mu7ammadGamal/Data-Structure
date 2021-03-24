#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef char SDT; // SDT --> Stack Data Type
#include "stackList.h"
void userDispStack(SDT val){
    printf("         %c        \n",val);
}

int isPrecedence(char enter,char top){
    if(enter=='^')
        return 1;
    if((enter == '*' || enter == '/'))
        return (top!='^'&& top!= '/' && top!= '*');
    if((enter == '+' || enter== '-'))
        return (top!='^'&& top!= '/' && top!= '*' && top!= '+' && top!= '-' );

    return 0;
}

void infix_to_postfix(char infix[]){
    Stack s;
    initStack(&s);
    char c;
    char temp[strlen(infix)];
    int j=0;

    for(int i =0;infix[i]!='\0';i++){
        c = infix[i];
        if(isalnum(c)) // A:Z or 0:9
        {
          temp[j++]=c;
        }


        else if(!isalnum(c)) // +, -, *, /, $
        {
            if(isEmpty(&s))
            {
                push(&s,c);
            }
            else
            {
                while(!isEmpty(&s) && !isPrecedence(c,getTop(&s)))// full and less than top
                {
                    temp[j++]=(char)pop(&s);
                }
                push(&s,c);
            }
        }
        else
            continue;
            dispStack(&s,userDispStack);
    }

    while(!isEmpty(&s))
    {
       temp[j++]=(char)pop(&s);
       temp[j]='\0';
    }
    strcpy(infix,temp);
    //for(int i=0;temp[i]!='\0';i++){infix[i]=temp[i];}

    //printf("%s",infix);



}





void main(){
    char exp[20]="2+3*7-6/3";
    //printf("Enter the expression: ");
    //scanf("%s",&exp);
    infix_to_postfix(&exp);
    printf("%s",exp);


}
