#include <stdio.h>
#include <stdlib.h>

int checkDuplicate(int arr[], int n, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= i + k && j < n; j++) {
            if (arr[i] == arr[j])
                return 1;
        }
    }
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        int k;
        scanf("%d", &k);
        if (checkDuplicate(arr, n, k))
            printf("Duplicate present in window %d.\n", k);
        else
            printf("Duplicate not present in window %d.\n", k);
    }
    return 0;
}
