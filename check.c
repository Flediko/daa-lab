#include<stdio.h>

void check(int [], int, int);
void sort(int arr[], int n)
{
    int i, j, m, temp;
    for (i = 0; i < n - 1; i++)
    {
        m = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[m])
            {
                m = j;
            }
        }
        temp = arr[m];
        arr[m] = arr[i];
        arr[i] = temp;
    }
}

void check(int arr[], int n, int k)
{
    int i = 0, j = 1, c = 0;
    while (j < n)
    {
        if (arr[j] - arr[i] == k)
        {
            c++;
            j++;
            i++;
        }
        else if (arr[j] - arr[i] < k)
            j++;
        else
            i++;
    }
    printf("The count is equal to %d\n", c);
}

void main()
{
    int arr[100], l, n, k;
    printf("Enter the number of arrays to be checked: ");
    scanf("%d", &l);
    for (int i = 0; i < l; i++)
    {
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        printf("Enter the array: ");
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }
        sort(arr, n);
        printf("Enter the key: ");
        scanf("%d", &k);
        check(arr, n, k);
    }
}

