//server side
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
    char * text="hello linux";

    //step 1: creating shared memory
shmID=shmget(key,40,IPC_CREAT|0666);
if(shmID<0){
    printf("error while creating");
    exit(0);
}
// step 2:attach shared mem
shmptr=shmat(shmID,NULL,0);
if(shmptr==(char *)-1){
    printf ("error while attaching");
}
//step 3: write in shared memory
temp=shmptr;
int len=strlen(text);
for(int i =0;i<len;i++){
    *temp=text[i];
    temp++;

}
*temp='%';
while(*shmptr!='#'){
sleep(1);
}
shmdt(shmptr);
shmctl(shmID,IPC_RMID,NULL);
return 0;
}
