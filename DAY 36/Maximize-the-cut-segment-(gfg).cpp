class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // DP array to store the maximum number of cuts for each length
        int dp[n + 1];
        
        // Initialize the DP array with -1 (indicating impossible lengths)
        for (int i = 0; i <= n; i++)
            dp[i] = -1;
        
        // Base case: If the length of the rod is 0, no cuts can be made
        dp[0] = 0;
        
        // Iterate over each length of the rod
        for (int i = 1; i <= n; i++) {
            // If a cut of length x can be made
            if (i >= x && dp[i - x] != -1)
                dp[i] = max(dp[i], dp[i - x] + 1);
            // If a cut of length y can be made
            if (i >= y && dp[i - y] != -1)
                dp[i] = max(dp[i], dp[i - y] + 1);
            // If a cut of length z can be made
            if (i >= z && dp[i - z] != -1)
                dp[i] = max(dp[i], dp[i - z] + 1);
        }
        
        // If dp[n] is -1, it means it's not possible to make the exact length, otherwise return dp[n]
        return dp[n] == -1 ? 0 : dp[n];
    }
};