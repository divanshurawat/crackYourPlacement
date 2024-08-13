class Solution {
  private:
  bool dfs(int node, int parent,int vis[], vector<int>adj[]){
      vis[node]=1;
      for(auto adjacentNode: adj[node]){
          //if node is not visited then visit the node
          if(!vis[adjacentNode]){
              if(dfs(adjacentNode, node, vis, adj)==true) return true;
          }
          /* if adjacent node is not visited and it is also not parent 
          then there is cycle in the path and return true*/
          else if(adjacentNode!=parent) return true;
      }
      return false;
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj)==true) return true;
            }
        }
        return false;
    }
};