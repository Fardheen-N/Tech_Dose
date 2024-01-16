class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> arr;
    RandomizedSet() {
                
    }
    
    bool insert(int val) {
        if(mp.count(val)!=0) return false ;
        mp[val]=arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val)==0) return false;
        int i = mp[val];
        mp[arr[arr.size()-1]]=i;
        swap(arr[i],arr[arr.size()-1]);
        arr.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */