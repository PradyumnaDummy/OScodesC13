#include<stdio.h>
struct cpus{
int pname;
int burst;
int arrival;
int priority;
}s[10];

int main()
{
int num_p,i,j,k;
int arr[100],wt[10],rt[10];
printf("enter number of processes");
scanf("%d",&num_p);

for(i=0;i<num_p;i++)
{
printf("enter data for process %d in order pname burst arrival and priority",i+1);
scanf("%d %d %d %d",&s[i].pname,&s[i].burst,&s[i].arrival,&s[i].priority);
}

k=0;

for(i=0;i<num_p;i++) //num_p=3
{
	for(j=0;j<s[i].burst;j++)
		{arr[k]=s[i].pname;
		k++;}
}

for(i=0;i<num_p;i++)    //i=1
{
for(j=0;j<k;j++) //k to 0
{
if(arr[j]==s[i].pname)    //s[1].pname=1...  1 1 1 2 2 3 3 3 3
{
rt[i]=j-s[i].arrival;   //wt[i]= (j+1) - s[i].arrival - s[i].burst .... tat[i]=(j+1) - s[i].arrival
break;
}
}
}

for (i=0;i<num_p;i++)
{
printf("%d ",rt[i]);
}
}


//1 1 1 2 2 3 3 3 3
//  0 1 2 3 4 5 6 7 8 
//P1(3)  P2(2)   P3(4)
//0 -3    -5     -9
