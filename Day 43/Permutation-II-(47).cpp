class Solution {
public:
    int n;
    vector<vector<int>> result;

    void solve(vector<int>&nums, int idx){
        if(idx==n){
            result.push_back(nums);
            return;
        }
        unordered_set<int>uniqueSet;
        for(int i=idx;i<n;i++){
            if(uniqueSet.find(nums[i])!=uniqueSet.end()) continue;//do not take the element which is present in the set
            uniqueSet.insert(nums[i]);
            swap(nums[i], nums[idx]);

            solve(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        solve(nums,0);
        return result;

    }
};