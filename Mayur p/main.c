#include <stdio.h>
#include <stdlib.h>
struct cricket
{
    char team[10];
    char name[50];
    float avg;
}p[50];
int main()
{
     int i,k,n=4;

 for(i=0;i<n;i++)
 {
  printf("\n Enter Team Name : ");
  scanf("%s",p[i].team);


      printf("\n Enter Player Name : ");
  scanf("%s",p[i].name);
  printf("\n Enter Batting Average : ");
  scanf("%f",&p[i].avg);

 }

  printf("\n TEAM      \t  PLAYER \t  AVERAGE");
for(i=0;i<n;i++)
    printf("\n %s     \t %s \t %f",p[i].team,p[i].name,p[i].avg);

    return 0;

}
