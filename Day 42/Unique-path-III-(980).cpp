class Solution {
public:
    int m, n;
    int ans;
    int nonObstacles;

    vector<vector<int>>directions{{1, 0}, {-1,0}, {0,1}, {0, -1}};
    void backTrack(vector<vector<int>>& grid, int cnt, int i, int j){
        if(i<0 || i>=m ||j <0 ||j>=n ||grid[i][j]==-1) return;

        if(grid[i][j]==2){
            if(cnt==nonObstacles) ans++;

            return;
        }

        grid[i][j]=-1;
        for(auto dir:directions){
            int newi=i+dir[0];
            int newj=j+dir[1];

            backTrack(grid, cnt+1, newi, newj);
        }
        grid[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        ans=0;
        nonObstacles=0;
        int start_x=0, start_y=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) nonObstacles++;

                if(grid[i][j]==1){
                    start_x=i;
                    start_y=j;
                }
            }
        }
        nonObstacles+=1;
        int cnt=0;
        
        backTrack(grid, cnt, start_x, start_y);
        return ans;
    }
};