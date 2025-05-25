#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    int weight[n], value[n];
    for (int i = 0; i < n; i++) scanf("%d", &weight[i]);
    for (int i = 0; i < n; i++) scanf("%d", &value[i]);
    int W;
    scanf("%d", &W);
    
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i-1] <= w)
                dp[i][w] = max(value[i-1] + dp[i-1][w - weight[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    printf("Value = %d\n", dp[n][W]);

    int w = W;
    printf("Weights selected :");
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            printf(" %d", weight[i-1]);
            w -= weight[i-1];
        }
    }
    printf("\n");
    return 0;
}
