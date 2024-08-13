class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>>& graph, vector<int>&vis, vector<int>& pathVis, vector<int>&check){
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        //treaverse adjacent nodes
        for(auto it:graph[node]){
            //when node is not visited
            if(!vis[it]){
                if(dfsCheck(it, graph, vis, pathVis, check)) {
                    check[node]=0;
                    return true;
                }
            } 
            /*if node is previosly viisted,
            but it has to on the same path*/
            
            else if(pathVis[it]){
                check[node]=0;
                return true;
            }
        }
        /*there is no cycle , hence it is a safe node, beacuse if there is any 
        cycle then it will break out of function above in return true statements*/
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>vis(V,0);
        vector<int> pathVis(V,0);
        vector<int>check(V,0);
        vector<int>safeNodes;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsCheck(i, graph, vis, pathVis, check) ;
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};