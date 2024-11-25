#include <stdio.h>
int MissingSmallElement(int arr[], int low, int high) 
{
    if (low > high) 
    {
        return low; // Return low as it represents the smallest missing element
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == mid) 
    {
        return MissingSmallElement(arr, mid + 1, high);
    } 
    else 
    {
        return MissingSmallElement(arr, low, mid - 1);
    }
}

int main()
{
    int arr[] = {0, 1, 3, 4, 5, 6, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int missingElement = MissingSmallElement(arr, 0, n - 1);
    printf("The missing smallest element is: %d\n", missingElement);
    return 0;
}