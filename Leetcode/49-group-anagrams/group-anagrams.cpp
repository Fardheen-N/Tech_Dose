class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mapi;
        vector<vector<string>> res;
        for(int i=0;i<strs.size();i++){
           string temp = strs[i];
           sort(temp.begin(),temp.end());
           mapi[temp].push_back(strs[i]); 
        }
       
        for(auto i:mapi){
            res.push_back(i.second);
        }
        return res;
    }
};