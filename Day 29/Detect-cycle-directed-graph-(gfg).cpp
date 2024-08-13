class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int indegree[V]={0};
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        //push all the nodes with indegree zero in the queue
	        if(indegree[i]==0) q.push(i);
	    }
	    
	    int cnt=0;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        cnt++; //count the number of elements in the topo sot array
	        /*node is in your topo sort , so please remove it from the 
	        indegree*/
	        for(auto it:adj[node]){
	            /*decrease the indegree of all the all the adjacent nodes 
	            of the node as the current node will be removed from the 
	            graph*/
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
	    }
	    
	    return cnt==V?false:true;
	    /*if cnt is equal to total number of elements then there is no cylce
	    else there is cycle*/
    }
};