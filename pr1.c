#include<stdio.h>
#include <sys/wait.h>  
#include <unistd.h> 
int main()
{
pid_t i,j;
i=fork();
j=fork();
if (i>0 && j>0)
{
printf("i=%d j=%d id=%d par_id=%d:i am parent running\n",i,j,getpid(),getppid());
//wait(NULL);
//wait(NULL);
printf("parent exits\n");
}
else if (i==0 && j>0) 
{
printf("i=%d j=%d id=%d par_id=%d:i am first child\n",i,j,getpid(),getppid());
//wait(NULL);
printf("child 1 exits\n");
}
else if (j==0 && i>0) 
{
printf("i=%d j=%d id=%d par_id=%d:i am second child\n",i,j,getpid(),getppid());
//execlp("/bin/sh","ls", "-l",NULL);
printf("child 2 exits\n");
}
else
{
printf("i=%d j=%d id=%d par_id=%d:i am grand child\n",i,j,getpid(),getppid());
printf("grandchild exits\n");
}

printf("all\n");
return 0;

}
  
