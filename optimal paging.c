#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10
#define INF 9999

int main() {
    int reference_string[MAX_PAGES] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1};
    int frames[MAX_FRAMES];
    int page_faults = 0;
    int i, j, k, max, index;

    // Initialize frames to -1 (empty)
    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    printf("Reference String: ");
    for (i = 0; i < MAX_PAGES; i++) {
        printf("%d ", reference_string[i]);
    }
    printf("\n");

    printf("\nOptimal Paging Technique Simulation:\n");
    printf("-------------------------------------\n");

    for (i = 0; i < MAX_PAGES; i++) {
        int found = 0;
        // Check if the page is already in a frame
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == reference_string[i]) {
                found = 1;
                break;
            }
        }
        // If page is not in any frame, find the optimal page to replace
        if (!found) {
            page_faults++;
            int furthest = -INF;
            index = -1;
            for (j = 0; j < MAX_FRAMES; j++) {
                int next_occurrence = INF;
                for (k = i + 1; k < MAX_PAGES; k++) {
                    if (frames[j] == reference_string[k]) {
                        next_occurrence = k;
                        break;
                    }
                }
                if (next_occurrence > furthest) {
                    furthest = next_occurrence;
                    index = j;
                }
            }
            frames[index] = reference_string[i];
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

