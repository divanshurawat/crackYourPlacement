class Solution {
public:
    vector<vector<int>> result;

     void twoSum(vector<int>&nums, int t, int i, int j){
        while(i<j){
            if(nums[i]+nums[j]> t)
                j--;
            else if(nums[i]+nums[j]<t)
                i++;
            else{
                //remove duplicates from either end
                while(i<j && nums[i]==nums[i+1]) i++;
                while(i<j && nums[j]==nums[j-1]) j--;

                result.push_back({-t, nums[i], nums[j]});

                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return {};

        result.clear();
        sort(nums.begin(), nums.end());

        //fixing one element
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int n1=nums[i];
            int target=-n1;

            twoSum(nums, target, i+1, n-1);
        }
        return result;
    }
};