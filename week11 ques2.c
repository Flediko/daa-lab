#include <stdio.h>

int main() {
    int numCoins, target;
    scanf("%d", &numCoins);
    
    int coins[numCoins];
    for (int i = 0; i < numCoins; i++) {
        scanf("%d", &coins[i]);
    }

    scanf("%d", &target);
    
    int dp[target + 1];
    
    for (int i = 0; i <= target; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;  
    for (int i = 0; i < numCoins; i++) {
        for (int j = coins[i]; j <= target; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    
    printf("%d\n", dp[target]);
    
    return 0;
}
