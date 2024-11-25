#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x) 
{
    if (high >= low) 
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[low] <= arr[mid]) 
        {
            if (x >= arr[low] && x < arr[mid])
                return binarySearch(arr, low, mid - 1, x);
            else
                return binarySearch(arr, mid + 1, high, x);
        } 
        else 
        {
            if (x > arr[mid] && x <= arr[high])
                return binarySearch(arr, mid + 1, high, x);
            else
                return binarySearch(arr, low, mid - 1, x);
        }
    }
    return -1;
}

int main() 
{
    int arr[] = {5, 6, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("Element is not present in array\n");
    else
        printf("Element is present at index %d\n", result);
    return 0;
}