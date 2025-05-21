#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    if (sum % 2 != 0) {
        printf("no\n");
        return 0;
    }

    int target = sum / 2;
    int dp[target + 1];
    for (int i = 0; i <= target; i++) dp[i] = 0;
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = target; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    if (dp[target]) printf("yes\n");
    else printf("no\n");

    return 0;
}
