//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        if (s.size() < p.size()) return "-1";
        
        vector<int> map(128, 0);
        int count = p.length();
        int start = 0, minStart = 0, minLen = INT_MAX;
        
        for (char c : p) map[c]++;
        
        for (int end = 0; end < s.length(); end++) {
            if (map[s[end]]-- > 0) count--;
            
            while (count == 0) {
                if (end - start + 1 < minLen) {
                    minStart = start;
                    minLen = end - start + 1;
                }
                
                if (map[s[start++]]++ == 0) count++;
            }
        }
        
        return minLen == INT_MAX ? "-1" : s.substr(minStart, minLen);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends