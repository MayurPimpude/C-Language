#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>

struct node
{
    char name[10];
    int data;
    struct node *rlink;
    struct node *llink;
};

struct gnode
{
    char naam[10];
    int val;
    struct gnode *next;
};

struct gnode *head;

int n,a[];
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
        printf("\nContact list already present !\n");
        return;
    }

    do{
        I=makenode();
      printf("\nEnter name : ");
      scanf("%s",I->name);

      printf("Enter Contact Number : ");
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
             printf("\nWant to add a Contact (Y/N) : ");
            ch=getche();

    }while(ch=='y' || ch=='Y');
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
  printf("\nNumber of Contacts are : %d \n",count);
  return count;
}

void delete()
{
    int choice;
    if(start==NULL)
    {
        printf("\n Create contact List First ! \n");
        return;
    }
    do{
        printf("\n++++Delete++++\n");
        printf("\n1. Delete All");
        printf("\n2. Delete By Name");
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
    printf("\nALL CONTACTS DELETED !\n");
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
  struct node *pp;
  char nam[10];
  if(start == NULL)
  {
      printf("\nContact List Is Empty\n");
      return;
  }

  printf("\nEnter Name To Delete Contact : ");
  scanf("%s",nam);

 ptrAtValue = start;
  while(ptrAtValue!=NULL && (val==0))
    {
        val=strcmp(ptrAtValue->name,nam);
        if(val!=0)
        {
            ptrAtValue = ptrAtValue->rlink;
        }


        if(pp == NULL)
        {
            printf("\nNOT FOUND \n");
            return;
        }
    }

    if(ptrAtValue->rlink==NULL)
    {
           // start->llink=NULL;
           ptrAtValue->llink->rlink=NULL;
            display();
            printf("\n1Node %s Deleted Successfully !!\n",nam);
            free(ptrAtValue);
    }
    else if(ptrAtValue == start)
    {
        start = start->rlink;
        start->llink=NULL;
        free(ptrAtValue);
        display();
    }
    else
    {
        ptrAtValue->llink->rlink = ptrAtValue -> rlink;
        ptrAtValue->rlink->llink = ptrAtValue -> llink;
        ptrAtValue -> rlink = NULL;
        ptrAtValue -> llink = NULL;
        free(ptrAtValue);
        display();
        printf("\nNode %s Deleted Successfully !!\n",nam);
    }
}

void search()
{
    int item,i=0,flag;
    char contact[10];
    ptr = start;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter Name to search : ");
        scanf("%s",contact);
        while (ptr!=NULL)
        {
            item=strcmp(ptr->name,contact);
            if(item == 0)
            {
                printf("\nElement found at location %d ",i+1);
                printf("\nNumber : %d ",ptr->data);
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

printf("\nContacts Present are : \n");
do
{
printf(" %s -> %d",I->name,I->data);
if(I->rlink != NULL)
     printf("\n");
   I=I->rlink;
}while(I!=NULL);
printf("\n");

 struct gnode *ptr2;
    int i;
    printf("\nPrinting groups : \n");
    for(i=0;i<n;i++)
    {
        printf("\nGroup %d \n",i+1);
        ptr2 = a[i];
        while(ptr2!=NULL)
        {
            printf("%s -> %d\n",ptr2->naam,ptr2->val);
            ptr2 = ptr2->next;
        }
    }
}

void insert()
{
    int ch;
    struct node *ptrBeforePos;
    struct node *I;
    if(start==NULL)
    {
        printf("\n Create List First ! \n");
        return;
    }

    I=makenode();

    printf("\nEnter Name : ");
    scanf("%s",I->name);

    printf("Enter Contact Number : ");
    scanf("%d",&I->data);

    ptrBeforePos = start;

    while(ptrBeforePos->rlink!=NULL)
    {
        ptrBeforePos = ptrBeforePos->rlink;
    }

    if(ptrBeforePos->rlink==NULL)
    {
        ptrBeforePos->rlink = I;
        I->llink = ptrBeforePos;
        I->rlink = NULL;
    }

     display();
}

void group()
{
    int choice;
    do{
    printf("\n****GROUP****\n");
    printf("\n1.Create Group");
    printf("\n2.Delete Group");
    printf("\n3.Print Group");
    printf("\n4.Back To Main Menu\n");
    printf("\nEnter choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        CreateGroup();
        break;

    case 2:
        DeleteGroup();
        break;

    case 3:
        PrintGroup();
        break;

    case 4:
        return main();

    default:
        printf("Invalid Choice");
    }
    }while(choice!=4);
}

void CreateGroup()
{
    char ch,na[10];
    int i,val;
    printf("\nEnter number of groups you want to make : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      head=NULL;
        printf("\nGroup %d ",i+1);
    do{
    struct gnode *ptr = (struct node*)malloc(sizeof(struct node));

    if(ptr == NULL)
    {
        printf("\nnot able to push the element");
    }
    else
    {
        printf("\nEnter Name : ");
        scanf("%s", ptr->naam);
        printf("Enter the Number : ");
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

}

void PrintGroup()
{
    struct gnode *ptr2;
    int i;
    printf("\nPrinting groups\n");
    for(i=0;i<n;i++)
    {
        printf("\nGroup %d \n",i+1);
        ptr2 = a[i];
        while(ptr2!=NULL)
        {
            printf("%s -> %d\n",ptr2->naam,ptr2->val);
            ptr2 = ptr2->next;
        }
    }
}

void DeleteGroup()
{
    int choice,i,no;
    printf("\n *DELETE GROUP* \n");
    printf("\n1.Delete Group");
    printf("\n2.Delete All Groups");
    printf("\nEnter Choice : ");
    scanf("%d",&choice);
    switch(choice)
    {

    case 1:
        printf("\nEnter Group number want to Delete : ");
        scanf("%d",&no);
        a[no-1] = NULL;
        break;

    case 2:
        for(i=0;i<n;i++)
        {
            a[i] = NULL;
        }
        printf("\nAll Groups Deleted Successfully !\n");
        break;
    }
}

void main()
{
    int choice;
    printf("\n-------------------------------------------------------------------");
    printf("\n\t\t\tCHATTER");
    printf("\n-------------------------------------------------------------------\n");
    do{
    printf("\n****MAIN MENU****\n");
    printf("\n1. Create Contact");
    printf("\n2. Insert ");
    printf("\n3. Delete");
    printf("\n4. Display");
    printf("\n5. Count");
    printf("\n6. Search");
    printf("\n7. Make Group");
    printf("\n8. Exit\n");
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
        group();
        break;

    case 8:
        free(start);
        free(end);
        printf("\n..END !!\n");
        break;

    default:
        printf("\nInvaild choice !!\n");
    }
   } while(choice!=8);
}
