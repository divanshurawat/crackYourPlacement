class Solution {
public:
    void solve(int start, int n, int k, vector<int>& temp, vector<vector<int>>& result) {
        if (k == 0) {
            result.push_back(temp);
            return;
        }
        if (start > n || k > n - start + 1) return;

        // take
        temp.push_back(start);
        solve(start + 1, n, k - 1, temp, result);
        
        // not take
        temp.pop_back();
        solve(start + 1, n, k, temp, result);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(1, n, k, temp, result);
        return result;
    }
};
