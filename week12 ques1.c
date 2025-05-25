#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char s1[100], s2[100];
    scanf("%s", s1);
    scanf("%s", s2);
    
    int m = strlen(s1), n = strlen(s2);
    int dp[m+1][n+1];
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int index = dp[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs[index - 1] = s1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    printf("%s %d\n", lcs, dp[m][n]);
    return 0;
}
