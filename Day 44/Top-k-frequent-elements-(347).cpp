class Solution {
public:
    typedef pair<int, int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(auto num:nums) mp[num]++;

        //define the min heap
        priority_queue<p, vector<p>, greater<p>>pq;
        //push elements in the min the heap from map and maintain size of k only

        for(auto it:mp){
            int value=it.first;
            int freq=it.second;

            pq.push({freq, value});
            if(pq.size()>k) pq.pop();//remove element with least frequency

        }
        //result;
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};