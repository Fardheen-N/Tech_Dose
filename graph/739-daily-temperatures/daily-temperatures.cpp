class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n,0);
        int maxi = -1;
        int in ;
        for(int i=n-1;i>=0;i--){
            if(maxi<=temp[i]){maxi=temp[i];continue;}
            int days = 1;
            while(temp[i]>=temp[i+days]){
                days += res[i+days];
            }
            res[i]= days;
        }
        return res;
    }
};