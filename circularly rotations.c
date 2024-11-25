#include <stdio.h>

int findMin(int arr[], int low, int high) {
    if (high < low)
        return arr[low];

    if (high == low)
        return arr[low];

    int mid = low + (high - low) / 2;

    if (mid < high && arr[mid] > arr[mid + 1])
        return mid + 1;

    if (mid > low && arr[mid] < arr[mid - 1])
        return mid;

    if (arr[low] <= arr[mid])
        return findMin(arr, mid + 1, high);

    return findMin(arr, low, mid - 1);
}

int main() {
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int minIndex = findMin(arr, 0, n - 1);
    int rotations = minIndex;
    printf("Number of rotations: %d\n", rotations);
    return 0;
}