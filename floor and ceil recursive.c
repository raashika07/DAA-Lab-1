#include <stdio.h>
int findFloor(int arr[], int low, int high, int x) {
    if (low > high)
        return -1;
    if (x >= arr[high])
        return arr[high];
    if (x < arr[low])
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == x)
        return arr[mid];
    if (mid > 0 && arr[mid-1] <= x && x < arr[mid])
        return arr[mid-1];
    if (x < arr[mid])
        return findFloor(arr, low, mid-1, x);
    return findFloor(arr, mid+1, high, x);
}
int findCeil(int arr[], int low, int high, int x) {
    if (low > high)
        return -1;
    if (x <= arr[low])
        return arr[low];
    if (x > arr[high])
        return -1;
        
    int mid = low + (high - low) / 2;
    if (arr[mid] == x)
        return arr[mid];
    if (mid < high && arr[mid] < x && x <= arr[mid+1])
        return arr[mid+1];
    if (x > arr[mid])
        return findCeil(arr, mid+1, high, x);
    return findCeil(arr, low, mid-1, x);
}

int main() {
    int arr[] = {1, 2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nEnter number to find floor and ceil: ");
    scanf("%d", &x);
    int floor = findFloor(arr, 0, n-1, x);
    int ceil = findCeil(arr, 0, n-1, x);
    if (floor != -1)
        printf("Floor of %d is %d\n", x, floor);
    else
        printf("Floor doesn't exist\n");
    if (ceil != -1)
        printf("Ceil of %d is %d\n", x, ceil);
    else
        printf("Ceil doesn't exist\n");
    return 0;
}