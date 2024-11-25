#include <stdio.h>
int searchNearlySorted(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (mid > low && arr[mid - 1] == key)
            return mid - 1;
        if (mid < high && arr[mid + 1] == key)
            return mid + 1;
        if (key < arr[mid])
            high = mid - 2; 
        else
            low = mid + 2;  
    }
    return -1; 
}
int main() {
    int arr[] = {2, 1, 3, 5, 4, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Nearly Sorted Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nEnter element to search: ");
    scanf("%d", &key);
    int result = searchNearlySorted(arr, n, key);
    if (result != -1)
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found in the array\n", key);
    return 0;
}