//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int>st;
        int n=S.size();
        for(int i=0;i<n;i++){
            if(S[i]=='*'){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(y*x);
            }
            else if(S[i]=='/'){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(y/x);
            }
            else if(S[i]=='+'){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(y+x);
            }
            else if(S[i]=='-'){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(y-x);
            }
            else {
                st.push(S[i]-'0');
            }
        }
        int ans=st.top();
        st.pop();
        return ans;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends