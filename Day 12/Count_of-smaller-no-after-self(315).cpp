class Solution {
public:
    void merge(vector<int>&ans,vector<pair<int, int>>&numsPair, int left, int mid, int right){
        vector<pair<int, int>>temp(right-left+1);
        int i=left, j=mid+1;
        int k=0;

        while(i<=mid && j<=right){
            if(numsPair[i].first<=numsPair[j].first){
                temp[k++]=numsPair[j++];
            }
            else{
                ans[numsPair[i].second]+=right-j+1;
                temp[k++]=numsPair[i++];
            }
        }
        while(i<=mid) temp[k++]=numsPair[i++];
        while(j<=right) temp[k++]=numsPair[j++];
        for(int i=left;i<=right;i++) numsPair[i]=temp[i-left];

    }
    void mergeSort(vector<int>&ans,vector<pair<int, int>>&numsPair, int left, int right){
        if(left<right){
            int mid=left+(right-left)/2;
            mergeSort(ans, numsPair, left, mid);
            mergeSort(ans, numsPair, mid+1, right);
            merge(ans, numsPair, left, mid, right);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int, int>>numsPair;
        for(int i=0;i<n;i++){
            numsPair.push_back({nums[i],i});
        }
        vector<int> ans(n,0);
        mergeSort(ans, numsPair, 0, n-1);
        return ans;
    }
};