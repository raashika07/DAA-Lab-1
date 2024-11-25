#include <stdio.h>
int findFirst(int arr[], int low, int high, int x) {
    if (low > high)
        return -1;
        
    int mid = low + (high - low) / 2;
    
    if ((mid == 0 || x > arr[mid-1]) && arr[mid] == x)
        return mid;
    else if (x > arr[mid])
        return findFirst(arr, mid+1, high, x);
    else
        return findFirst(arr, low, mid-1, x);
}
int findLast(int arr[], int low, int high, int x) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if ((mid == high || x < arr[mid+1]) && arr[mid] == x)
        return mid;
    else if (x < arr[mid])
        return findLast(arr, low, mid-1, x);
    else
        return findLast(arr, mid+1, high, x);
}
void findFrequency(int arr[], int n) {
    int i = 0;
    while (i < n) {
        int first = findFirst(arr, 0, n-1, arr[i]);
        int last = findLast(arr, 0, n-1, arr[i]);
        
        if (first != -1) {
            printf("Element %d occurs %d times\n", 
                   arr[i], last - first + 1);
            i = last + 1;
        } else {
            i++;
        }
    }
}
int main() {
    int arr[] = {1, 1, 2, 2, 2, 2, 3, 4, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nFrequency Count:\n");
    
    findFrequency(arr, n);
    
    return 0;
}