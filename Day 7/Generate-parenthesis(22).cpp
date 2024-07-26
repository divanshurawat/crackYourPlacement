class Solution {
public:
    void solve(string &curr, int n, vector<string> &ans, int open, int close){
        if(curr.length()==2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            solve(curr, n, ans,open+1, close);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            solve(curr, n, ans, open, close+1);
            curr.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        int open=0, close=0;
        string curr="";
        vector<string>ans;
        solve(curr, n, ans, open, close);
        return ans;
    }
};