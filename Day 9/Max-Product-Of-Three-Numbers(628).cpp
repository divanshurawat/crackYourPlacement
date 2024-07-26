class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        int ans=1;
        if(nums[n-1]<0 && nums[n-2]<0){
            ans=max((ans*nums[n-1]*nums[n-2]*nums[0]), (ans*nums[0]*nums[1]*nums[2]));
        }
        else ans=ans*nums[0]*nums[1]*nums[2];
        return ans;
    }
};