#include <stdio.h>
#include <stdlib.h>
int fcfs(int n, int head, int req[]) {
    int sum = 0;
    int movement;
    for(int i = 0; i < n; i++) {
        movement = req[i] - head;
        sum += abs(movement);
        head = req[i];
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

    printf("Total head movement = %d", fcfs(n, head, req));

    return 0;
}