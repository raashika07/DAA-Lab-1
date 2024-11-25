#include <stdio.h>
int findFloor(int arr[], int n, int x) 
{
    int low = 0, high = n - 1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}
int findCeil(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int main() 
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;
    int floor = findFloor(arr, n, x);
    int ceil = findCeil(arr, n, x);
    printf("Floor of %d is %d\n", x, floor);
    printf("Ceil of %d is %d\n", x, ceil);
    return 0;
}