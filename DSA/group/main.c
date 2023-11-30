#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();

struct node
{
int val;
struct node *next;
};
struct node *head;

int n,a[];

void main ()
{
    int choice=0;

    while(choice != 4)
    {
        printf("\n\n****MAIN MENU****\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                //free(ptr);
                printf("Exiting....");
                break;
            }
            default:
            {
                printf("Please Enter valid choice !!");
            }
    };
}
}


void push ()
{
    struct node *ptr2;
    char ch;
    int val,i;
    printf("\nEnter number of groups you want to make : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nGroup %d ",i+1);
    do{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    if(ptr == NULL)
    {
        printf("\nnot able to push the element");
    }
    else
    {
        printf("\nEnter the value : ");
        scanf("%d",&val);
        if(head==NULL)
        {
            ptr->val = val;
            ptr -> next = NULL;
            head=ptr;
        }
        else
        {
            ptr->val = val;
            ptr->next = head;
            head=ptr;

        }
    }

        printf("\nWant more people (Y/N) : ");
        scanf("%c",&ch);
        scanf("%c",&ch);

    }while(ch=='Y'|| ch=='y');
        printf("\nItem pushed Successfully !\n");

        a[i] = head;
    }

    printf("\nPrinting groups\n");
    for(i=0;i<n;i++)
    {
        printf("\nGroup %d ",i+1);
        ptr2 = a[i];
        while(ptr2!=NULL)
        {
            printf("\n%d",ptr2->val);
            ptr2 = ptr2->next;
        }
    }
}

void pop()
{
    int item,i;
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nUnderflow !!");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            ptr=a[i];
        }
        printf("\nElement -> %d popped Successfully !!",ptr->val);
        item = ptr->val;
      //  ptr = head;
        ptr = ptr->next;
        free(ptr);
    }
}


void display()
{
    int i,n;
    struct node *ptr;
   /* ptr=head;
    if(ptr == NULL)
    {
        printf("\nStack is empty !!\n");
    }
    else
    {
        printf("\nStack Linked List elements :\n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->val);
            ptr = ptr->next;
        }
    }*/
    /*for(i=0;i<=n;i++)
    {
        printf("\ngroup %d ",i+1);
        printf("\n-> %d ",a[i]);
    }*/
}
