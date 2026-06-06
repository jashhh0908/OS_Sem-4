#include<stdio.h>

void isSafe(int n, int m, int allocation[n][m], int available[m], int need[n][m]) {
    int i,j;
    int finish[n];
    int work[m];
    for(i = 0; i < m; i++) {
        work[i] = available[i];
    }
    for(i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int safeSeq[n];
    int count = 0;
    while(count < n) {
        int found = 0;
        for(i = 0; i < n; i++) {
            //check for unfinished processes
            if(!finish[i]) {
                int valid = 1;
                //check need < work to allocate, valid is the flag for it 
                for(j = 0; j < m; j++) {
                    if(need[i][j] > work[j]) {
                        valid = 0;
                        break;
                    }
                }
                if(valid) {
                    //release the resources
                    for(j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = 1;
                    safeSeq[count] = i;
                    count++;
                    found = 1;
                }
            }
        }
        if(!found) {
            printf("System is in unsafe state\n");
            return;
        }
    }

    printf("\nSystem is safe\n");
    printf("Safe Sequence: ");
    for(i = 0; i < n; i++) {
        printf("P%d ", safeSeq[i]);
    }
}

int main() {
    int n, m, i, j;
    printf("Enter no of processes and resources: ");
    scanf("%d %d", &n, &m);

    int allocation[n][m];
    int max[n][m];
    int available[m];

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter Max Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    int need[n][m];
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    isSafe(n, m, allocation, available, need);
    return 0;
}   