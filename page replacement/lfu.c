#include<stdio.h>

void lfu(int pages[], int frames[], int freq[], int capacity, int n) {
    int i, j;
    int hits = 0, faults = 0;
    for(i = 0; i < n; i++) {
        int found = 0;
        //check for hit
        for(j = 0; j < capacity; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                hits++;
                freq[j]++;
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
            //if empty replace directly else use LFU
            if(empty != -1) {
                frames[empty] = pages[i];
                freq[empty] = 1;
            } else {
                //assume first frame as LFU
                int lfu = 0;
                //compare next frame, if its freq is lesser than LFU freq, update LFU  
                for(j = 1; j < capacity; j++) {
                    if(freq[j] < freq[lfu]) {
                        lfu = j;
                    }
                }
                //replace LFU with current page
                frames[lfu] = pages[i];
                //set new page's freq count as 1
                freq[lfu] = 1;
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

    int frames[capacity], freq[capacity];
    for(int i = 0; i < capacity; i++) {
        frames[i] = -1;
        freq[i] = -1;
    }

    lfu(pages, frames, freq, capacity,n);
}