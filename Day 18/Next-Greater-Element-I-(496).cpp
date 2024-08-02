class Solution {
public:
    int findGreater(int x,int j, vector<int>&v){
        for(int i=j+1;i<v.size();i++){
            if(v[i]>x) return v[i];
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans;
        unordered_map<int , int>mp;
        for(int i=0;i<m;i++){
            mp[nums2[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(mp.find(nums1[i])!=mp.end()){
                int j=mp[nums1[i]];
                int x=findGreater(nums1[i], j, nums2);
                ans.push_back(x);
            }
        }
        return ans;
    }
};