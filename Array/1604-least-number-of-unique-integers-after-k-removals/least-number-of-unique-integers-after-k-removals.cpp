class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto i:arr){
            mp[i]++;
        }
        int res = 0;
        vector<int> vals;
        for(auto i:mp){
            vals.push_back(i.second);
        }
        sort(vals.begin(),vals.end());
        for(int i=0;i<vals.size();i++){
            if(vals[i]>=k){
                vals[i]-=k;
                k=0;
            }else{
                k-=vals[i];
                vals[i]=0;
            }
            if(k==0) break;
        }
        for(auto i:vals){
            cout<<i<<" ";
            if(i>0) res++;
        }
        return res;
    }
};