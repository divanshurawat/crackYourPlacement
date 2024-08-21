class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(int idx, int pre, vector<int>&nums) {
        if(idx == n) return 0;  // Base case should return 0 for LIS length calculation
        if(pre!=-1 && dp[idx][pre]!=-1) return dp[idx][pre];
        int skip = solve(idx + 1, pre, nums);
        int take = 0;
        if(pre == -1 || nums[idx] > nums[pre]) {
            take = 1 + solve(idx + 1, idx, nums);  // Corrected the parameters
        }
        if(pre!=-1) return dp[idx][pre]= max(skip, take);
        return  max(skip, take);
        
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        n = nums.size();
        return solve(0, -1, nums);  // Start with the first index and previous index as -1
    }
};
