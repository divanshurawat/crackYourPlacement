class Solution {
public:
    unordered_map<int, int>mp;
    int n;
    int dp[2001][2001];
    bool solve(int ci, int pj, int cs ){ //ci: current index, pj=preious jump
        if(ci==n-1) return true;
        if(dp[ci][pj]!=-1) return dp[ci][pj];
        //for lesser jump
        if(pj-1>0 && mp.find(cs+pj-1)!=mp.end()){
            int x=cs+pj-1;
            if(solve(mp[x], pj-1, x)) return dp[ci][pj]= true;
        }
        //for same jump
        if(pj>0 && mp.find(cs+pj)!=mp.end()){
            int x=cs+pj;
            if(solve(mp[x], pj, x)) return dp[ci][pj]= true;
        }
        //for greater jump
        if(mp.find(cs+pj+1)!=mp.end()){
            int x=cs+pj+1;
            if(solve(mp[x], pj+1, x)) return dp[ci][pj]= true;
        }
        return dp[ci][pj]=false;
    }
    bool canCross(vector<int>& stones) {
        memset(dp, -1, sizeof(dp));
        if(stones[1]!=1) return false;
        n=stones.size();
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        return solve(0,0,0);
    }
};