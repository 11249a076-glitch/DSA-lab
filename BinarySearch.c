//Aim:- To find the element using binary search
#include <stdio.h>

int main() {
    int i, j;
    int low = 0, high, mid;
    int n, key, temp;
    int found = 0; 

    printf("\nEnter how many elements you want to store:\n");
    scanf("%d", &n);

    int a[n];                    // variable-length array (VLA) to store the elements

                                 // Input section: read n elements
    printf("\nEnter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nGiven data:\n");
    for (i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }

                                // Sorting: simple insertion-like sort (or selection-lite)
    for (i = 0; i < n; i++) {
        for (j = 0; j < i + 1; j++) {
            if (a[i] < a[j]) {
                // swap a[i] and a[j]
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\n\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }

                                             // Ask for the key to search in the sorted array
    printf("\n\nEnter the key to search:\n");
    scanf("%d", &key);

                                             // Initialize binary search bounds
    low = 0;
    high = n - 1;

    while (low < high) {
        mid = (low + high) / 2;              // find the middle index

        if (a[mid] == key) {
                                             // If the middle element is the key, we found it
            printf("\nKey found at index: %d", mid + 1);
            found = 1;
            break;
        }

        if (a[mid] < key) {
            // If key is larger than a[mid], search in the right half
            low = mid + 1;
            high = n - 1;  // this resets high every time — could just keep previous high
        } else {
            // If key is smaller than a[mid], search in the left half
            low = 0;        // this resets low every time — could just keep previous low
            high = mid - 1;
        }
    }

    if (found == 0) {
        printf("\nElement not found");
    }

    return 0;
}
