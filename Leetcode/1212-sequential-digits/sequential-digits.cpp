class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num = "123456789";
        int st = count(low);
        int en = count(high);
        vector<int> res ;
        while(st<=en){
            int w = st;
            int l = 0,r=st;
            while(r<=9){
                int s = stoi(num.substr(l,st));
                if(s>high) return res;
                if(s>=low)
                res.push_back(s);
                l++;r++;
            }
            st++;
        }
        return res;
    }
    int count(int n){
        int cnt = 0;
        while(n){
            cnt++;
            n/=10;
        }
        return cnt;
    }
};