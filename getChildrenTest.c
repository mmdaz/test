#include "user.h"
#include "types.h"


int main(){

int pid1 = fork();
int pid2 = fork();

printf(1, "ppid: %d", getppid());
printf(1, "pid: %d\n", getpid());
getChildren(pid1);
getChildren(pid2);

     return 0;
}