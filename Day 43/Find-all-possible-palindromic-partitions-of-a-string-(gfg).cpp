class Solution {
  public:
    void func(int ind, string s, vector<string> &path, vector<vector<string>> &res){
        if(ind== s.size()){
            res.push_back(path);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s, ind, i)){
                path.push_back(s.substr(ind, i-ind+1));
                func(i+1, s, path, res);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end ){
        while(start<=end){
            if(s[start++]!=s[end--])
            return false;
        }
        return true;
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>> res;
        vector<string> path;
        func(0,S,path,res);
        return res;
    }
};