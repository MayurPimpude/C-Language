#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 5
int add_item;
void insert();
void delete();
void display();
void check();
int queue_array[MAX];
int rear = - 1;
int front = - 1;
void main()
{
    int choice;
    do{
    {   printf("\n");
         printf("****MENU**** \n\n");
        printf("1.Enqueue \n");
        printf("2.Dequeue \n");
        printf("3.Display all elements:\n");
        printf("4.Quit \n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            printf("Insert the element in queue : ");
            scanf("%d", &add_item);
            insert(add_item);
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        }
    } }while(choice=4);
}

void insert(int add_item)
{

    if (rear == MAX - 1)
    {
        printf("\tQueue Overflow !! \n");
        return;
    }

   if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        queue_array[rear] = add_item;
        return;
    }
    else
        check(add_item);
        rear++;
}


void check(int add_item)
{
    int i,j;

    for (i = 0; i <= rear; i++)
    {
        if (add_item >=queue_array[i])
        {
            for (j = rear + 1; j > i; j--)
            {
               queue_array[j] =queue_array[j - 1];
            }
           queue_array[i] = add_item;
            return;
        }
    }
   queue_array[i] = add_item;
}


void delete(int add_item)
{
    int i;
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
         for (i = 0; i <= rear; i++)
    {
        if (add_item == queue_array[i])
        {
            for (; i < rear; i++)
            {
                queue_array[i] = queue_array[i + 1];
            }

        queue_array[i] = -99;
        rear--;

        if (rear == -1)
            front = -1;
        }
    }

        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }

}

void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
         for (; front <= rear; front++)
    {
        printf(" %d ",queue_array[front]);
    }

    front = 0;
    }
}
