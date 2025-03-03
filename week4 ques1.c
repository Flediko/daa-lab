#include <stdio.h>

void sort(int arr[], int l, int r, int *c, int *s) 
{
    if (l >= r)
        return;

    int p = arr[r], i = l, j = r - 1;
    while (i <= j) {
        while (i <= j && arr[i] < p) {
            i++;
            (*c)++;
        }
        while (i <= j && arr[j] > p) {
            j--;
            (*c)++;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i++] = arr[j];
            arr[j--] = temp;
            (*s) += 2;
        }
    }

    arr[r] = arr[i];
    arr[i] = p;
    (*s)++;

    sort(arr, l, i - 1, c, s);
    sort(arr, i + 1, r, c, s);
}

int main() {
    int a[100], n, l, c = 0, s = 0;

    printf("Enter the number of test cases: ");
    scanf("%d", &l);

    for (int i = 0; i < l; i++) 
    {
        printf("Size of the array: ");
        scanf("%d", &n);
        printf("Enter the array: ");
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &a[j]);
        }

        sort(a, 0, n - 1, &c, &s);

        printf("Sorted array: ");
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", a[j]);
        }
        printf("\n");
        printf("The Comparisons: %d\n", c);
        printf("The Swaps: %d\n", s);
    }
    return 0;
}
