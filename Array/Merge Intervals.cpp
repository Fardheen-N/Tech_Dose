class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       if(intervals.size()==1) return intervals;
       int k=0; 
       sort(intervals.begin(),intervals.end());
       vector<vector<int>> res;
       res.push_back(intervals[0]);
       for(int i=1;i<intervals.size();i++){
           
               if(intervals[i][0]<=res[k][1]){
                   res[k][1]=max(intervals[i][1],res[k][1]);
               }
               else
               {res.push_back(intervals[i]);k++;}
       }
       return res; 
    }
};
