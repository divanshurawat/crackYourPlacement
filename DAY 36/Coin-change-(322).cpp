class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int m = coins.size();
        int n = amount + 1;
        
        // Initialize dp array with INT_MAX
        vector<vector<int>> dp(m + 1, vector<int>(n, INT_MAX));
        
        // Base case: 0 amount requires 0 coins
        for(int i = 0; i <= m; i++){
            dp[i][0] = 0;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j < n; j++){
                if(coins[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                } else {
                    if(dp[i][j - coins[i-1]] != INT_MAX){
                        dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - coins[i-1]]);
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }

        int result = dp[m][amount];
        return result == INT_MAX ? -1 : result;
    }
};
