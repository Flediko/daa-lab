#include<stdio.h>

void sort(int arr[], int n) 
{
    int i, j, temp, com = 0, shift = 0;
    for (i = 1; i < n; i++) 
    {
        j = i - 1;
        temp = arr[i];
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
            shift++;
            com++;
        }
        arr[j + 1] = temp;
    }

    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\ncomparisons=%d\nShifts=%d", com, shift);
}

void main() {
    int arr[100], l, n, k;
    printf("Enter the number of arrays to be checked: ");
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        printf("Enter the array: ");
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        sort(arr, n);
    }
}
