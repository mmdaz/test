#include "user.h"
#include "types.h"
#include "stat.h"



int main(int argc, char *argv[]){

fork();
fork();
fork();
// int pid2 = fork();
int pid = getpid();
// getChildren(pid);
printf(1, "ppid: %d\n", getppid());
printf(1, "pid: %d\n", getpid());
int children_id = getChildren(pid);
if (children_id != -1)
printf(1, "children of %d : %d\n", getppid(), children_id);
// printf(1, )

// printf(1, "children of %d is : %d\n", pid2, getChildren(pid2));

exit();
}