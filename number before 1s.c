#include <stdio.h>
int countOnes(int arr[], int n) 
{
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == 1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return n - low;
}
int main() {
    int arr[] = {0, 0, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = countOnes(arr, n);
    printf("Number of 1s: %d\n", count);
    return 0;
}