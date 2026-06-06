#include <stdio.h>

//same as best just sign of comparison changes and variable
void worst_fit(int blocks[], int process[], int n, int m) {
    int i, j;
    for(i = 0; i < m; i++) {
        int worst = -1;
        for(j = 0; j < n; j++) {
            if(blocks[j] >= process[i]) {
                if(worst == -1 || blocks[j] > blocks[worst]) {
                    worst = j;
                }
            }
        }
        if(worst != -1) {
            printf("Process %d -> Block %d\n", i + 1, worst + 1);
            blocks[worst] -= process[i];    
        } else {
            printf("Process %d NOT allocated\n", i + 1);
        }
    }
}
int main() {
    int n, m;
    printf("Enter no of blocks: ");
    scanf("%d", &n);
    printf("Enter no of processes: ");
    scanf("%d", &m);

    int blocks[n], process[m];

    printf("Enter sizes of blocks:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &blocks[i]);
    }

    printf("Enter sizes of processes:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &process[i]);
    }
    printf("\n");
    worst_fit(blocks, process, n, m);
}