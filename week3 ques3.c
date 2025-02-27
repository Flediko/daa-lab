#include <stdio.h>

void sort(int arr[], int l, int r) {
    if (l >= r)
        return;
    int p = arr[r], i = l, j = r - 1;
    while (i <= j) {
        while (i <= j && arr[i] < p)
            i++;
        while (i <= j && arr[j] > p)
            j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i++] = arr[j];
            arr[j--] = temp;
        }
    }
    arr[r] = arr[i];
    arr[i] = p;
    sort(arr, l, i - 1);
    sort(arr, i + 1, r);
}

void dup(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            printf("Yes, there is a Duplicate element\n");
            return;
        }
    }
    printf("No duplicate element was found\n");
}

int main() {
    int a[100], n, l;
    printf("Enter the number of test cases: ");
    scanf("%d", &l);
    for (int i = 0; i < l; i++) 
    {
        printf("Size of the array: ");
        scanf("%d", &n);
        printf("Enter the array: ");
        for (int j=0;j<n;j++) 
        {
            scanf("%d", &a[j]);
        }
        sort(a,0,n-1);
        printf("Sorted array: ");
        for (int j=0;j<n;j++) 
        {
            printf("%d ", a[j]);
        }
        printf("\n");
        dup(a, n);
    }
    return 0;
}

