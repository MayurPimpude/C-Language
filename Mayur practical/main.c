#include <stdio.h>
#include<string.h>
#include <stdlib.h>
struct cricket
{
    char team[10];
    char name[50];
    float avg;
}p[50];
int main()
{
   int i,k,n=2;

 for(i=0;i<n;i++)
 {
  printf("\n Enter Team Name : ");
  scanf("%s",p[i].team);
     for(k=0;k<=1;k++)
 {
      printf("\n Enter Player Name : ");
  scanf("%s",p[i].name);
  printf("\n Enter Batting Average : ");
  scanf("%f",&p[i].avg);

 }
 }

  printf("\n TEAM \t PLAYER \tAVERAGE");
for(i=0;i<n;i++){
    if(k=1){

    printf("\n %s \t %s \t %f",p[i].team,p[i].name,p[i].avg);
}
}
    return 0;
}
