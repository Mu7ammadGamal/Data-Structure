#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef char SDT; // SDT --> Stack Data Type
#include "stackList.h"
void userDispStack(SDT);
int isParent(char,char);
int isBalance(char[]);
void initStack(Stack*);

main(){
char exp[10];
printf("Enter an expression: ");
scanf("%s",exp);
isBalance(exp)?printf(">> BALANCED"):printf(">> NOT BALANCED");

}









//-------------------------------------------------------------------------------
void userDispStack(SDT val){
    printf("         %c        \n",val);
}

int isParent(char start,char end){
    return (start=='(' && end==')')||(start=='[' && end==']')||(start=='{' && end=='}');
}

int isBalance(char exp[])
{
    Stack s;
initStack(&s);
    for(int i=0;i<strlen(exp);++i)
        {

            if(exp[i]=='[' || exp[i]=='{' ||exp[i]=='('){push(&s,exp[i]);}

            else if(exp[i]==']' || exp[i]=='}' ||exp[i]==')')

            {
                if(isEmpty(&s) || !isParent(getTop(&s),exp[i])){return 0;}
                else{pop(&s);}
            }


        }

return isEmpty(&s);
}
