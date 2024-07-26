class Solution {
public:
    string reverseWords(string s) {
        string token="";
        stringstream ss(s);
        stack<string>st;
        while(getline(ss, token, ' ')){
            if(!token.empty())
            st.push(token);
        }
        string ans="";
        while (!st.empty()) {
        ans += st.top();
        st.pop();
        if (!st.empty()) {
            ans += " ";
        }
    }
        return ans;
    }
};