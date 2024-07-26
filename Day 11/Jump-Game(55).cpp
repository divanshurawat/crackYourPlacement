class Solution {
public:
    int t[10001];
    bool solve(vector<int>&nums, int n, int idx){
        if(idx==n-1) return true;

        if(t[idx]!=-1) return t[idx];
        for(int i=1;i<=nums[idx];i++){
            if(solve(nums, n, idx+i)) return t[idx]= true;
        }
        return t[idx]= false;
    }
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums, n, 0);
    }
};