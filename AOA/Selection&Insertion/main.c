#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#define LIMIT 100000

void selection_sort(int arr[], int n)
{
    int i, j, min_idx;
    int temp;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        //swap
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main()
{
    struct timeval stop, start;
    int i,j,k;
    int random_number;
    int arr[LIMIT];
    char str[20][20] = {"numbers0.dat","numbers1.dat","numbers2.dat","numbers3.dat","numbers4.dat"};
    int  S_difference[8],I_difference[8];
    FILE *fp;

    //file or data set creation using for loop added 2d strings
     for(j=0;j<5;j++)
        {
            fp =fopen (str[j],"w");
            srand((unsigned)time(0));
            i=0;

                do
                {
                    random_number = (int) (rand()%500) ;
                   // printf("%d\n", random_number);
                    fprintf(fp, "%d\n", random_number);
                    i++;
                }while (i<LIMIT);
            fclose(fp);

        }

    // FILES reading / input for insertion algorithm using for loop reading file using 2d string
  printf("\n\nINSERTION SORT\n");

    for(j=0;j<5;j++)
    {
        fp =fopen (str[j],"r");

        i=0;

        do
        {
            fscanf(fp, "%d", &arr[i]);
    //       printf("%d\n",arr[i]);
            i++;
        }while (i<LIMIT);

        fclose(fp);

        gettimeofday(&start, NULL);
        insertion_sort(arr,i);
        gettimeofday(&stop, NULL);

        printf("\n\nFILE NO. : %d",j+1);
        printf("\nFor Insertion Sort");
        printf("\nstart %lu", start.tv_sec);
        printf("\nstop %lu", stop.tv_sec);

        I_difference[j] = stop.tv_sec - start.tv_sec;
        printf("\nDifference %d s",I_difference[j]);
    }

    // FILES reading / input for Selection algorithm using for loop reading file using 2d string

    printf("\n\nSELECTION SORT\n");

    for(k=0;k<5;k++)
    {

        fp = fopen (str[k],"r");

        i=0;

        do
        {
            fscanf(fp, "%d", &arr[i]);
//          printf("%d\n",arr[i]);
            i++;
        }while (i<LIMIT);

        fclose(fp);

        gettimeofday(&start, NULL);
        selection_sort(arr,i);
        gettimeofday(&stop, NULL);

        printf("\n\nFILE NO. %d",k+1);
        printf("\nFor Selection Sort");
        printf("\nstart %lu", start.tv_sec);
        printf("\nstop %lu", stop.tv_sec);

        S_difference[k] = stop.tv_sec - start.tv_sec;
        printf("\nDifference %d s", S_difference[k]);

    }

    printf("\n-------------------------------------------------------------------------");
    printf("\n\t      |  selection sort  \t |\t insertion sort \t|");
    printf("\n-------------------------------------------------------------------------");
    printf("\n number0.dat  |\t\t  %d  \t\t |\t\t %d \t\t|",S_difference[0],I_difference[0]);
    printf("\n-------------------------------------------------------------------------");
    printf("\n number1.dat  |\t\t  %d  \t\t |\t\t %d \t\t|",S_difference[1],I_difference[1]);
    printf("\n-------------------------------------------------------------------------");
    printf("\n number2.dat  |\t\t  %d  \t\t |\t\t %d  \t\t|",S_difference[2],I_difference[2]);
    printf("\n-------------------------------------------------------------------------");
    printf("\n number3.dat  |\t\t  %d  \t\t |\t\t %d  \t\t|",S_difference[3],I_difference[3]);
    printf("\n-------------------------------------------------------------------------");
    printf("\n number4.dat  |\t\t  %d  \t\t |\t\t %d  \t\t|",S_difference[4],I_difference[4]);
    printf("\n-------------------------------------------------------------------------");

    return 0;
}
