#include <stdio.h>
#include<conio.h>
#include <string.h>
struct address
{
    char landmark[10];
    char street[10];
    char city[10];
    int pincode[7];
};
int main()
{
    int o,h,y,date,mon,yr,expireyr,issueyr,passnum,age;
    char gen[5],name[25],country[25],address[50],coll[20],company[15];
    system("COLOR 0E");
    printf("\n\t WELCOME TO VISA SERVICE OF JAPAN");

    printf("\n\n ENTER YOUR NAME(not more than 25 characters):");
    gets(name);
    printf("\nENTER CITIZENSHIP OF COUNTRY:");
    scanf("%s",country);
    printf("\nENTER DATE OF BIRTH (dd mm yyyy):");
    scanf("%d %d %d",&date,&mon,&yr);
     if(mon>=13 || date>=32){
        printf("\n\n ERROR IN DOB");
        printf("\nENTER DATE OF BIRTH (dd mm yyyy):");
        scanf("%d %d %d",&date,&mon,&yr);};

    age=2021-yr;
    printf("\n YOUR AGE IS :%d",2021-yr);
    while(age<0 || age>100){
        printf("\n\t AGE INVALID \n RE ENTER YOUR DATE OF BIRTH");

        printf("\nENTER DATE OF BIRTH (dd mm yyyy):");
        scanf("%d %d %d",&date,&mon,&yr);
        break;
    };
    printf("\n\n ENTER YOUR GENDER:");
    scanf("%s",gen);
    printf("\n\t\t PASSPORT DETAILS-\n");
    printf("\n\n ENTER YOUR PASSPORT NUMBER:");
    scanf("%d",&passnum);
    printf("\n ENTER DATE OF ISSUE OF PASSPORT YEAR:");
    scanf("%d",&issueyr);

    printf("\n ENTER EXPIRY YEAR OF PASSPORT:");
    scanf("%d",&expireyr);
    printf("\n\t\t PASSPORT ADDRESS-\n");
    struct address p1;
    printf("\n ENTER YOUR LANDMARK:");
    scanf("%s",p1.landmark);
    printf("\n ENTER YOUR STREET:");
    scanf("%s",p1.street);
    printf("\n ENTER YOUR CITY:");
    scanf("%s",p1.city);
    printf("\n ENTER YOUR PINCODE:");
    scanf("%s",p1.pincode);

   /* printf("\n APPLYING VISA AS STUDENT(yes/no):");
    scanf("%s",q);
    if(strcmp(q, "yes") == 0)
    printf("\n Enter college name:");
    scanf("%s",coll);*/
     printf("\n\n\t....................................................................");
    printf("\n\t........................under process...............................");
     printf("\n\t....................................................................\n");
    y=2021 - issueyr;

    h= expireyr - issueyr;

    if(h<5  || h>10 || y>11 || y<0 || expireyr<=2021 ||age<=0)
        {
    system("COLOR 0C");
    printf("\nPASSPORT INVALID \n\n\t VISA REJECTED");
        }
    else
        {

    printf("\n APPLYING VISA FOR JOB/STUDY/TOURISM");
     printf("\n ENTER  '1 FOR JOB'  '2 FOR STUDY' '3 FOR TOURIST':");
    scanf("%d",&o);
    switch(o)
    {
        case 1:
            printf("\n\t %s APPLYING FOR JOB VISA",name);


            if(age>20){
                    printf("\nENTER COMPANY NAME:");
                    scanf("%s",company);
                    printf("\n\n\t NAME: %s",name);
                    printf("\n\t COUNTRY: %s",country);
                    printf("\n GENDER: %s",gen);
                    printf("\n LANDMARK :%s",p1.landmark);
                    printf("\n STREET : %s",p1.street);
                    printf("\n CITY : %s",p1.city);
                    printf("\n PINCODE :%d ",p1.pincode);
                    system("COLOR 0A");
                    printf("\n\tVISA GRANTED FOR TENURE OF 2 YEAR ONLY");
            }
            else{
                system("COLOR 0C");
                printf("\n\n\tVISA REJECTED \n\n\t MINOR FOR JOB");
            }
            break;
        case 2:
            printf("\n\t %s APPLYING FOR STUDY VISA",name);
            printf("\n ENTER COLLEGE NAME:");
            scanf("%s",coll);

            printf("\n\n\t NAME: %s",name);
             printf("\n\t COUNTRY:%s",country);
             printf("\n\t GENDER:%s",gen);
             printf("\n ADDRESS");
             printf("\nLANDMARK :%s",p1.landmark);
             printf("\n STREET :%s ",p1.street);
             printf("\n CITY :%s ",p1.city);
             printf("\n PINCODE :%d ",p1.pincode);
             system("COLOR 0A");
            printf("\n\tVISA GRANTED FOR TENURE OF 5 YEAR ONLY\n");
            break;
         case 3:
             printf("\n\n\t \%s \t APPLYING VISA FOR TOURISM",name);
             printf("\n\t NAME:%s",name);
             printf("\n\t COUNTRY: %s",country);
             printf("\n\t GENDER: %s",gen);
             printf("\n ADDRESS");
             printf("\n LANDMARK :%s",p1.landmark);
             printf("\n STREET :%s",p1.street);
             printf("\n CITY : %s",p1.city);
             printf("\n PINCODE : %d",p1.pincode);
             system("COLOR 0A");
             printf("\n\n\tVISA GRANTED FOR TENURE OF 1 YEAR ONLY");
             break;
    }}

    return 0;

}

