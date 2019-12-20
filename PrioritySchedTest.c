// before for change pri


#include "timeVariables.h"
#include "user.h"



int main(int argc, char const *argv[])
{
    struct timeVariables my_time;
    int numOfProc = 25;
    int time_counter = 0, turnAroundTimeSum = 0, CBTSum = 0, WaitingTimeSum = 0;
    struct averageTimes lowest_priority = {0, 0, 0, 0},
     low_priority = {0, 0, 0, 0}, medium_priority = {0, 0, 0, 0}, high_priority = {0, 0, 0, 0},
      highest_priority = {0, 0, 0, 0};
    changePolicy(2);
    
    
    for (int i = 0; i < numOfProc; i ++){
            int fid = fork();
            if (fid == 0){
                if (i > 0 && i <= 5)
                    changePriority(5);
                if (i > 5 && i <= 10)
                    changePriority(4);
                if (i > 10 && i <= 15)
                    changePriority(3);
                if (i > 15 && i <= 20)
                    changePriority(2);
                if (i > 20 && i <= 25)
                    changePriority(1);
                for (int j=0; j < 100; j ++){
                    printf(1, " child number: %d,%d ", i, j);
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
                switch (my_time.priority_group)
                {
                case 1:
                    highest_priority.TurnAroundTime += (my_time.terminationTime - my_time.creationTime);
                    highest_priority.WaitingTime +=  (my_time.terminationTime - my_time.creationTime - my_time.runningTime);
                    highest_priority.CBT += my_time.runningTime;
                    highest_priority.time_counter ++;
                    break;
                case 2:
                    high_priority.TurnAroundTime += (my_time.terminationTime - my_time.creationTime);
                    high_priority.WaitingTime +=  (my_time.terminationTime - my_time.creationTime - my_time.runningTime);
                    high_priority.CBT += my_time.runningTime;
                    high_priority.time_counter ++;
                    break;
                case 3:
                    medium_priority.TurnAroundTime += (my_time.terminationTime - my_time.creationTime);
                    medium_priority.WaitingTime +=  (my_time.terminationTime - my_time.creationTime - my_time.runningTime);
                    medium_priority.CBT += my_time.runningTime;
                    medium_priority.time_counter ++;
                    break;
                case 4:
                    low_priority.TurnAroundTime += (my_time.terminationTime - my_time.creationTime);
                    low_priority.WaitingTime +=  (my_time.terminationTime - my_time.creationTime - my_time.runningTime);
                    low_priority.CBT += my_time.runningTime;
                    low_priority.time_counter ++;
                    break;
                case 5:
                    lowest_priority.TurnAroundTime += (my_time.terminationTime - my_time.creationTime);
                    lowest_priority.WaitingTime +=  (my_time.terminationTime - my_time.creationTime - my_time.runningTime);
                    lowest_priority.CBT += my_time.runningTime;
                    lowest_priority.time_counter ++;
                    break;
                default:
                    break;
                }     
            }
        }


  
        printf(1, "================ group 1 ===============\n");
        printf(1, "Average Turn Around Time: %d\n", highest_priority.TurnAroundTime / highest_priority.time_counter);
        printf(1, "Average CBT Time: %d\n", highest_priority.CBT / highest_priority.time_counter);
        printf(1, "Average Waitnig Time: %d\n", highest_priority.WaitingTime / highest_priority.time_counter);


        printf(1, "================ group 2 ===============\n");
        printf(1, "Average Turn Around Time: %d\n", high_priority.TurnAroundTime / high_priority.time_counter);
        printf(1, "Average CBT Time: %d\n", high_priority.CBT / high_priority.time_counter);
        printf(1, "Average Waitnig Time: %d\n", high_priority.WaitingTime / high_priority.time_counter);


        printf(1, "================ group 3 ===============\n");
        printf(1, "Average Turn Around Time: %d\n", medium_priority.TurnAroundTime / medium_priority.time_counter);
        printf(1, "Average CBT Time: %d\n", medium_priority.CBT / medium_priority.time_counter);
        printf(1, "Average Waitnig Time: %d\n", medium_priority.WaitingTime / medium_priority.time_counter);

        printf(1, "================ group 4 ===============\n");
        printf(1, "Average Turn Around Time: %d\n", low_priority.TurnAroundTime / low_priority.time_counter);
        printf(1, "Average CBT Time: %d\n", low_priority.CBT / low_priority.time_counter);
        printf(1, "Average Waitnig Time: %d\n", low_priority.WaitingTime / low_priority.time_counter);


        printf(1, "================ group 5 ===============\n");
        printf(1, "Average Turn Around Time: %d\n", lowest_priority.TurnAroundTime / lowest_priority.time_counter);
        printf(1, "Average CBT Time: %d\n", lowest_priority.CBT / lowest_priority.time_counter);
        printf(1, "Average Waitnig Time: %d\n", lowest_priority.WaitingTime / lowest_priority.time_counter);

    

  printf(1, "================ TOTAL ===============\n");
        
  
  printf(1, "Average Turn Around Time: %d\n", turnAroundTimeSum / time_counter);
  printf(1, "Average CBT Time: %d\n", CBTSum / time_counter);
  printf(1, "Average Waitnig Time: %d\n", WaitingTimeSum / time_counter);
    return 0;
    // exit();
}

