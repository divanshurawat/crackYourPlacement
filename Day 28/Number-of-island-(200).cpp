class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid ){
        vis[row][col]=1;
        queue<pair<int, int>>q;
        q.push({row, col});
        int n=grid.size();
        int m=grid[0].size();
        
        while(!q.empty()){
            int row= q.front().first;
            int col=q.front().second;
            q.pop();
            
            //traverse in the neighours and marsk them if its a land
            //upper
            if(row-1>=0 && grid[row-1][col]=='1' && !vis[row-1][col]){
                vis[row-1][col]=1;
                q.push({row-1, col});
            }
            //down
            if(row+1<n && grid[row+1][col]=='1' && !vis[row+1][col]){
                vis[row+1][col]=1;
                q.push({row+1, col});
            }
            //left
            if(col-1>=0 && grid[row][col-1]=='1' && !vis[row][col-1]){
                vis[row][col-1]=1;
                q.push({row, col-1});
            }
            //right
            if(col+1<m && grid[row][col+1]=='1' && !vis[row][col+1]){
                vis[row][col+1]=1;
                q.push({row, col+1});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;