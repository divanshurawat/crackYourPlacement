class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int deficit =0;
        long long balance =0;
        int start=0;
        for(int i=0;i<n;i++){
            balance+=gas[i]-cost[i];
            if(balance<0){
                deficit+=balance;
                balance=0;
                start=i+1;
            }
        }
        if(deficit+balance>=0){
            return start;
        }
        else return -1;
    }
};