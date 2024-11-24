
#include<stdio.h>
struct PS{
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

}

int main(){
int a[10];
for(int i=0;i<3;i++){
printf("Enter the name,burst time, arrival time and priority of process respectively.\n");
scanf("%d",&s[i].pname);
scanf("%d",&s[i].burst);
scanf("%d",&s[i].arrival);
scanf("%d",&s[i].priority);
}
int gnattChart[50];
for(int i=0;i<3;i++)
{
a[i]=s[i].priority;
}



sort(a,3);

int z=0;
for(int i=0;i<3;i++)
{
	int ii=a[i];
	for(int j=0;j<s[ii].burst;j++)
		{gnattChart[z]=s[ii].pname;
		z++;}
}

for(int i=0;i<z;i++){
printf("%d \t",gnattChart[i]);
}}
