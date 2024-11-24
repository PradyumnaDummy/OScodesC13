#include<stdio.h>
struct cpus{
int pname;
int burst;
int arrival;
int priority;
}s[10];

void sort(int a[],int n)
{
int b[10],c[10];
int min,i,j,tmp,ind;
for(i=0;i<n;i++)
{
b[i]=a[i];
c[i]=a[i];}
for(i=0;i<n;i++)
{
min=100;
for(j=i;j<n;j++)

{
if (b[j]<min)
{
min=b[j];
ind=j;}
}
tmp=b[i];
b[i]=min;
b[ind]=tmp;

}

for (i=0;i<n;i++)
{
for (j=0;j<n;j++)
{
if (b[i]==c[j]){a[i]=j;c[j]=-1;break;}
}}

for(i=0;i<n;i++)
{
printf("%d ",a[i]);}
}

int main()
{
int num_p,i,j,k,ii;
int arr[100],wt[10],rt[10],a[10];
printf("enter number of processes");
scanf("%d",&num_p);

for(i=0;i<num_p;i++)
{
printf("enter data for process %d in order pname burst arrival and priority",i+1);
scanf("%d %d %d %d",&s[i].pname,&s[i].burst,&s[i].arrival,&s[i].priority);
}

for(i=0;i<num_p;i++)
{
a[i]=s[i].burst;
}



sort(a,num_p);

k=0;
for(i=0;i<num_p;i++)
{
	ii=a[i];
	for(j=0;j<s[ii].burst;j++)
		{arr[k]=s[ii].pname;
		k++;}
}

for(i=0;i<num_p;i++)
{
for(j=0;j<k;j++)
{
if(arr[j]==s[i].pname)
{
rt[i]=j-s[i].arrival;
break;
}
}
}

for (i=0;i<num_p;i++)
{
printf("%d ",rt[i]);
}
}



