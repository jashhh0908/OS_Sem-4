#include<stdio.h>

void optimal(int pages[], int frames[], int capacity, int n) {
    int i, j, k;
    int hits = 0, faults = 0;
    for(i = 0; i < n; i++) {
        int found = 0;
        //check for hit
        for(j = 0; j < capacity; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                hits++;
                break;
            }
        }
        //check for fault
        if(!found) {
            faults++;
            int empty = -1;
            //check if frames are empty
            for(j = 0; j < capacity; j++) {
                if(frames[j] == -1) {
                    empty = j;
                    break;
                }
            }
            //if empty then directly replace else use optimal algo
            if(empty != -1) {
                frames[empty] = pages[i];
            } else {
                int pos = -1, farthest = i;
                //check next occurence for each frame
                for(j = 0; j < capacity; j++) {
                    //check future pages
                    for(k = i + 1; k < n; k++) {
                        if(frames[j] == pages[k]) {
                            //update if the current frame is further else stop searching further for it
                            if(k > farthest) {
                                farthest = k;
                                pos = j;
                            }
                            break;
                        }
                    }
                    if(k == n) {
                        pos = j;
                        break;
                    }
                }
                frames[pos] = pages[i];
            }
        }
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

    optimal(pages, frames, capacity,n);
}