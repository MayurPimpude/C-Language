#include<stdio.h>
#define N 10

int findLRU(int time[], int n)
{
int i, minimum = time[0], pos = 0;

for(i = 1; i < n; ++i)
    {
        if(time[i] < minimum)
        {
            minimum = time[i];
            pos = i;
        }
    }
return pos;
}

void LRU(int no_of_pages,int pages[],int no_of_frames)
{
    printf("\n===========================================");
    printf("\n\tPage Replacement Policy LRU \n");
    printf("===========================================\n");

    int  frames[10],counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
    int miss,hit;

    for(i = 0; i < no_of_frames; ++i)
    {
     frames[i] = -1;
    }

    for(i = 0; i < no_of_pages; ++i)
    {
     flag1 = flag2 = 0;

     for(j = 0; j < no_of_frames; ++j)
     {
        if(frames[j] == pages[i]){
        counter++;
        time[j] = counter;
    flag1 = flag2 = 1;
    break;
   }
     }

  if(flag1 == 0)
  {
    for(j = 0; j < no_of_frames; ++j)
    {
        if(frames[j] == -1)
        {
            counter++;
            faults++;
            frames[j] = pages[i];
            time[j] = counter;
            flag2 = 1;
            break;
        }
     }
    }

     if(flag2 == 0)
     {
        pos = findLRU(time, no_of_frames);
        counter++;
        faults++;
        frames[pos] = pages[i];
        time[pos] = counter;
     }

     printf("\n");

     for(j = 0; j < no_of_frames; ++j){
     printf("%d\t", frames[j]);
     }
}
printf("\n\nTotal Page Faults = %d\n", faults);

}

void optimal(int no_of_pages,int pages[],int no_of_frames)
{
    int  temp[10],frames[20],flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    int miss,hit;
    printf("\n===========================================");
    printf("\n\tPage Replacement Policy Optimal \n");
    printf("===========================================\n");

    for(i = 0; i < no_of_frames; ++i)
    {
        frames[i] = -1;
    }

    for(i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;

        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }

        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0){
         flag3 =0;

            for(j = 0; j < no_of_frames; ++j){
             temp[j] = -1;

             for(k = i + 1; k < no_of_pages; ++k){
             if(frames[j] == pages[k]){
             temp[j] = k;
             break;
             }
             }
            }

            for(j = 0; j < no_of_frames; ++j){
             if(temp[j] == -1){
             pos = j;
             flag3 = 1;
             break;
             }
            }

            if(flag3 ==0){
             max = temp[0];
             pos = 0;

             for(j = 1; j < no_of_frames; ++j){
             if(temp[j] > max){
             max = temp[j];
             pos = j;
             }
             }
            }
frames[pos] = pages[i];
faults++;
        }

        printf("\n");

        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d", faults);

}

void FCFS(int pages,int referenceString[],int frames)
{
    printf("\n===========================================");
    printf("\n\tPage Replacement Policy FCFS \n");
    printf("===========================================\n");

    int  pageFaults = 0, m, n, s;

int temp[frames];
for(m = 0; m < frames; m++)
{
  temp[m] = -1;
}
for(m = 0; m < pages; m++)
{
  s = 0;
  for(n = 0; n < frames; n++)
   {
      if(referenceString[m] == temp[n])
         {
            s++;
            pageFaults--;
         }
   }
   pageFaults++;
   if((pageFaults <= frames) && (s == 0))
      {
        temp[m] = referenceString[m];
      }
   else if(s == 0)
      {
        temp[(pageFaults - 1) % frames] = referenceString[m];
      }
      printf("\n");
      for(n = 0; n < frames; n++)
       {
         printf("%d\t", temp[n]);
       }
}
printf("\nTotal Page Faults:\t%d\n", pageFaults);

}

int main()
{
    int pagesize,page[20],fsize,i;

    printf("===========================================");
    printf("\n\tPage Replacement Policy\n");
    printf("===========================================\n");

    printf("\nEnter array size: ");
    scanf("%d",&pagesize);

    printf("\nEnter array : ");
    for(i=0;i<pagesize;i++)
    {
        scanf("%d",&page[i]);
    }

    printf("\nEnter Frame size : ");
    scanf("%d",&fsize);

    FCFS(pagesize,page,fsize);
    optimal(pagesize,page,fsize);
    LRU(pagesize,page,fsize);

    return 0;
}
