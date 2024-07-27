class Solution {
public:
    int countK(vector<int>nums, int maxi, int n){
        int x=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=maxi){
                sum+=nums[i];
            }
            else{
                x++;
                sum=nums[i];
            }
        }
        return x;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        
        int low=0;
        int high=0;
        for(int i=0;i<n;i++){
            low=max(low, nums[i]);
            high+=nums[i];
        }
        while(low<=high){
            int mid=(low+high)/2;
            int x=countK(nums, mid, n);
            if(x>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};