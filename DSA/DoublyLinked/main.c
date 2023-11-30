#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *rlink;
    struct node *llink;
};

struct node *start = NULL,*ptr=NULL;
struct node *end;

int makenode()
{
    return((struct node*)malloc(sizeof(struct node)));
}

void create()
{
    struct node *I;
    int value;
    char ch;
    if(start!=NULL)
    {
        printf("\nLinkedlist already present !\n");
        return;
    }

    do{
        I=makenode();

      printf("\nEnter Data : ");
      scanf("%d",&value);

           I->data=value;
           I->rlink=NULL;
           I->llink=end;
            if(start == NULL)
            {
                start =I;
            }
            else
            {
                end->rlink=I;
            }
          end = I;
             printf("\nWant new node (Y/N) : ");
            ch=getche();

    }while(ch=='y' || ch=='Y');
}

void insertpos()
{
    int pos,i,nodeCount;
    struct node *ptrBeforePos;
    struct node *I;
    if(start == NULL)
    {
        printf("\nCreate Linked List First !!\n");
        return;
    }
    I=makenode();
    nodeCount=count();
    display();
    printf("\nEnter Position To Add Node : ");
    scanf("%d",&pos);
    if(pos<1 || pos>nodeCount+1)
    {
        printf("\nInvalid Position Entered !!\n");
        return;
    }
    printf("\nEnter Data To Insert : ");
    scanf("%d",&I->data);

    if(pos == 1)
    {
        I->rlink = start;
        start->llink = I;
        I->llink = NULL;
        start=I;
        printf("\nNode Inserted Successfully !");
        return;
    }

    ptrBeforePos = start;
    for(i=0 ; i<pos-2 ; i++)
    {
        ptrBeforePos = ptrBeforePos->rlink;
    }
    I->rlink = ptrBeforePos->rlink;
    I->llink = ptrBeforePos;
    ptrBeforePos->rlink = I;
     printf("\nNode Inserted Successfully !");

    if(I->rlink!=NULL)
        I->rlink->llink=I;
     display();
}

void insertVal()
{
    int val;
    struct node *ptrAtValue,*ptrBeforeVal;
     struct node *I;
    if(start==NULL)
    {
        printf("\nLIST EMPTY !\n");
        return;
    }
    printf("\nEnter Data Before Which New Node To Insert : ");
    scanf("%d",&val);

    ptrAtValue = start;
    while( (ptrAtValue->data != val) && (ptrAtValue!=NULL) )
    {
        ptrAtValue = ptrAtValue->rlink;
        if(ptrAtValue == NULL)
        {
            printf("\nNOT FOUND \n");
            return;
        }
    }
    I=makenode();

    if(ptrAtValue == NULL)
    {
        printf("\nReqiured Node Not Found ! \n");
        return;
    }

    printf("\nEnter Data to Insert : ");
    scanf("%d",&I->data);

    I->llink = ptrAtValue->llink;
    I->rlink=ptrAtValue;

    if(ptrAtValue == start)
    {
        start = I;
    }
    else
    {
        I->llink->rlink=I;
    }
    ptrAtValue->llink = I;
       printf("\nNode Inserted Successfully !\n");
       display();
}

int count()
{
  int count=0;
  struct node *pointer;
  if(start==NULL)
  {
      printf("\nLIST EMPTY !\n");
      return;
  }

  pointer = start;
  while(pointer!=NULL)
  {
      pointer = pointer->rlink;
      count++;
  }
  printf("\nNumber of node's are : %d \n",count);
  return count;
}

void delete()
{
    int choice;
    if(start==NULL)
    {
        printf("\n Create List First ! \n");
        return;
    }
    do{
        printf("\n++++Delete++++\n");
        printf("\n1. Delete All");
        printf("\n2. Delete By Value");
        printf("\n3. Back To Main Menu\n");
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            deleteAll();
            break;

        case 2:
            deleteByVal();
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
    start = NULL;
    free(start);
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

void deleteByVal()
{
  int val;
  struct node *ptrAtValue;
  struct node *te;
  if(start == NULL)
  {
      printf("\nLinked List Is Empty\n");
      return;
  }

  printf("\nEnter The Data Of Node To Be Deleted : ");
  scanf("%d",&val);

  ptrAtValue = start;
  while( (ptrAtValue->data != val) && (ptrAtValue!=NULL) )
    {
        ptrAtValue = ptrAtValue->rlink;
        if(ptrAtValue == NULL)
        {
            printf("\nNOT FOUND \n");
            return;
        }
    }
    if(ptrAtValue == start)
    {
        start = start->rlink;
        if(start!=NULL)
        {
            start->llink=NULL;
            display();
            printf("\nNode %d Deleted Successfully !!\n",val);
        }
    }
    else if(ptrAtValue->rlink==NULL)
    {
        ptrAtValue->llink->rlink=NULL;
        display();
        printf("\nNode %d Deleted Successfully !!\n",val);
    }
    else
    {
        ptrAtValue->llink->rlink = ptrAtValue -> rlink;
        ptrAtValue->rlink->llink = ptrAtValue -> llink;
        ptrAtValue -> rlink = NULL;
        ptrAtValue -> llink = NULL;
        display();
        printf("\nNode %d Deleted Successfully !!\n",val);
    }
}

void search()
{
    struct node *ptr;
    int item,i=0,flag;
    ptr = start;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter Element to search : ");
        scanf("%d",&item);
        while (ptr!=NULL)
        {
            if(ptr->data == item)
            {
                printf("\nElement found at location %d \n",i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> rlink;
        }
        if(flag==1)
        {
            printf("\nElement not found\n");
        }
    }

}

void display()
{
    struct node *I;
I=start;
if(start == NULL)
{
 printf("\nLinked List Not Present !\n");
 return;
}

printf("\nNode's Present are : \n");
do
{
printf(" %d ",I->data);
if(I->rlink != NULL)
     printf("<->");
   I=I->rlink;
}while(I!=NULL);
printf("\n");
}

void insert()
{
    int ch;
    if(start==NULL)
    {
        printf("\n Create List First ! \n");
        return;
    }
    do{
    printf("\n++++INSERT++++\n");
    printf("\n1. Insert By Position");
    printf("\n2. Insert By Before Value");
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
    printf("\n6. Search");
    printf("\n7. Exit\n");
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
        search();
        break;

    case 7:
        free(start);
        free(end);
        printf("\n..END !!\n");
        break;

    default:
        printf("\nInvaild choice !!\n");
    }
   } while(choice!=7);
}
