#include "timeVariables.h"
#include "user.h"



int main(int argc, char const *argv[])
{
    struct timeVariables my_time;
    int numOfProc = 3;
    int time_counter = 0, turnAroundTimeSum = 0, CBTSum = 0, WaitingTimeSum = 0;
    
    
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
                turnAroundTimeSum += my_time.terminationTime - my_time.creationTime;
                CBTSum += my_time.runningTime;
                WaitingTimeSum += my_time.terminationTime - my_time.creationTime - my_time.runningTime;
                time_counter ++ ;

                
                
            }
        }


  printf(1, "Average Turn Around Time: %d\n", turnAroundTimeSum / time_counter);
  printf(1, "Average CBT Time: %d\n", CBTSum / time_counter);
  printf(1, "Average Waitnig Time: %d\n", WaitingTimeSum / time_counter);
    return 0;
    // exit();
}

