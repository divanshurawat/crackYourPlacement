//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int m=mat.size();
        for(int i=0;i<m;i++){
            int x=accumulate(mat[i].begin(), mat[i].end(), 0);
            if(x == 0) {  // This person knows nobody
                bool isCelebrity = true;
                for(int j = 0; j < m; j++) {
                    if(i != j && mat[j][i] == 0) {  // Check if everyone knows this person
                        isCelebrity = false;
                        break;
                    }
                }
                if(isCelebrity) return i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends