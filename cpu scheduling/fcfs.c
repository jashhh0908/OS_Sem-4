#include <stdio.h>

void sort(int process[], int arrival[], int burst[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arrival[j] > arrival[j+1]) {
                temp = process[j];
                process[j] = process[j+1];
                process[j+1] = temp;

                temp = arrival[j];
                arrival[j] = arrival[j+1];
                arrival[j+1] = temp;

                temp = burst[j];
                burst[j] = burst[j+1];
                burst[j+1] = temp;
            }
        }
    }
}

void printTable(int process[], int arrival_time[], int burst_time[], int wait_time[], int tat_time[], int n) {
    printf("Process\tAT\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", process[i], arrival_time[i], burst_time[i], wait_time[i], tat_time[i]);
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

    int process[n], arrival_time[n], burst_time[n], tat_time[n], wait_time[n];

    for(int i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter arrival time for P%d: ", process[i]);
        scanf("%d", &arrival_time[i]);
        printf("Enter burst time for P%d: ", process[i]);
        scanf("%d", &burst_time[i]);
        printf("\n");
    }

    sort(process, arrival_time, burst_time, n);

    int currentTime = 0, total_tat = 0, total_wt = 0;
    for(int i = 0; i < n; i++) {
        if(currentTime < arrival_time[i]) {
            currentTime = arrival_time[i];
        }
        int completion = currentTime + burst_time[i];

        tat_time[i] = completion - arrival_time[i];
        wait_time[i] = tat_time[i] - burst_time[i];

        total_tat += tat_time[i];
        total_wt += wait_time[i];

        currentTime = completion;
    }

    printTable(process, arrival_time, burst_time,  wait_time, tat_time, n);

    printf("Average waiting time: %f\n", (float)total_wt / n);
    printf("Average turnaround time: %f\n", (float)total_tat / n);

    printf("\nGantt Chart:\n");
    int time = 0;
    for(int i = 0; i < n; i++) {
        if(time < arrival_time[i]) {
            printf("%d | Idle | ", time);
            time = arrival_time[i];
        }
        printf("%d | P%d | ", time, process[i]);
        time += burst_time[i];
    }
    printf("%d\n", time);
    return 0;
}