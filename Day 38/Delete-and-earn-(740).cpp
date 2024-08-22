class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi=*max_element(nums.begin(), nums.end());
        int dp[10005];
        vector<int>freq(10005);

        for(auto it:nums) freq[it]++;
        dp[1]=freq[1];
        dp[2]= max(dp[1], freq[2]*2);
        for(int i=3;i<=maxi;i++){
            dp[i]=max(dp[i-1], dp[i-2]+freq[i]*i);//either previous state or sum of second previous state and curretn state
        }
        return dp[maxi];
    }
};