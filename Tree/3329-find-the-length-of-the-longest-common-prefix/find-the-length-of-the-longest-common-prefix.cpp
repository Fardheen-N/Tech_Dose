class TrieNode {
public:
    TrieNode* links[10];
    bool isLeaf = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(char c : word) {
            if(!temp -> links[c - '0']) {
                temp -> links[c - '0'] = new TrieNode();
            }
            temp = temp -> links[c - '0'];
        }
        temp -> isLeaf = true;
    }
    
    int startsWith(string prefix) {
        TrieNode* temp = root;
        int res = 0;
        for(char c : prefix) {
            if(!temp -> links[c - '0']) break;
            temp = temp -> links[c - '0'];
            res++;
        }
        return res;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie N1;
        for(auto i:arr2){
            string s= to_string(i);
            N1.insert(s);
        }
        int res = 0;
        for(auto i:arr1){
            string s = to_string(i);
            res=max(res,N1.startsWith(s));
        }
        return res;
    }
};
