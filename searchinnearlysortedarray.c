#include <stdio.h>
int searchInNearlySortedArray(int arr[], int n, int x) 
{
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (mid - 1 >= low && arr[mid - 1] == x) 
        {
            return mid - 1;
        }
        if (mid + 1 <= high && arr[mid + 1] == x) 
        {
            return mid + 1;
        }
        if (arr[mid] < x) 
        {
            low = mid + 2; 
        } 
        else 
        {
            high = mid - 2; 
        }
    }
    return -1; 
}

int main() {
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    int result = searchInNearlySortedArray(arr, n, x);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found.\n");
    }
    return 0;
}