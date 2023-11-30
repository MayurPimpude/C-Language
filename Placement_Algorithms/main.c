#include<stdio.h>
#define max 25

void bestfit(int nb,int b[],int np,int p[])
{
    int fragment[20],i,j,temp,lowest=9999;
    static int barray[20],parray[20];
    printf("\n\nBEST FIT\n");

for(i=1;i<=np;i++)
    {
        for(j=1;j<=nb;j++)
        {
            if(barray[j]!=1)
            {
                temp=b[j]-p[i];
                if(temp>=0)
                if(lowest>temp)
                {
                    parray[i]=j;
                    lowest=temp;
                }
            }
        }

    fragment[i]=lowest;
    barray[parray[i]]=1;
    lowest=10000;
    }

printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");

for(i=1;i<=np && parray[i]!=0;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,p[i],parray[i],b[parray[i]],fragment[i]);

}


void worstfit(int nb,int b[],int nf,int f[])
{
   // int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0;
   int frag[max],highest=0,temp,i,j;
 static int bf[max],ff[max];

printf("\n\nWORST FIT\n");

for(i=1;i<=nf;i++)
{
  for(j=1;j<=nb;j++)
    {
        if(bf[j]!=1)
        {
            temp=b[j]-f[i];
            if(temp>=0)
            if(highest<temp)
            {
                ff[i]=j;
                highest=temp;
            }
        }
        frag[i]=highest;
        bf[ff[i]]=1;
        highest=0;
    }

ff[i]=j;
highest=temp;
}

printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");

for(i=1;i<=nf;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);

}

 void firstfit(int bno,int bsize[],int pno,int psize[])
{
	int flags[10], allocation[10], i, j;
	printf("\n\nFIRST FIT \n");

	for(i = 0; i < 10; i++)
	{
		flags[i] = 0;
		allocation[i] = -1;
	}

	for(i = 1; i < pno; i++)
		for(j = 1; j < bno; j++)
			if(flags[j] == 0 && bsize[j] >= psize[i])
			{
				allocation[j] = i;
				flags[j] = 1;
				break;
			}

	printf("\nBlock no.\tsize\t\tprocess no.\t\tsize\n");
	for(i = 1; i < bno; i++)
	{
		printf("\n%d\t\t%d\t\t", i+1, bsize[i]);
		if(flags[i] == 1)
			printf("%d\t\t\t%d",allocation[i]+1,psize[allocation[i]]);
		else
			printf("Not allocated");
	}
}

void main()
{
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;

    printf("\nPLACEMENT ALGORITHM\n");

    printf("\nEnter no. of blocks : ");
	scanf("%d", &bno);

	printf("\nEnter size of each block: ");
	for(i = 1; i <=bno; i++)
		scanf("%d", &bsize[i]);

	printf("\nEnter no. of processes: ");
	scanf("%d", &pno);

	printf("\nEnter size of each process: ");
	for(i = 1; i <=pno; i++)
		scanf("%d", &psize[i]);

    firstfit(bno,bsize,pno,psize);
    bestfit(bno,bsize,pno,psize);
    worstfit(bno,bsize,pno,psize);
}
