#include "timeVariables.h"
#include "user.h"



int main(int argc, char const *argv[])
{
    struct timeVariables my_time;
    int numOfProc = 3;
    
    for (int i = 0; i < numOfProc; i ++){
            int fid = fork();
            if (fid == 0){
                for (int j=0; j < 100; j ++){
                    printf(1, " pid: %d,%d ", getpid(), j);
                }
                exit();
                
            }
            else
            {
                waitForChildren(&my_time);
                printf(1, "\nTurnAroundTime: %d\nCBT: %d\nWaiting Time: %d\n", my_time.terminationTime - my_time.creationTime,
                    my_time.runningTime,
                    my_time.terminationTime - my_time.creationTime - my_time.runningTime);
                
            }
        }
        
    return 0;
    // exit();
}

