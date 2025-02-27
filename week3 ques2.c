#include <stdio.h>

void sort(int a[], int n, int* c, int* s) {
    int min, temp;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            (*c)++;
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            (*s)++;
        }
    }
}

void main() {
    int a[100], n, l, c = 0, s = 0;
    printf("Enter the number of test cases: ");
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        printf("Size of the array: ");
        scanf("%d", &n);
        printf("Enter the array: ");
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &a[j]);
        }
        c = 0;
        s = 0;
        sort(a, n, &c, &s);
        printf("Sorted array: ");
        for (int j=0;j<n;j++)
        {
            printf("%d ", a[j]);
        }
        printf("\nThe number of comparisons are: %d", c);
        printf("\nThe number of swaps are: %d\n", s);
    }
}

