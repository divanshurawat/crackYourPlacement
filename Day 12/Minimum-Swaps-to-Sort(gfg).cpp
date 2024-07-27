//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size(),ans=0;
	    unordered_map<int, int>mp;
	    vector<int> temp;
	    
	    for(auto it:nums){
	        temp.push_back(it);
	    }
	    sort(temp.begin(), temp.end());
	    for(int i=0;i<n;i++){
	        mp[temp[i]]=i;
	    }
	    int i=0;
	    while(i<n){
	        if(mp[nums[i]]==i){
	            i++;
	        }
	        else{
	            swap(nums[i],nums[mp[nums[i]]]);
	            ans++;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends