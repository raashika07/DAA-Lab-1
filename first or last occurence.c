#include <stdio.h>

int findFirstOccur(int arr[], int n, int x) 
{
    int low = 0, high = n - 1;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) 
        {
            if (mid == 0 || arr[mid - 1] != x)
                return mid;
            else
                high = mid - 1;
        } 
        else if (arr[mid] < x) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }
    return -1;
}

int findLastOccur(int arr[], int n, int x) 
{
    int low = 0, high = n - 1;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) 
        {
            if (mid == n - 1 || arr[mid + 1] != x)
                return mid;
            else
                low = mid + 1;
        } 
        else if (arr[mid] < x) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main() 
{
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int firstOccurrence = findFirstOccur(arr, n, x);
    int lastOccurrence = findLastOccur(arr, n, x);
    if (firstOccurrence != -1) 
    {
        printf("First occurrence of %d is at index %d\n", x, firstOccurrence);
    } 
    else 
    {
        printf("Element %d is not present in the array\n", x);
    }

    if (lastOccurrence != -1)
    {
        printf("Last occurrence of %d is at index %d\n", x, lastOccurrence);
    } 
    else 
    {
        printf("Element %d is not present in the array\n", x);
    }
    return 0;
}