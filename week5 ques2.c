#include <stdio.h> #include <stdlib.h>

void find(int *arr, int key, int n) { int temp; for (int i = 0; i < n - 1; i++) { for (int j = i + 1; j < n; j++) { if (arr[i] > arr[j]) { temp = arr[i]; arr[i] = arr[j]; arr[j] = temp; } } }

int i = 0, j = n - 1, sum;
while (i < j) {
    sum = arr[i] + arr[j];
    if (sum == key) {
        printf("%d %d\n", arr[i], arr[j]);
        return;
    } else if (sum > key) {
        j--;
    } else {
        i++;
    }
}
printf("Element not Found!!!\n");

}

int main() { int T, n, *arr, key; printf("Enter the number of test cases: "); scanf("%d", &T);

for (int i = 0; i < T; i++) {
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    
    printf("Enter the elements: ");
    for (int j = 0; j < n; j++) {
        scanf("%d", &arr[j]);
    }
    
    printf("Enter the key: ");
    scanf("%d", &key);
    
    find(arr, key, n);
    free(arr);
}
return 0;

}

