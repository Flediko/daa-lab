#include <stdio.h> #include <stdlib.h>

void same(int *arr, int m, int *arr2, int n) { int i = 0, j = 0;

while (i < m && j < n) {
    if (arr[i] == arr2[j]) {
        printf("%d ", arr[i]);
        i++, j++;
    } else if (arr[i] > arr2[j]) {
        j++;
    } else {
        i++;
    }
}
printf("\n");

}

int main() { int T, m, n, *arr, *arr1; printf("Enter the number of test cases: "); scanf("%d", &T);

while (T--) {
    printf("Enter the size of first array: ");
    scanf("%d", &m);
    arr = (int *)malloc(m * sizeof(int));
    
    printf("Enter the numbers: ");
    for (int j = 0; j < m; j++) {
        scanf("%d", &arr[j]);
    }
    
    printf("Enter the size of second array: ");
    scanf("%d", &n);
    arr1 = (int *)malloc(n * sizeof(int));
    
    printf("Enter the numbers: ");
    for (int j = 0; j < n; j++) {
        scanf("%d", &arr1[j]);
    }
    
    same(arr, m, arr1, n);
    
    free(arr);
    free(arr1);
}
return 0;

}

