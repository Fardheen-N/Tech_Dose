class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long wait = 0;
        long curr = 1;
        for(int i=0;i<n;i++){
            if(customers[i][0]<curr){
                wait+=(curr-customers[i][0]);
            }else{
                curr=customers[i][0];
            }
            curr+=customers[i][1];
            wait+=customers[i][1];
        }
        double d = 1.0;
        return wait/(n*d);
    }
};