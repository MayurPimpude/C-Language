#include <stdio.h>
#include <stdlib.h>

void fcfs()
{
    int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
	int n,sum=0,i,j,temp,pos,p[10];
	float totalTAT=0,totalWT=0;

    printf("\n#### FCFS ####\n");
	printf("\nEnter number of processes: ");
	scanf("%d",&n);

	printf("\nEnter arrival time and burst time for each process\n\n");

	for(int i=0;i<n;i++)
	{

		printf("Arrival time of process[%d] : ",i+1);
		scanf("%d",&at[i]);

		printf("Burst time of process[%d] : ",i+1);
		scanf("%d",&bt[i]);
        p[i]=i+1;
		printf("\n");
	}

	for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(at[j]<at[pos])
                pos=j;
        }

        temp=at[i];
        at[i]=at[pos];
        at[pos]=temp;

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

	//calculate completion time of processes

	for(j=0;j<1;j++)
    {
        i=0;
        sum=sum +at[i]+bt[j];
		ct[j]+=sum;
    }
	for(int j=1;j<n;j++)
	{
		sum=sum+bt[j];
		ct[j]+=sum;
	}

	//calculate turnaround time and waiting times

	for(int k=0;k<n;k++)
	{
		tat[k]=ct[k]-at[k];
		totalTAT+=tat[k];
	}


	for(int k=0;k<n;k++)
	{
		wt[k]=tat[k]-bt[k];
		totalWT+=wt[k];
	}

	printf("Solution: \n\n");
	printf("PID\t AT\t BT\t CT\t TAT\t WT\t\n\n");

	for(int i=0;i<n;i++)
	{
		printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}

	printf("\n\nAverage Turnaround Time = %f\n",totalTAT/n);
	printf("Average WT = %f\n\n",totalWT/n);

}

void RR()
{
     int i, limit, total = 0, x, counter = 0, time_quantum;
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
      float average_wait_time, average_turnaround_time;

      printf("\n#### Round Robin ####\n");
      printf("\nEnter Total Number of Processes : ");
      scanf("%d", &limit);
      x = limit;
      for(i = 0; i < limit; i++)
      {
            printf("\nEnter Details of PID[%d]\n",i + 1);

            printf("\nArrival Time: ");
            scanf("%d", &arrival_time[i]);

            printf("Burst Time: ");
            scanf("%d", &burst_time[i]);
            printf("\n");
            temp[i] = burst_time[i];
      }

      printf("\nEnter Time Quantum: ");
      scanf("%d", &time_quantum);
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i];
                  turnaround_time = turnaround_time + total - arrival_time[i];
                  counter = 0;
            }
            if(i == limit - 1)
            {
                  i = 0;
            }
            else if(arrival_time[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }

      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\nAverage Waiting Time: %f", average_wait_time);
      printf("\nAvg Turnaround Time: %f\n", average_turnaround_time);

}

void SJF()
{
     printf("\n#### SJF Non-Preemptive ####\n");
    int arrival_time[10], burst_time[10], temp[10];
      int i, smallest, count = 0, time, limit;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;
      printf("\nEnter the Total Number of Processes : ");
      scanf("%d", &limit);
      printf("\nEnter Details of %d Processes\n", limit);
      for(i = 0; i < limit; i++)
      {
            printf("\nEnter Arrival Time : ");
            scanf("%d", &arrival_time[i]);
            printf("Enter Burst Time : ");
            scanf("%d", &burst_time[i]);
            temp[i] = burst_time[i];
      }
      burst_time[9] = 9999;
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
                  }
            }
            burst_time[smallest]--;
            if(burst_time[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
                  turnaround_time = turnaround_time + end - arrival_time[smallest];
            }
      }
      average_waiting_time = wait_time / limit;
      average_turnaround_time = turnaround_time / limit;
      printf("\n\nAverage Waiting Time : %lf\n", average_waiting_time);
      printf("Average Turnaround Time : %lf\n", average_turnaround_time);

}

int main()
{
    char ch;
    int choice;
    do{
    printf("\n****Scheduling Algorithm****\n");
    printf("\n1.FCFS\n2.RR\n3.SJF\n4.Exit\n");
    printf("\nEnter Choice :");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        fcfs();
        break;

    case 2:
        RR();
        break;

    case 3:
        SJF();
        break;

    case 4:
        break;

    default:
        printf("\nInvalid Input !!\n");
    }
    printf("\nDo you want to continue (Y/N): ");
    ch = getche();
    printf("\n");
    }while(ch=='y' || ch=='Y');
    return 0;
}
