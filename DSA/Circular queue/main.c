
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 4

void insert();
void  dequeue();
void display();
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
            insert();
            break;
            case 2:
            dequeue();
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

void insert()
{
    int add_item;
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
         printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        queue_array[rear] = add_item;
        printf("\n Element Inserted successfully !! ");
    }
    else if (((rear + 1)%MAX) == front)
    {
      printf("Queue Overflow \n");
    }
    else
    {
        printf("Insert the element in queue : ");
        scanf("%d", &add_item);
        rear = ((rear + 1)%MAX);
        queue_array[rear] = add_item;
         printf("\n Element Inserted successfully !! ");
    }
}

void  dequeue()
{
    if (front== -1 && rear == - 1 )
    {
        printf("Queue Underflow \n");
        return ;
    }
    else if(front == rear)
    {
         printf("Element deleted from queue is : %d\n", queue_array[front]);
         front= rear = - 1 ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = ((front + 1)%MAX);
    }
}

void display()
{
    if (front == 1 && rear == - 1)
    {
     printf("Queue is empty \n");
    }
    int i = front;
      printf("\nCircular Queue Elements are : \n");
      if(front <= rear)
        {
	 while(i <= rear)
	    printf("%d\t", queue_array[i++]);
      }
      else
        {
	 while(i <= MAX - 1)
	    printf("%d\t",  queue_array[i++]);
	 i = 0;
	 while(i <= rear)
	    printf("%d\t", queue_array[i++]);
        }
}

