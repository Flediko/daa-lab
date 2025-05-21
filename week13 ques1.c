#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char arr[n];
    int freq[256] = {0};
    for (int i = 0; i < n; i++) {
        scanf(" %c", &arr[i]);
        freq[(int)arr[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0)
            printf("%c %d\n", i, freq[i]);
    }
    return 0;
}
