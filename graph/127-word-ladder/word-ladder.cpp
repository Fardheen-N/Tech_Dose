class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,bool> word;
        int n = beginWord.size();
        for(auto i:wordList){
            word[i]=1;
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string str = q.front().first;
                int st = q.front().second;
                q.pop();
                for(int i=0;i<n;i++){
                    char ori = str[i];
                   for(char ch='a';ch<='z';ch++){
                       str[i]=ch;
                       if(str == endWord && word[str]==1) return st+1;
                       if(word[str]==1){
                           q.push({str,st+1});
                           word[str]=0;
                       }
                   }
                   str[i]=ori; 
                }
            }
        }
        return 0;
    }
};