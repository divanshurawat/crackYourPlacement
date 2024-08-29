class Solution {
public:
    typedef pair<int, char>P;
    string reorganizeString(string s) {
        int n=s.size();

        vector<int>cnt(26,0);
        for(char &ch:s){
            cnt[ch-'a']++;
            if(cnt[ch-'a']> (n+1)/2) return "";
        }
        //max-heap
        priority_queue<P, vector<P>>pq;
         
        for(char ch='a'; ch<='z'; ch++){
            if(cnt[ch-'a']>0){
                pq.push({cnt[ch-'a'], ch});
            }
        }

        string result="";
        while(pq.size()>=2){
            //we have to deal with the characters with max frequency
            auto P1=pq.top();
            pq.pop();
            auto P2=pq.top();
            pq.pop();

            result.push_back(P1.second);
            P1.first--;
            result.push_back(P2.second);
            P2.first--;

            if(P1.first>0) pq.push(P1);
            if(P2.first>0) pq.push(P2);
        }

        if(!pq.empty()){
            result.push_back(pq.top().second);
        }
        return result;
    }
};