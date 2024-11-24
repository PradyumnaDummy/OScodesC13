#include<stdio.h>

struct mem{
char status;
int size;
}m[25];

void ins(int data, int pos, int num)
{
int i;
for(i=num;i>=pos;i--)
{
m[i+1].status=m[i].status;
m[i+1].size=m[i].size;
}
m[pos].size=data;
m[pos].status='h';
}

int main()
{
int i,j,n,data,req[25];
n=12;
printf("enter memory chunk status");
for(i=0;i<n;i++)
scanf("%c",&m[i].status);

printf("enter memory chunk size");
for(i=0;i<n;i++)
scanf("%d",&m[i].size);

printf("enter req");
for(i=0;i<3;i++)
scanf("%d",&req[i]);


pointer=0;
for(i=0;i<3;i++)
{
for(j=0;j<n;j++)
{
if(m[j].status=='h')
	{
	if(m[j].size>=req[i])
		{
		data=m[j].size-req[i];
		m[j].size=req[i];
		m[j].status='u';
		pointer=j;
		if(data>0)
			{

			ins(data,j+1,n);
			n=n+1;
			}
		break;

		}

	}
}
}








for(i=0;i<n;i++)
printf("%c : %d\n",m[i].status,m[i].size);

return 0;
}




