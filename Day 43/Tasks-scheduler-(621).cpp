class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26,0);

        for(auto ch:tasks) mp[ch-'A']++;

        sort(mp.begin(), mp.end());

        int maxF=mp[25];
        int gaddhe=maxF-1;
        int idle=n*gaddhe;

        for(int i=24;i>=0;i--){
            idle-=min(mp[i], gaddhe);
        }
        if(idle>0) return (tasks.size()+idle);
        return tasks.size();
    }
};