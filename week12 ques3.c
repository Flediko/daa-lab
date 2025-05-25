#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

void permute(char *str, int l, int r) {
    if (l == r) {
        printf("%s\n", str);
        return;
    }
    for (int i = l; i <= r; i++) {
        if (i != l && str[i] == str[l]) continue;
        swap(&str[l], &str[i]);
        qsort(str + l + 1, r - l, sizeof(char), compare);
        permute(str, l + 1, r);
    }
}

int main() {
    char str[100];
    scanf("%s", str);
    int n = strlen(str);
    qsort(str, n, sizeof(char), compare);
    permute(str, 0, n - 1);
    return 0;
}
