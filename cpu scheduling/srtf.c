#include <stdio.h>

void printTable(int process[], int arrival_time[], int burst_time[], int wait_time[], int tat_time[], int n) {
    printf("Process\tAT\tBT\tWT\tTAT\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",process[i], arrival_time[i], burst_time[i], wait_time[i], tat_time[i]);
    }
}

int main() {
    int n;
    printf("Enter no of processes: ");
    scanf("%d", &n);
    if(n <= 0) {
        printf("Invalid input\n");
        return 1;
    }

    int process[n], arrival_time[n], burst_time[n], tat_time[n], wait_time[n], completed[n], remaining_time[n];
    for(int i = 0; i < n; i++) {
        completed[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter arrival time for P%d: ", process[i]);
        scanf("%d", &arrival_time[i]);
        printf("Enter burst time for P%d: ", process[i]);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];

        printf("\n");
    }

    int currentTime = 0, total_tat = 0, total_wt = 0;
    int completed_count = 0;
    while(completed_count < n) {
        int shortest = -1;
        //find shortest process that has arrived and not completed
        for(int i = 0; i < n; i++) {
            if (arrival_time[i] <= currentTime && !completed[i]) {
                if(shortest == -1 || remaining_time[i] < remaining_time[shortest]) {
                    shortest = i;
                }
            }
        }
        //if shortest = -1 means no process has arrived (idle cpu), calculate the process which arrives first
        if (shortest == -1) {
            int nextArrival = 999999;
            for(int i = 0; i < n; i++) {
                if(!completed[i] && arrival_time[i] > currentTime && arrival_time[i] < nextArrival) {
                    nextArrival = arrival_time[i];
                }
            }
            printf("%d | Idle | ", currentTime);
            currentTime = nextArrival;
            continue;
        }
        
        printf("%d | P%d | ", currentTime, process[shortest]);

        //decrease time by 1 unit and check again if any other process that have arrived have lesser burst time or not
        remaining_time[shortest]--;
        currentTime++;

        if(remaining_time[shortest] == 0) {
            tat_time[shortest] = currentTime - arrival_time[shortest];
            wait_time[shortest] = tat_time[shortest] - burst_time[shortest];

            total_tat += tat_time[shortest];
            total_wt += wait_time[shortest];

            completed[shortest] = 1;
            completed_count++;
        }
        
    }

    printf("%d\n", currentTime);
    printf("\n");

    printTable(process, arrival_time, burst_time,  wait_time, tat_time, n);
    printf("\n");

    printf("Average waiting time: %f\n", (float)total_wt / n);
    printf("Average turnaround time: %f\n", (float)total_tat / n);

    return 0;
}