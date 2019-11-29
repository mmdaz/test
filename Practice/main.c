
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h>


int main(){
    //  int flag1 = fork();
    //  int flag2 = fork();
    // if (flag1 > 0)
    // {
    //    printf("p1 is >0 and parent and my child = %d\n",flag1);
    // }
    // else if(flag2 > 0)
    // {
    //     printf("p2 is >0 and parent and my child = %d\n",flag2);
    // }
    // else
    // {
    //     printf("p is =0 and child and flag1=%d and flag2=%d\n",flag1,flag2);
    // }
    
 int pid = fork();

int x = getChildren(pid);
  getppid();
  return 0;
}