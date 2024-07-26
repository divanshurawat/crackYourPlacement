class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int cnt=0;
        mp[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0) rem+=k;
            if(mp.find(rem)!=mp.end()){
                cnt+=mp[rem];
                mp[rem]++;
            }
            else{
                mp[rem]=1;
            }
        }
        return cnt;
    }
};