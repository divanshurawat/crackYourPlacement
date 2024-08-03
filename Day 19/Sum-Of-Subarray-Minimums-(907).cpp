class Solution {
public:
    vector<int> getNSL(vector<int>&arr, int n){
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                ans[i]=-1;
            }else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                ans[i]=st.empty()?-1: st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> getNSR(vector<int>&arr, int n){
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans[i]=n;
            }else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                ans[i]=st.empty()?n: st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> NSL= getNSL(arr, n);
        vector<int> NSR= getNSR(arr, n);
        long long sum=0;
        int M=1e9+7;
        for(int i=0;i<n;i++){
            long long ls=i-NSL[i]; //left me kitne elemnets honge
            long long rs= NSR[i]-i; //rigth me kitne elements honge

            long long totalWays=ls*rs; //total subarray jine mininum arr[i] hoga
            long long totalSum= arr[i]*totalWays;
            sum=(sum+totalSum)%M;
        }
        return sum;
    }
}; 