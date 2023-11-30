#include<stdio.h>
#include<stdlib.h>
#include <conio.h>

void Array(int **marks, int *students, int classes)
{
    int i,j,highest,sum = 0;
    float avg;
    printf("\nMarks Array : ");
    for(i=0;i<classes;i++)
    {
        printf("\n");
        for(j=0;j<students[i];j++)
        {
             printf("%d ",marks[i][j]);
             if (marks[i][j] > highest)
               {
                   highest = marks[i][j];
               }
        }
    }

     printf("\n");

     for(i=0;i<classes;i++)
    {

        for(j=0;j<students[i];j++)
        {
            sum = sum +marks[i][j];
        }
        printf("\nSum : %d ",sum);
        avg = sum/students[i];
        printf("\nAverage of class %d is : %f ",i+1,avg);
        sum=0;
         printf("\n");
    }

    for(i=0;i<classes;i++)
    {
        for(j=0;j<students[i];j++)
        {
               if (highest == marks[i][j])
               {
                printf("\n\t**TOPPER**");
                printf("\nTOPPER from class %d ,student no. %d || MARKS : %d ",i+1,j+1,highest);
                break;
               }
        }
    }

    printf("\n");
}

int main()
{
    int **marks;
    int *students;
    int i,classes,j;

    printf("\nNumber of classes : ");
    scanf("%d",&classes);

    students = (int *)malloc(classes*sizeof(int));
    marks = (int **)malloc(classes*sizeof(int *));
    for(i=0;i<classes;i++)
    {

        printf("\nNumber of students in class %d : ",i+1);
        scanf("%d",&students[i]);

        marks[i] = (int *)malloc(students[i]*sizeof(int));

        printf("\n");

        for(j=0;j<students[i];j++)
            {
            printf("Enter marks of Class %d Student %d : ",i+1,j+1);
            scanf("%d",&marks[i][j]);
            }


    }

    printf("\n\nLength of 2D Array is : ");
    for(i=0;i<classes;i++)
    {
        printf(" %d",students[i]);
    }

    Array(marks,students,classes);

}

