class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        int i = 0;

        for(; i < n - 1; i++) {
            if(heights[i + 1] <= heights[i]) continue;

            int diff = heights[i + 1] - heights[i];

            if(bricks >= diff) {
                bricks -= diff;
                pq.push(diff);
            } 
            else if(ladders > 0) {
                if(!pq.empty() && pq.top() > diff) {
                    int maxB = pq.top();
                    pq.pop();
                    bricks += maxB;
                    bricks -= diff;
                    pq.push(diff);
                }
                // Use the ladder here (either after replacing bricks or directly)
                ladders--;
            } 
            else {
                break;
            }
        }
        return i;
    }
};
