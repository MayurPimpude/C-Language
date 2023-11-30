#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#define LIMIT 250000

void QuickSort(int array[],int length)
{
      QuickSort_Recursion(array,0,length-1);
}

void QuickSort_Recursion(int array[],int low,int high)
{
    if(low<high)
    {
        int pivot_index = partition(array,low,high);
        QuickSort_Recursion(array,low,pivot_index - 1);
        QuickSort_Recursion(array,pivot_index + 1,high);
    }
}

int partition(int array[],int low,int high)
{
    int pivot_value = array[high];
    int i = low;
    for(int j=low;j<high;j++)
    {
        if (array[j]<=pivot_value)
        {
            swap(&array[i],&array[j]);
            i++;
        }
    }
    swap(&array[i],&array[high]);

    return i;
}

void MergeSort(int array[],int length)
{
    MergeSort_Recursion(array,0,length-1);
}

void MergeSort_Recursion(int array[],int l, int r)
{
    if(l<r)
    {
        int m = l + (r-l)/2;
        MergeSort_Recursion(array,l,m);
        MergeSort_Recursion(array,m+1,r);
        mergeSorted_Array(array,l,m,r);
    }
}

void mergeSorted_Array(int array[],int l,int m,int r)
{
    int left = m -l+1;
    int right = r - m;
    int temp_left[left];
    int temp_right[right];

    int i,j,k;
    for(int i = 0;i<left;i++)
    {
        temp_left[i] = array[l+i];
    }

    for(int i=0;i<right;i++)
    {
        temp_right[i] = array[m+1+i];
    }

    for(i=0,j=0,k=l;k<=r;k++)
    {
        if ((i<left)&&(j>=right || temp_left[i] <= temp_right[j]))
        {
            array[k] = temp_left[i];
            i++;
        }
        else
        {
            array[k] = temp_right[j];
            j++;
        }
    }
}

void PrintArray(int array[],int length)
{
    int i;
      FILE *fp;
     fp =fopen ("output.txt","w");
     fprintf(fp,"Quick Sort");
     for (int i=0;i<length;i++)
   {
       fprintf(fp,"%d",array[i]);
   }
    fclose(fp);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
     struct timeval stop, start;
    int i,j,k;
    int random_number;
    int arr[LIMIT];
    char str[20][20] = {"numbers0.dat","numbers1.dat","numbers2.dat","numbers3.dat","numbers4.dat"};
    float  Q_difference[8],M_difference[8];
    int length = LIMIT;
    FILE *fp;

   /* for(j=0;j<5;j++)
        {
            fp =fopen (str[j],"w");
            srand((unsigned)time(0));
            i=0;

                do
                {
                    random_number = (int) (rand()%1000) ;
                    fprintf(fp, "%d\n", random_number);
                    i++;
                }while (i<LIMIT);
            fclose(fp);

        }*/


   printf("\n\nMERGE SORT\n");

    for(j=0;j<5;j++)
    {
        fp =fopen (str[j],"r");

        i=0;

        do
        {
            fscanf(fp, "%d", &arr[i]);
            i++;
        }while (i<LIMIT);

        fclose(fp);

        gettimeofday(&start, NULL);
        MergeSort(arr,length);
        gettimeofday(&stop, NULL);

        printf("\n\nFILE NO. : %d",j+1);
        printf("\nFor Merge Sort");
        printf("\nstart %lu", start.tv_usec);
        printf("\nstop %lu", stop.tv_usec);

        M_difference[j] = (stop.tv_usec - start.tv_usec)/1000000.0;
        if( M_difference[j]<0)
             M_difference[j] = - M_difference[j];
        printf("\nDifference %4f s",M_difference[j]);
    }

      printf("\n\nQUICK SORT\n");

    for(k=0;k<5;k++)
    {

        fp = fopen (str[k],"r");

        i=0;

        do
        {
            fscanf(fp, "%d", &arr[i]);
            i++;
        }while (i<LIMIT);

        fclose(fp);

        gettimeofday(&start, NULL);
        QuickSort(arr,i);
        gettimeofday(&stop, NULL);

        printf("\n\nFILE NO. %d",k+1);
        printf("\nFor QUICK Sort");
        printf("\nstart %lu", start.tv_usec);
        printf("\nstop %lu", stop.tv_usec);

        Q_difference[k] = (stop.tv_usec - start.tv_usec)/1000000.0;
         if( Q_difference[k]<0)
             Q_difference[k] =(start.tv_usec - stop.tv_usec)/1000000.0;
        printf("\nDifference %f s", Q_difference[k]);

    }

    printf("\n-------------------------------------------------------------------------");
    printf("\n\t      |  Merge sort  \t\t\t|\t Quick sort \t|");
    printf("\n-------------------------------------------------------------------------");
    printf("\n number0.dat  |\t\t  %f  \t\t |\t %f \t|",M_difference[0],Q_difference[0]);
    printf("\n-------------------------------------------------------------------------");
    printf("\n number1.dat  |\t\t  %f  \t\t |\t %f \t|",M_difference[1],Q_difference[1]);
    printf("\n-------------------------------------------------------------------------");
    printf("\n number2.dat  |\t\t  %f  \t\t |\t %f \t|",M_difference[2],Q_difference[2]);
    printf("\n-------------------------------------------------------------------------");
    printf("\n number3.dat  |\t\t  %f  \t\t |\t %f \t|",M_difference[3],Q_difference[3]);
    printf("\n-------------------------------------------------------------------------");
    printf("\n number4.dat  |\t\t  %f  \t\t |\t %f \t|",M_difference[4],Q_difference[4]);
    printf("\n-------------------------------------------------------------------------");

   return 0;
}
