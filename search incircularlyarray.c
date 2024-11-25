#include <stdio.h>
int searchInCircularArray(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[left] <= arr[mid]) {
            if (target >= arr[left] && target < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        else {
            if (target > arr[mid] && target <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1; 
}

int main() {
    int arr[] = {8, 9, 10, 1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int test_values[] = {3, 8, 10, 6, 11};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);
    
    for(int i = 0; i < num_tests; i++) {
        int target = test_values[i];
        int result = searchInCircularArray(arr, n, target);
        
        if(result != -1) {
            printf("Element %d found at index %d\n", target, result);
        } else {
            printf("Element %d not found in the array\n", target);
        }
    }
    
    return 0;
}