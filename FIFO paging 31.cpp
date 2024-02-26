#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int main() {
    int frames[MAX_FRAMES];
    int pages[MAX_PAGES];
    int pageFaults = 0;
    int nextPageIndex = 0;

    // Initialize frames with -1 indicating an empty frame
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    printf("Enter the page reference string (separated by spaces): ");
    for (int i = 0; i < MAX_PAGES; i++) {
        scanf("%d", &pages[i]);
    }

    // Simulate FIFO paging
    for (int i = 0; i < MAX_PAGES; i++) {
        int page = pages[i];
        int pageFound = 0;

        // Check if page is already in a frame
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                pageFound = 1;
                break;
            }
        }

        // If page is not found in frames, replace the oldest page
        if (!pageFound) {
            frames[nextPageIndex] = page;
            nextPageIndex = (nextPageIndex + 1) % MAX_FRAMES;
            pageFaults++;
        }

        // Display current state of frames after each page reference
        printf("Page reference: %d | Frames: ", page);
        for (int j = 0; j < MAX_FRAMES; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}

