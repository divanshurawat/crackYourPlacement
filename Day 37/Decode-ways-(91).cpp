class Solution {
public:
    vector<int>dp;
    int solve(int i, string&s, int &n){
        if(i==n) return 1; //one valid split done
        if(s[i]=='0') return 0; //not possible to split

        if(dp[i] !=-1) return dp[i];

        int only_ith_char= solve(i+1,s,n);
        int ith_i_plus_1_char= 0;

        if(i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))
            ith_i_plus_1_char=solve(i+2,s,n);
        
        return dp[i]= only_ith_char +ith_i_plus_1_char;

    }
    int numDecodings(string s) {
        
        int n=s.size();
        dp.resize(n+1, -1);
        return solve(0,s,n);
    }
};