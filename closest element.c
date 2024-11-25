#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int findCrossOver(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    if (x >= arr[high])
        return high;
    if (x < arr[low])
        return low;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x && arr[mid + 1] > x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
void printKClosest(int arr[], int n, int k, int x) {
    int left = findCrossOver(arr, n, x);
    int right = left + 1;
    if (arr[left] == x)
        left--;
        
    int count = 0;
    while (left >= 0 && right < n && count < k) {
        if (abs(arr[left] - x) <= abs(arr[right] - x)) {
            printf("%d ", arr[left]);
            left--;
        }
        else {
            printf("%d ", arr[right]);
            right++;
        }
        count++;
    }
    while (count < k && left >= 0) {
        printf("%d ", arr[left]);
        left--;
        count++;
    }
    while (count < k && right < n) {
        printf("%d ", arr[right]);
        right++;
        count++;
    }
}
int main() {
    int arr[] = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k, x;
    printf("Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nEnter value x: ");
    scanf("%d", &x);
    printf("Enter number of closest elements (k): ");
    scanf("%d", &k);
    if (k > n) {
        printf("k cannot be greater than array size\n");
        return 1;
    }
    printf("%d closest elements to %d are: ", k, x);
    printKClosest(arr, n, k, x);
    printf("\n");
    return 0;
}