#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#define LIMIT 100000

int binary_search2(int a[], int search,int l,int init)
{
  int mid;
  if (l>=init)
  {
       mid = init+(l-init)/4;
       printf("at location %d\n",mid);
      if(a[mid] == search)
      {
          return mid;
      }
      else if(a[mid]>search)
      {
          binary_search(a,search,mid-1,init);
      }
      else
      {
          binary_search(a,search,l,mid+1);
      }
  }
}


int binary_search(int a[], int search,int l,int init)
{
  int mid;
  if (l>=init)
  {
       mid = init+(l-init)/2;
       printf("at location %d\n",mid);
      if(a[mid] == search)
      {
          return mid;
      }
      else if(a[mid]>search)
      {
          binary_search(a,search,mid-1,init);
      }
      else
      {
          binary_search(a,search,l,mid+1);
      }
  }
}

void main()
{
    struct timeval stop, start;
    float diff2,diff4;
    int array[LIMIT],i;
    int search ;
    int init = 0;
    char ch;
    FILE *fp;

          /*  fp =fopen ("info.dat","w");
            i=0;

               for(i=0;i<LIMIT;i++)
               {
                   fprintf(fp, "%d\n",i);
               }
            fclose(fp);*/

            printf("\n\t\tBINARY SEARCH\n\n");
        do
        {
        printf("\nEnter Element to search from 0 to 100000 range : ");
        scanf("%d",&search);

        if(search>100000)
        {
            printf("\nInvalid search number !\n");
            return;
        }
        fp =fopen ("info.dat","r");
        i=0;
        do
        {
            fscanf(fp, "%d", &array[i]);
            i++;
        }while (i<LIMIT);
        fclose(fp);


    printf("\n\n****dividing array in 1/2****\n\n");

    gettimeofday(&start, NULL);
    int result = binary_search(array,search,LIMIT,init);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    gettimeofday(&stop, NULL);

    printf("\nstart %lu", start.tv_usec);
    printf("\nstop %lu", stop.tv_usec);

    diff2 = (stop.tv_usec - start.tv_usec)/1000000.0;

         if( diff2<0)
             diff2 =(start.tv_sec - stop.tv_sec)/1000000.0;
    printf("\nDifference %f s", diff2);


    printf("\n\n****dividing array in 1/4****\n\n");

    fp =fopen ("info.dat","r");
        i=0;
        do
        {
            fscanf(fp, "%d", &array[i]);
            i++;
        }while (i<LIMIT);
        fclose(fp);


    gettimeofday(&start, NULL);
    int result4 = binary_search2(array,search,i-1,init);
    (result4 == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    gettimeofday(&stop, NULL);

    printf("\nstart %lu", start.tv_usec);
    printf("\nstop %lu", stop.tv_usec);

    diff4 = (stop.tv_usec - start.tv_usec)/1000000.0;

         if( diff4<0)
             diff4 =(start.tv_sec - stop.tv_sec)/1000000.0;
    printf("\nDifference %f s\n", diff4);

    printf("\n-----------------------------------------------------------");
    printf("\n\t\t 1/2 \t\t|\t 1/4 \t\t |");
    printf("\n-----------------------------------------------------------");
    printf("\n\t %f \t\t|\t %f\t |",diff2,diff4);
    printf("\n-----------------------------------------------------------");



       /* else
        {
            printf("\nInvalid search number !\n");
            return;
        }*/

    printf("\n\nDo you want to continue (Y/N): ");
    ch = getche();
    }while(ch =='y' || ch =='Y');

}
