#include <stdio.h>
int findPeakElement(int arr[], int n) {
    // If array has only one element, it's the peak
    if (n == 1)
        return 0;
    if (arr[0] >= arr[1])
        return 0;
    if (arr[n-1] >= arr[n-2])
        return n-1;
    int low = 1;
    int high = n - 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1])
            return mid;
        if (arr[mid-1] > arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1; 
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    int result = findPeakElement(arr, n);
    if (result != -1)
        printf("\nPeak element is %d at index %d\n", arr[result], result);
    else
        printf("\nNo peak element found\n");
    return 0;
}