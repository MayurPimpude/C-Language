#include <stdio.h>
int main()
{char pass[]="mayur",pas[20],user[]="navalpimpude",users[20];
int result,r;
    printf("\n ENTER USERNAME:");
    scanf("%s",users);
    printf("\n ENTER PASSWORD:");
scanf("%s",pas);
result= strcmp(pass,pas);
r= strcmp(user,users);
if(result==0&&r==0)
{
    printf("\n Hello World");
}
else
{if(r==0){
    printf("\n incorrect password");}
    else{
        printf("\n incorrect username");
    }}
    return 0;
}

