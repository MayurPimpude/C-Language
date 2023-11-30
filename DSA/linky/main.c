#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *link;
};

struct node *current = NULL,*I=NULL;

int makenode()
{
    return((struct node*)malloc(sizeof(struct node)));
}

void create()
{
    struct node *newnode;
    int value;
    char ch;
    if(I!=NULL)
    {
        printf("\nLinkedlist already present !\n");
        return;
    }

    do{

         newnode = (struct node*)malloc(sizeof(struct node));
      printf("\nEnter Data : ");
      scanf("%d",&value);

            newnode->data = value;
            newnode->link = NULL;
            if(I==NULL)
            {
                I=current=newnode;
            }
            else
            {
            current->link = newnode;
            current = current->link;
            }
             printf("\nWant new node (Y/N) : ");
            ch=getche();

    }while(ch=='y' || ch=='Y');
}

void insertpos()
{
    int pos,i;
    struct node *ptrBeforePos;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    count();
    display();
    printf("\nEnter Position To Add Node : ");
    scanf("%d",&pos);

    printf("\nEnter Data To Insert : ");
    scanf("%d",&newnode->data);

    if(pos == 1)
    {
        newnode->link = I;
        I = newnode;
        printf("\nNode Inserted Successfully !");
        return;
    }

    ptrBeforePos = I;
    for(i=0 ; i<pos-2 ; i++)
    {
        ptrBeforePos = ptrBeforePos->link;
    }
    newnode->link = ptrBeforePos->link;
    ptrBeforePos->link = newnode;
     printf("\nNode Inserted Successfully !");

     display();
}

void insertVal()
{
    int val;
    struct node *ptrAtValue,*ptrBeforeVal;
     struct node *newnode;
    if(I==NULL)
    {
        printf("\nLIST EMPTY !\n");
        return;
    }
    printf("\nEnter data After which new node to insert : ");
    scanf("%d",&val);

    ptrAtValue = I;
    while( (ptrAtValue->data != val) && (ptrAtValue->link != I) )
    {
        ptrAtValue = ptrAtValue->link;
        if(ptrAtValue == NULL)
        {
            printf("\nNOT FOUND \n");
            return;
        }
    }

    if(ptrAtValue == NULL)
    {
        printf("\nReqiured Node Not Found ! \n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter Data to Insert : ");
    scanf("%d",&newnode->data);

    newnode->link = ptrAtValue->link;
    ptrAtValue->link = newnode;

       printf("\nNode Inserted Successfully !\n");
       display();
}
int count()
{
  int count=0;
  struct node *pointer;
  if(I==NULL)
  {
      printf("\nLIST EMPTY !\n");
      return;
  }

  pointer = I;
  while(pointer!=NULL)
  {
      pointer = pointer->link;
      count++;
  }
  printf("\nNumber of node's are : %d \n",count);
  return count;
}

void delete()
{
    int choice;
    if(I==NULL)
    {
        printf("\n Create List First ! \n");
        return;
    }
    do{
        printf("\n++++Delete++++\n");
        printf("\n1. Delete All");
        printf("\n2. Delete By Position");
        printf("\n3. Back To Main Menu\n");
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            deleteAll();
           // deleteByValue();
            break;

        case 2:
            deleteByPos();
            break;

        case 3:
            break;

        default:
            printf("\nInvalid choice ! \n");
        }
    }while(choice!=3);

}

void deleteAll()
{
    char ch;
    printf("\nARE YOU SURE TO DELETE ALL (Y/N) : ");
    ch=getche();
    switch(ch)
    {
    case 'Y':
    case 'y':
        {
    current = NULL;
    I = NULL;
    free(current);
    free(I);
    printf("\nALL NODES DELETED !\n");
    break;
        }

    case 'N':
    case 'n':
        {
        printf("\nDelete All Terminated !");
        break ;
        }

    default:
        printf("\nInvalid Choice !");
    }
}

void deleteByPos()
{
   struct node *point=I,*ptr1;
   int loc,i=0,nodecount;
   nodecount = count();
    int last = nodecount;
   printf("\nEnter the location of node to delete : ");
   scanf("%d",&loc);

   if(loc<1 || loc>nodecount)
   {
       printf("\nInvalid Position !\n");
       return;
   }
   current = I;
   if(loc == 1)
   {
        point = I;
        I = I->link;
        point->link=NULL;
        free(point);
        printf("\nNode on position deleted Successfully !\n");
        display();
        return I;
   }

   else if (loc == last)
   {
        point = I;
        while(point->link != NULL)
        {
            ptr1 = point;
            point = point ->link;
        }
        ptr1->link = NULL;
        free(point);
        printf("\nDeleted Node from the last Successfully\n");
        display();
   }

   else
    {
        point = I;
    while(i == loc )
   {
       point = point->link;
       i++;
    }
    point = current->link;
    current->link = point->link;
    point->link = NULL;
    free(point);
    printf("\nNode on position deleted Successfully !\n");
    display();
    return current;
   }

}

void display()
{
current =I;
if(current == NULL)
{
 printf("\nLinked List Not Present !\n");
 return;
}

printf("\nNode's Present are : \n");
do
{
printf(" %d ",current->data);
if(current->link != NULL)
     printf("->");
   current=current->link;
}while(current!=NULL);
printf("\n");
}

void insert()
{
    int ch;
    if(I==NULL)
    {
        printf("\n Create List First ! \n");
        return;
    }
    do{
    printf("\n++++INSERT++++\n");
    printf("\n1. Insert By Position");
    printf("\n2. Insert By After Value");
    printf("\n3. Back To Main Menu\n");

    printf("\nEnter Choice : ");
    scanf("%d",&ch);
	switch(ch)
	{

	case 1:
    insertpos();
    break;

    case 2:
	insertVal();
	break;

	case 3:
	break;

	default:
	printf("\nInvalid Choice !\n");
}
    }while(ch!=3);
}

void main()
{
    int choice;
    do{
    printf("\n****MAIN MENU****\n");
    printf("\n1. Create Linklist");
    printf("\n2. Insert ");
    printf("\n3. Delete");
    printf("\n4. Display");
    printf("\n5. Count");
    printf("\n6. Exit\n");
    printf("\nEnter Choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1 :
      create();
      break;

    case 2 :
        insert();
        break;

    case 3:
        delete();
        break;

    case 4:
        display();
        break;

    case 5:
        count();
        break;

    case 6:
        free(current);
        free(I);
        printf("\n..END !!\n");
        break;

    default:
        printf("\nInvaild choice !!\n");
    }
   } while(choice!=6);
}
