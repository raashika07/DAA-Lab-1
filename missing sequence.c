#include <stdio.h>

// Function to find the missing term in the arithmetic progression
int findMissingTerm(int arr[], int n) {
    int low = 0;
    int high = n - 1;
    int d = (arr[n - 1] - arr[0]) / n; // Common difference

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int expected = arr[0] + mid * d; // Calculate the expected value at position mid

        if (arr[mid] == expected) {
            // If the current term matches the expected term, move to the right
            low = mid + 1;
        } else {
            // If the current term doesn't match, check if the missing term is at mid
            if (mid > 0 && arr[mid - 1] == arr[0] + (mid - 1) * d)
                return expected;
            // Otherwise, move to the left
            high = mid - 1;
        }
    }

    return -1; // Return -1 if no missing term is found
}

int main() {
    int arr[] = {2, 4, 8, 10, 12, 14}; // Example sequence
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int result = findMissingTerm(arr, n);

    if (result != -1)
        printf("\nMissing term in the sequence is: %d\n", result);
    else
        printf("\nNo missing term found\n");

    return 0;
}
