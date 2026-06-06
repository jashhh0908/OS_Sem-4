#include <stdio.h>

void next_fit(int blocks[], int process[], int n, int m) {
    int i, j;
    int lastIndex = 0;
    for(i = 0; i < m; i++) {
        int allocated = 0;
        int count = 0;
        j = lastIndex;
        while(count < n) {
            if(blocks[j] >= process[i]) {
                printf("Process %d -> Block %d\n", i + 1, j + 1);
                blocks[j] -= process[i];
                lastIndex = j;
                allocated = 1;
                break;
            }
            j = (j + 1) % n;
            count++;
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
    next_fit(blocks, process, n, m);
}