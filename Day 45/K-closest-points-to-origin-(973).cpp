class Solution {
public:
    typedef pair<double, pair<int, int>>P;
    double distFromOrigin(int i, int j){
        double ans=sqrt(i*i+ j*j);
        return ans;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<P, vector<P>>pq;
        for(auto it:points){
            int i=it[0];
            int j=it[1];
            double x=distFromOrigin(i,j);
            pq.push({x,{i,j}});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            ans.push_back({x, y});
        }
        return ans;
    }
};