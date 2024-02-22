class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0,r=0;
        for(auto i:weights){
            r+=i;
            l=max(l,i);
        }
        while(l<=r){
            int mid = (l+r)/2;
            int mindays = check(weights,mid);
            // if(mindays == days) return mid;
            if(mindays>=days){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        // cout<<<<endl;
        return l;
    }
    int check(vector<int> &w,int cap){
        int sum =0;
        int res=0;
        for(int i=0;i<w.size();i++){
            if(sum+w[i]>cap){
                res++;
                sum=w[i];
            }else{
                sum+=w[i];
            }
        }
        return res;
    }
};