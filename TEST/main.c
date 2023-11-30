
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#define MAX_SIZE 100
struct student
{
    char name[20],clas[20];
    int mmarks,pmarks,cmarks,dmarks,roll;

}s[MAX_SIZE];
void main()
{
    int i,n,a,c,ch,rol,login,lock;
char pass[]="echo",pas[20],u[]="teacher",user[20];
FILE *fp;
do{
printf("\n----------------------------------------------------------");
printf("\n\t\t VESIT EXAM RESULT PORTAL ");
printf("\n----------------------------------------------------------");
printf("\n1 TEACHER LOGIN");
printf("\n2 STUDENT LOGIN");
printf("\n3 EXIT");
printf("\n\nEnter Login:");
scanf("%d",&c);
switch(c)
{
case 1:
    printf("\n----------------------------------------------------------");
    printf("\n\t\t TEACHERS LOGIN");
    printf("\n----------------------------------------------------------");
    printf("\nENTER USERNAME:");//username is teacher
    scanf("%s",user);
    printf("\nENTER PASSWORD:");//password is echo//
    scanf("%s",pas);
    login=strcmp(pass,pas);
    lock=strcmp(u,user);
    if(login==0&&lock==0)
    {
    printf("\n 1. RESULT FILE");
    printf("\n 2. SEARCH");
    printf("\n 3. EXIT");
    printf("\n\n Enter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:

     printf("\n Enter number of students:");
scanf("%d",&n);
printf("\n --------------------------------------------------");
    printf("\n \t\t Enter IA 1 Marks Of Students ");
    printf("\n --------------------------------------------------");
    fp=fopen("result.txt","w");
    for(i=0;i<n;i++)
    {
        printf("\n ENTER CLASS:");
    scanf("%s",s[i].clas);
    fprintf(fp,"class=%s\n",s[i].clas);
        printf("\n ENTER NAME:");
         fflush(stdin);
        scanf("%[^\n]s",s[i].name);
        fprintf(fp,"name=%s\n",s[i].name);
        printf("\n ENTER ROLL NO.:");
        scanf("%d",&s[i].roll);
        fprintf(fp,"roll no=%d\n",s[i].roll);
        printf("\n ENTER MARKS OF MATHS:");
        scanf("%d",&s[i].mmarks);
        fprintf(fp,"maths=%d\n",s[i].mmarks);
        printf("\n ENTER MARKS OF PHYSICS'S:");
        scanf("%d",&s[i].pmarks);
        fprintf(fp,"physics=%d\n",s[i].pmarks);
        printf("\n ENTER MARKS OF CHEMISTRY:");
        scanf("%d",&s[i].cmarks);
        fprintf(fp,"chemistry=%d\n",s[i].cmarks);
        printf("\n ENTER MARKS OF DRAWING:");
        scanf("%d",&s[i].dmarks);
        fprintf(fp,"drawing=%d\n",s[i].dmarks);
        printf("\ndata saved successfully\n");
        printf("\n\n");
       // fwrite(&s[i],sizeof(s),1,fp);
    }
    fclose(fp);
    break;
    case 2:
        printf(" \n Enter roll number:");
        scanf("%d",&rol);
    if(s[i].roll==rol)
    {
        printf("\n NAME:");
        puts(s[i].name);
        printf("\n ROLL NUMBER:%d\n",s[i].roll);
        printf("\n \t PHYSICS  \t CHEMISTRY \t DRAWING \tMATHS");
        printf("\n \t %d \t\t %d \t\t %d \t\t %d ",s[i].pmarks,s[i].cmarks,s[i].dmarks,s[i].mmarks);
        a=s[i].pmarks+s[i].cmarks+s[i].dmarks+s[i].mmarks;
        printf("\n\n AVERAGE OF MARKS:%d",a/4);
        printf("\n");
    }
    else
    {
        printf("\n\tRECORD NOT FOUND \n ");
    }
        break;
        case 3:
        break;
    }
    }

 else
    {
 if(lock==0)
    printf("\n \t PASSWORD INVALID");
 if(login==0)
    printf("\n\t INVALID USERNAME");
printf("\n \t TRY AGAIN LATER");
    }
    break ;

case 2:
    fp=fopen("result.txt","r");
    if(fp==NULL)
    {
        printf("can not open");
    }
    printf("\n----------------------------------------------------------");
    printf("\n \t\t RESULT");
    printf("\n----------------------------------------------------------");
    printf("\n SEARCH BY ROLL NO.:");
    scanf("%d",&rol);
    while(fread(&s[i],sizeof(s),1,fp)!=NULL)
    {if(s[i].roll==rol){

        //fread(&s[i],sizeof(s),1,fp);
      //  printf("\n NAME:%s",s[i].name);
       // printf("\n ROLL NUMBER:%d\n",s[i].roll);

      //  printf("\n \t PHYSICS  \t CHEMISTRY \t DRAWING \tMATHS");
        printf("\n \t %d \t\t %d \t\t %d \t\t %d ",s[i].pmarks,s[i].cmarks,s[i].dmarks,s[i].mmarks);
       // a=s[i].pmarks+s[i].cmarks+s[i].dmarks+s[i].mmarks;
       // printf("\n\n AVERAGE OF MARKS:%d",a/4);
        printf("\n");
fclose(fp);
    }}
    break;
case 3:
    break;
default:
    printf("\nEnter Between 1 to 3 only\n");
    break;
}}
while(ch!=3);

}
