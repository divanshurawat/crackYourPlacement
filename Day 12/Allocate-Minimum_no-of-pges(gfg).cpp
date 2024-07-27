//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    int countStudents(int arr[], int pages, int n) { 
        int students = 1;
        long long pagesStudent = 0;
        for (int i = 0; i < n; i++) {
            if (pagesStudent + arr[i] <= pages) {
                //add pages to current student
                pagesStudent += arr[i];
            }
            else {
                //add pages to next student
                students++;
                pagesStudent = arr[i];
            }
        }
        return students;
    }
    long long findPages(int n, int arr[], int m) {
        // code here
        if (m > n) return -1;

        int low =0;
        int high =0;
        for(int i=0;i<n;i++){
            low=max(low, arr[i]);
            high+=arr[i];
        }
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int students = countStudents(arr, mid, n);
            if (students > m) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends