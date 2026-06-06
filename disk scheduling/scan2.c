//this is a shortcut method using the formula, dont know which to use.
#include <stdio.h>

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

    int arr[n+1];
    for(int i = 0; i < n; i++) {
        arr[i] = req[i];
    }
    arr[n] = head;
    
    for(int i = 0; i < n + 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    int min = arr[0], max = arr[n], sum;
    char direction;
    printf("Enter direction (L - Left | R - Right): ");
    scanf(" %c", &direction);

    if(direction == 'R') {
        sum = (200 - head) + (200 - min);
    } else if(direction == 'L') {
        sum = head + (max - min);
    }
    printf("Total head movement = %d", sum);

    return 0;
}