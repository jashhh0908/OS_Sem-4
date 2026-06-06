#include <stdio.h>

void first_fit(int blocks[], int process[], int n, int m) {
    int i, j;
    for(i = 0; i < m; i++) {
        int allocated = 0;
        for(j = 0; j < n; j++) {
            if(blocks[j] >= process[i]) {
                printf("Proccess %d allocated to Block %d\n", i + 1, j + 1);
                blocks[j] -= process[i];
                allocated = 1;
                break;
            }
        }
        if(!allocated) {
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
    first_fit(blocks, process, n, m);
}