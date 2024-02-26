#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

int main() {
    int reference_string[MAX_PAGES] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};
    int frames[MAX_FRAMES];
    int page_faults = 0;
    int i, j, k, min, found;

    // Initialize frames to -1 (empty)
    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    printf("Reference String: ");
    for (i = 0; i < MAX_PAGES; i++) {
        printf("%d ", reference_string[i]);
    }
    printf("\n");

    printf("\nLRU Paging Technique Simulation:\n");
    printf("--------------------------------\n");

    for (i = 0; i < MAX_PAGES; i++) {
        found = 0;
        // Check if the page is already in a frame
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == reference_string[i]) {
                found = 1;
                break;
            }
        }
        // If page is not in any frame, find the least recently used frame
        if (!found) {
            page_faults++;
            min = i;
            for (j = 0; j < MAX_FRAMES; j++) {
                for (k = i - 1; k >= 0; k--) {
                    if (frames[j] == reference_string[k]) {
                        if (k < min) {
                            min = k;
                            found = j;
                        }
                        break;
                    }
                }
            }
            frames[found] = reference_string[i];
        }

        // Display current frame status
        printf("\nPage %d: ", reference_string[i]);
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == -1)
                printf("X ");
            else
                printf("%d ", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults: %d\n", page_faults);

    return 0;
}

