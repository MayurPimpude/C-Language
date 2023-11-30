#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int top=-1,stack[MAX];
void push()
{int d;
if (top==MAX-1)
{
    printf("\n STACK OVERFLOW!! \n");
    return;
}
else
{
    printf("\nEnter ELEMENT:");
scanf("%d",&d);
++top;
stack[top]=d;
printf("\nelement pushed sucessfully\n");
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
    printf("\nPOPPED ELEMENT: %d",stack[top]);
    --top;

}
}
void show()
{int i;
if(top==-1)
    {
        printf("\nNO ELEMENTS IN STACK!!\n");
    }
    else
    {
        printf("\nElements present in the stack:\n");
        for(i=top;i>=0;--i)
            {
            printf(" %d\n",stack[i]);
            }
    }
}
int main()
{
    int choice;
    do{
    printf("\n");
    printf("\n1. PUSH");
    printf("\n2. POP");
    printf("\n3. SHOW");
    printf("\n4. EXIT");
    printf("\n\nEnter choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        show();
        break;
    case 4:
        break;
    default:
        printf("\nInvalid choice enter between 1 to 4");

    }
    } while(choice!=4);
    return 0;
}
