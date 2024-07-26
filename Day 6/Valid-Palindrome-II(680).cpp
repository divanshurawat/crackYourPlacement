class Solution {
public:
    bool validPalindrome(string s) {
        int l=0, r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                int l1=l+1, r1=r, l2=l, r2=r-1;
                while(l1<r1 && s[l1]==s[r1]){
                    l1++;
                    r1--;
                }
                while(l2<r2 && s[l2]==s[r2]){
                    l2++;
                    r2--;
                }
                return l1>=r1 || l2>=r2;
            }
            l++;
            r--;
        }
        return true;
    }
};