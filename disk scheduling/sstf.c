#include <stdio.h>
#include <stdlib.h>
int sstf(int n, int head, int req[]) {
    int sum = 0;
    int visited[n], i, j;
    for(i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for(i = 0; i < n; i++) {
        int min = 999999;
        int index = -1;

        for(j = 0; j < n; j++) {
            if(!visited[j]) {
                int distance = abs(req[j] - head);
                if(distance < min) {
                    min = distance;
                    index = j;
                }
            }
        }
        sum += min;
        head = req[index];
        visited[index] = 1;
    }
    return sum;
}

int main() {
    int n, head;
    printf("Enter no of requests: ");
    scanf("%d",&n);

    int req[n];
    printf("Enter requests: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter head: ");
    scanf("%d", &head);

    printf("Total head movement = %d", sstf(n, head, req));

    return 0;
}