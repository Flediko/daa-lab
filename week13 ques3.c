#include <stdio.h>

#define MAX 10000

typedef struct {
    int a, b;
} Pair;

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    Pair map[MAX * MAX] = {{-1, -1}};
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int prod = arr[i] * arr[j];
            if (map[prod].a == -1) {
                map[prod].a = arr[i];
                map[prod].b = arr[j];
            } else {
                if ((arr[i] != map[prod].a && arr[i] != map[prod].b) &&
                    (arr[j] != map[prod].a && arr[j] != map[prod].b)) {
                    printf("%d %d\n", map[prod].a, map[prod].b);
                    printf("%d %d\n", arr[i], arr[j]);
                    return 0;
                }
            }
        }
    }
    printf("No such pairs found.\n");
    return 0;
}
