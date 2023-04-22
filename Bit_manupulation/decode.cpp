class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int mask=0,encode=0;
        int size=encoded.size();
        vector<int> res(size+1);
        for(int i=1;i<=size+1;i++){
            mask^=i;
        }
        for(int i=1;i<size;i+=2){
            encode^=encoded[i];
        }
        res[0]=mask^encode;
        for(int i=0;i<size;i++){
            res[i+1]=res[i]^encoded[i];
        }
        return res;
    }
};
