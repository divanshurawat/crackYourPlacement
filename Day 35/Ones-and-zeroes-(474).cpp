class Solution {
public:
    vector<vector<vector<int>>>dp;
    int findMaxForm(vector<string>& strs, int m, int n) {
          
          dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));
           return findmax(strs,m,n,0);
        
        
    }
    
     int findmax (vector<string>& strs, int m, int n,int index)
     {
         if(index==strs.size())return 0;
         if(dp[m][n][index]!=-1)return dp[m][n][index];
         int countzeroes = count(strs[index].begin(),strs[index].end(),'0');
         int countones = strs[index].size()-countzeroes;
         
         if(m-countzeroes>=0 && n-countones>=0)
         return dp[m][n][index]= max(1+findmax(strs,m-countzeroes,n-countones,index+1),
         findmax(strs,m,n,index+1));
         
         return dp[m][n][index]=findmax(strs,m,n,index+1);
     }
};