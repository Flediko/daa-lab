#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to find majority element using Boyer-Moore
int findMajorityElement(int arr[], int n) {
    int count = 0, candidate = -1;

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        }
        else if (arr[i] == candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    // Verify candidate
    count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == candidate)
            count++;

    if (count > n / 2)
        return 1; // Yes
    else
        return 0; // No
}

// Function to find median
float findMedian(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    if (n % 2 == 0)
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    else
        return arr[n/2];
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (findMajorityElement(arr, n))
        printf("yes\n");
    else
        printf("no\n");

    printf("%.1f\n", findMedian(arr, n));

    return 0;
}
