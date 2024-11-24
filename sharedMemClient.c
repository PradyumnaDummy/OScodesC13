//client side
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>
#include<sys/shm.h>
int main(){
    int shmID;
    char shmptr , temp;
    key_t key=9876;
    shmID=shmget(key,40,0666);
if(shmID<0){
    printf("error while creating");
    exit(0);
}
shmptr=shmat(shmID,NULL,0);
if(shmptr==(char *)-1){
    printf ("error while attaching");
    exit(0);
}

temp=shmptr;
while(*temp!='%'){
printf("%c",*temp);
temp++;}
*shmptr='#';
shmdt(shmptr);
return 0;
}
