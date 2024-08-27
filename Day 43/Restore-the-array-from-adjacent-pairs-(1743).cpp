class Solution {
public:
    vector<int>ans;
    void dfs(int start, int prev, unordered_map<int, vector<int>> &adj){
        ans.push_back(start);
        for(auto v:adj[start]){
            if(v!=prev) dfs(v, start,adj);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;

        for(auto it:adjacentPairs){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int start=-1;
        for(auto it:adj){
            if(it.second.size()==1) 
            {
                start=it.first;
                break;
            }
        }
        dfs(start, INT_MIN, adj);
        return ans;
    }
};