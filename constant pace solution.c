#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
void findPairsWithDiffK(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compare);
    int i = 0;
    int j = 1;
    while (i < n && j < n) {
        if (i != j && arr[j] - arr[i] == k) {
            printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
            i++;
            j++;
        }
        else if (arr[j] - arr[i] < k)
            j++;
        else
            i++;
    }
}
int main() {
    int arr[] = {1, 5, 2, 2, 2, 5, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    printf("Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nEnter difference k: ");
    scanf("%d", &k);
    printf("\nPairs with difference %d:\n", k);
    findPairsWithDiffK(arr, n, k);
    return 0;
}