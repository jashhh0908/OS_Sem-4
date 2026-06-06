#include<stdio.h>

void lru(int pages[], int frames[], int recent[], int capacity, int n) {
    int i, j;
    int hits = 0, faults = 0;
    for(i = 0; i < n; i++) {
        int found = 0;
        //check for hit
        for(j = 0; j < capacity; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                hits++;
                recent[j] = i;
                break; 
            }
        }
        //check for fault
        if(!found) {
            faults++;
            int empty = -1;
            //checkf if any empty frame
            for(j = 0; j < capacity; j++) {
                if(frames[j] == -1) {
                    empty = j;
                    break;
                }
            }
            //if empty replace directly else use LRU
            if(empty != -1) {
                frames[empty] = pages[i];
                recent[empty] = i;
            } else {
                //assume first frame as LRU
                int lru = 0;
                //compare next frame, if its recent is lesser than LRU recent
                //it means it was used earlier, update LRU  
                for(j = 1; j < capacity; j++) {
                    if(recent[j] < recent[lru]) {
                        lru = j;
                    }
                }
                //replace LRU with current page
                frames[lru] = pages[i];
                //update current pages' LRU as the current index
                recent[lru] = i;
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

    int frames[capacity], recent[capacity];
    for(int i = 0; i < capacity; i++) {
        frames[i] = -1;
        recent[i] = -1;
    }

    lru(pages, frames, recent, capacity,n);
}