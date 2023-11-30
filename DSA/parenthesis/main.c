#include <stdio.h>
#include <stdlib.h>
#define MAX 7
int top=-1,stack[MAX];

void push(char d)
{
if (top==MAX-1)
{
    printf("\n STACK OVERFLOW!! \n");
    return;
}
else
{
++top;
stack[top]=d;
printf("\nelement pushed successfully\n");
}
}

void pop()
{
if (top==-1)
{
    printf("\n STACK UNDERFLOW!!\n");
}
else
{
    --top;
}
}



int main()
{
    int i,choice;
    char exp[MAX];
    do{
    printf("\n****MENU****\n");
    printf("\n1.Check Parenthesis");
    printf("\n2.EXIT\n");

    printf("\nEnter choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
    printf("\nEnter Expression: ");
    scanf("%s",&exp);
     int i;
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='{' || exp[i]=='('|| exp[i]=='[' )
            {
                push(exp[i]);
                continue;
            }
        else if(exp[i]=='}'||exp[i]==']'||exp[i]==')')
        {

              if(exp[i]==']')
               {
            if( stack[top]=='[' )
                {
        {
            pop();

        }}
        else
        {
            printf("\nUnbalanced Expression !\n");
            break;
        }
              }

              if(exp[i]=='}')
               {
            if(stack[top]=='{')
                {
        {
            pop();

        }}
        else
        {
            printf("\nUnbalanced Expression !\n");
            break;
        }
              }


              if(exp[i]==')')
               {
            if( stack[top]=='(')
                {
        {
            pop();

        }}
        else
        {
            printf("\nUnbalanced Expression !\n");
            break;
        }
              }
            }
    }
        if(top == -1)
        {
            printf("\nBalanced Expression !\n");
        }

    break;

        case 2:
            break;

        default:
            printf("\nEnter choice between 1 to 2 only\n");
    }
    }while(choice!=2);
    return 0;
}
