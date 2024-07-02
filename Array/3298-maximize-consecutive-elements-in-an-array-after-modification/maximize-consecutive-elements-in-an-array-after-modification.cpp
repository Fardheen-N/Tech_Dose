// class Solution {
// public:
//     int maxSelectedElements(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<vector<int>> copy(2,vector<int>(nums));
//         for(int i=0;i<nums.size();i++){
//             copy[1][i]++;
//         }
//         for(int i=0;i<nums.size();i++){
//             cout<<nums[i]<<" ";
//         }cout<<endl;
//         for(int i=0;i<nums.size();i++){
//             cout<<copy[1][i]<<" ";
//         }

//         int best = 0;
//         for(int i=0;i<nums.size();i++){
//             best = max({best,solve(copy,i,0)+1,solve(copy,i,1)+1});
//         }
//         return best;
//     }
//     int solve(vector<vector<int>>& copy,int i,bool st){
//         if(i==copy[0].size()) return 0;

//         int path1=0,path2=0;
//         if(i+1!=copy[0].size()){
//             if(copy[st][i+1]-1==copy[st][i]) path1 = solve(copy,i+1,st)+1;
//             if(copy[!st][i+1]-1==copy[st][i]) path2 = solve(copy,i+1,!st)+1;
//         }

//         return max(path1,path2);
//     }
// };
class Solution {
public:
    vector<map<int,int>> dp;
    int solve(int in,int prev,vector<int> &nums){
         if(in==nums.size())return 0;
         if(dp[in].count(prev))return dp[in][prev];
         int ans=0;
         if(prev+1==nums[in]){
             ans=max(ans,1+solve(in+1,nums[in],nums));
         }
         if(nums[in]+1==prev+1){
             ans=max(ans,1+solve(in+1,nums[in]+1,nums));
         }
         if(nums[in]+1==prev){
             ans=max(ans,solve(in+1,nums[in]+1,nums));
         }
         return dp[in][prev]=ans;
    }

    int maxSelectedElements(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         int ans=1;
         int l=nums.size();
         dp.resize(l);
         for(int i=0;i<nums.size();i++){
             ans=max({ans,1+solve(i+1,nums[i],nums),1+solve(i+1,nums[i]+1,nums)});   
         }
        //  for(auto it:dp){
        //      for(auto i:it){
        //          cout<<i.first<<" "<<i.second<<endl;
        //      }
        //      cout<<endl;
        //  }
         return ans;      
    }
};