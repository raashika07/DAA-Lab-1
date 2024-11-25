#include <stdio.h>
int findOddOccurrence(int arr[], int n) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        if (low == high)
            return arr[low];
            
        int mid = low + (high - low) / 2;
        if (mid % 2 == 0) {
            if (arr[mid] == arr[mid + 1])
                low = mid + 2;
            else
                high = mid;
        }
        else {
            if (arr[mid] == arr[mid - 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int main() {
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    int result = findOddOccurrence(arr, n);
    if (result != -1)
        printf("\nElement occurring odd number of times: %d\n", result);
    else
        printf("\nNo element occurs odd number of times\n");
    return 0;
}