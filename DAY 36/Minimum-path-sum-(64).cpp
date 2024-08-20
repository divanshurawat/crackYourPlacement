class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>& grid,int i, int j, int m, int n){
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        if(i==m-1){// in last row, can go onlhy to right
            return dp[i][j]= grid[i][j]+solve(grid, i,j+1, m, n);
        }
        else if(j==n-1){//int last column, can go only down
            return dp[i][j]= grid[i][j]+solve(grid, i+1, j, m, n);
        }
        else{
            return dp[i][j]= grid[i][j]+ min(solve(grid, i+1, j, m,n), solve(grid, i, j+1,m,n));
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int m=grid.size();
        int n=grid[0].size();
        int i=0, j=0;
        return solve(grid, i, j, m,n);
    }
};