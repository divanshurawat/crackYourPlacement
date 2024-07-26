class Solution {
public:
    int c = 0;
    int revPairs(vector<int> &a, vector<int> &b){
        int count = 0;
        int i=0; // a
        int j=0; // b
        while(i<a.size() && j<b.size()){
            long long int bruh = b[j];
            if(a[i]>2*bruh){
                count += a.size()-i;
                j++;
            }
            else{ // a[i]<=b[j];
                i++;
            }
        }
        return count;
    }
    void merge(vector<int> &a, vector<int> &b, vector<int> &res){
        int i=0, j=0, k=0;
        while(i<a.size()&&j<b.size()){
            if(a[i]<=b[j]) res[k++] = a[i++];
            else res[k++] = b[j++];
        }
        if(i==a.size()) while(j<b.size()) res[k++] = b[j++];
        else if(j==b.size()) while(i<a.size()) res[k++] = a[i++];
    }
    void mergeSort(vector<int> &v){
        int n = v.size();
        if(n==1) return;
        int n1 = n/2, n2 = n - n/2;
        vector<int> a(n1), b(n2);
        // copy paste
        for(int i=0; i<n1; i++) a[i] = v[i];
        for(int i=0; i<n2; i++) b[i] = v[i+n1];
        // magic
        mergeSort(a);
        mergeSort(b);
        // count reverse pairs
        c += revPairs(a,b);
        // merge
        merge(a,b,v);
        a.clear(); b.clear();
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums);
        return c;
    }
};