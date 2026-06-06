#include<stdio.h>

void fifo(int pages[], int frames[], int capacity, int n) {
    int i, j;
    int index = 0, hits = 0, faults = 0;
    for(i = 0; i < n; i++) {
        int found = 0;
        //check for hit
        for(j = 0; j < capacity; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                printf("\n%d hit\n", frames[j]);
                hits++;
                break;
            }
        }
        //check for fault 
        if(!found) {
            faults++;
            printf("\nFault! Replacing %d with %d\n", frames[index], pages[i]);
            frames[index] = pages[i];
            index = (index + 1) % capacity;
        }
        //print current frames
        printf("Frames: [ ");
        for(j = 0; j < capacity; j++) {
            if(frames[j] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[j]);
            }
        }
        printf("]\n");
    }

    printf("\nNo of Hits = %d", hits);
    printf("\nNo of Faults = %d", faults);
    printf("\nHit Ratio = %.2f", (float)hits/n);
    printf("\nFault Ratio = %.2f", (float)faults/n);
}
int main() {
    int n;
    printf("Enter no of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter reference string: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    int capacity;
    printf("Enter frame capacity: ");
    scanf("%d", &capacity);

    int frames[capacity];
    for(int i = 0; i < capacity; i++) {
        frames[i] = -1;
    }

    fifo(pages, frames, capacity,n);
}