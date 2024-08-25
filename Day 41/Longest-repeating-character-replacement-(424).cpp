class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0; int r=0; int maxf=0; int maxLen=0;
        int hash[26]={};
        while(r<s.size()){
            hash[s[r]-'A']++;
            maxf=max(maxf, hash[s[r]-'A']);
            if(r-l+1-maxf>k){
                hash[s[l]-'A']--; 
                maxf=0;
                l++;
            }
            if(r-l+1-maxf<=k){
                maxLen=max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};