#include <stdio.h>
#define INF 99999
#define MAX 100

int min(int a, int b) { return a < b ? a : b; }

int shortest(int g[MAX][MAX], int n, int s, int d, int k) {
    int dp[MAX][MAX][MAX];
    for (int e = 0; e <= k; e++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j][e] = (i == j && e == 0) ? 0 : INF;

    for (int e = 1; e <= k; e++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int m = 0; m < n; m++)
                    if (g[i][m] && dp[m][j][e - 1] != INF)
                        dp[i][j][e] = min(dp[i][j][e], g[i][m] + dp[m][j][e - 1]);

    return dp[s][d][k];
}

int main() {
    int n, g[MAX][MAX], s, d, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    scanf("%d %d %d", &s, &d, &k);
    int ans = shortest(g, n, s - 1, d - 1, k);
    if (ans == INF)
        printf("no path of length k is available\n");
    else
        printf("Weight of shortest path from (%d,%d) with %d edges : %d\n", s, d, k, ans);
}
