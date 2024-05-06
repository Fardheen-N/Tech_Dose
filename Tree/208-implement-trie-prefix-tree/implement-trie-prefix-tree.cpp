class TrieNode{
    public:
        TrieNode *link[26];
        bool leaf = 0;
};
class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *temp = root;
        for(auto i:word){
            if(temp->link[i-'a']==NULL){
                temp->link[i-'a']=new TrieNode();
            }
            temp=temp->link[i-'a'];
        }
        temp->leaf = true;
    }
    
    bool search(string word) {
        TrieNode *temp = root;
        for(auto i:word){
            if(!temp->link[i-'a']) return 0;
            temp=temp->link[i-'a'];
        }
        return temp->leaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for(auto i:prefix){
            if(!temp->link[i-'a']) return 0;
            temp=temp->link[i-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */