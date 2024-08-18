class Solution {
public:
    int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    void dfs(int i, int j, vector<vector<int> > &grid, vector<vector<bool> > &visited, int val){
        grid[i][j]=val;
        visited[i][j]=true;
        int n = grid.size();
        for(int k=0; k<4; k++){
            if(i+dir[k][0]>=0 && i+dir[k][0]<n && j+dir[k][1]>=0 && j+dir[k][1]<n && grid[i+dir[k][0]][j+dir[k][1]] && !visited[i+dir[k][0]][j+dir[k][1]]){
                dfs(i+dir[k][0], j+dir[k][1], grid, visited, val);
            }
        }

    }
    int largestIsland(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size();
        vector<vector<bool> > visited(n, vector<bool>(n, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] && !visited[i][j]){
                    dfs(i, j, grid, visited, ++cnt);
                }
            }
        }
        vector<int> freq(cnt+1, 0);
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                freq[grid[i][j]]++;
                if(grid[i][j])ans = max(ans, freq[grid[i][j]]);
            }
        }

        for(int i=0 ; i<n; i++){
            for(int j=0; j<n; j++){
                
                if(grid[i][j]==0){
                    set<int> st;

                    for(int k=0; k<4; k++){
                        if(i+dir[k][0]>=0 && i+dir[k][0]<n && j+dir[k][1]>=0 && j+dir[k][1]<n){
                            if(grid[i+dir[k][0]][j+dir[k][1]]){
                                st.insert(grid[i+dir[k][0]][j+dir[k][1]]);
                            }
                        }
                    }
                    int curr = 1;
                    for (auto it = st.begin(); it != st.end(); it++)curr+=freq[*it];
                    ans = max(ans, curr);
                }
            }
        }

        return ans;
    }
};