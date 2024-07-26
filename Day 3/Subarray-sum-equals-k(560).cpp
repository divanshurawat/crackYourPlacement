class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0, prefSum=0;
        unordered_map<int, int>freq;
        freq[0]=1;
        for(auto el:nums){
            prefSum+=el;
            if(freq.find(prefSum-k)!=freq.end())
                ans+=freq[prefSum-k];
            freq[prefSum]++;
        }
        return ans;
    }
};