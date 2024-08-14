class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>>q;
        q.push({beginWord,1});
        //set to store all words so that fidnig a word is done with less time complexcity
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int steps= q.front().second;
            q.pop();
            if(word==endWord) return steps;
            
            for(int i=0;i<word.size();i++){
                char org=word[i];
                for(char ch='a' ;ch<='z'; ch++){
                    word[i]=ch;
                    //if word exists int the set
                    if(st.find(word)!=st.end()){
                        //remove word from the set , so it will never encounter again and we did not stuck in a loop
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i]=org;
            }
        }
        return 0;
    }
};