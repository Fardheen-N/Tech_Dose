class Solution {
public:
    vector<int> g[1000];
    unordered_map<int,vector<int>> dp;
    vector<int> dfs(int node){
        if(dp.find(node)!=dp.end())return dp[node];
        vector<int> te;
        for(auto e: g[node]){
            
            vector<int> pe=dfs(e);
            
            if(te.size()<pe.size()){
                te=pe;
            }}
        te.push_back(node);
        return dp[node]=te;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
        if(nums[j]%nums[i]==0){
               g[i].push_back(j);
                    
                } }}
        
        for(int i=0;i<n;i++){
            
           vector<int> temp=dfs(i);
    
            if(temp.size()>ans.size()){
                ans=temp;
            }
        }
        
        for(int i=0;i<ans.size();i++){
            ans[i]=nums[ans[i]];
        }
        
        return ans;
    }
};