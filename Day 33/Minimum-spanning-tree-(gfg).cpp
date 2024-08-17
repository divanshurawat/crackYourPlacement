class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>>pq;
        
        vector<int>vis(V,0);
        //pq {w, node}
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            
            if(vis[node]==1) continue;
            //add node to the MST
            vis[node]=1;
            sum+=wt;
            
            for(auto it:adj[node]){
                int adjNode=it[0];
                int edW=it[1];
                if(!vis[adjNode]){
                    pq.push({edW, adjNode});// do not make the node visites
                }
            }
        }
        return sum;
    }
};