class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> freq;
        for(auto i:nums) freq[i]++;
        int count = 0;
        for(auto i:freq){
            cout<<i.first<<":"<<i.second<<endl;
        }
        for(auto i:freq){
            if(i.second<2) return -1;
            else if(i.second%3==0){
                count += (i.second/3);
            }
            else {
                // i.second-=3;
                // count++;
                count += (i.second/3)+1;
            }
        }
        return count;
    }
};