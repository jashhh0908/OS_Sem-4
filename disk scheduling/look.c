//this is using the actual simulation logic for scan, dont know which to use.
#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int look(int req[], int n, int head, char direction) {
    int pos = -1;
    int i;
    for(i = 0; i < n; i++) {
        if(req[i] > head) {
            pos = i;
            break;
        }
    }

    if(pos == -1) pos = n;
    int current = head, sum = 0;
    if(direction == 'R' || direction == 'r') {
        for(i = pos; i < n; i++) {
            sum += abs(req[i] - current);
            current = req[i];
        }

        for(i = pos - 1; i >= 0; i--) {
            sum += abs(req[i] - current);
            current = req[i];
        }
    } else {
        for(i = pos - 1; i >= 0; i--) {
            sum += abs(req[i] - current);
            current = req[i];
        }

        for(i = pos; i < n; i++) {
            sum += abs(req[i] - current);
            current = req[i];
        }
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

    char direction;
    printf("Enter direction (L - Left | R - Right): ");
    scanf(" %c", &direction);
    
    sort(req, n);

    printf("Total head movement = %d", look(req, n, head, direction));

    return 0;
}