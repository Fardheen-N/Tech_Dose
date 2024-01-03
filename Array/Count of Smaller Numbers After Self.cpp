class Solution {
public:
    void mergeSort(vector<int> &count,vector<pair<int,int>>& nums,int l,int h){
        if(l==h) return ;
        int mid = (l+h)/2;
        mergeSort(count,nums,l,mid);
        mergeSort(count,nums,mid+1,h);
        merge(count,nums,l,mid,h);
    }
    void merge(vector<int>& count,vector<pair<int,int>>& nums,int l,int mid,int h){
        vector<pair<int,int>> temp;
        int p1=l,p2=mid+1;
        while(p1<=mid&&p2<=h){
            if(nums[p1].first<=nums[p2].first){
                temp.push_back(nums[p2++]);
            }
            else{
                count[nums[p1].second]+=(h-p2+1);
                temp.push_back(nums[p1++]);
            }
        }
        while(p1<=mid) temp.push_back(nums[p1++]);
        while(p2<=h) temp.push_back(nums[p2++]);

        for(int i=l;i<=h;i++){
            nums[i]=temp[i-l];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> array;
        for(int i=0;i<nums.size();i++) array.push_back({nums[i],i});
        vector<int> res(nums.size(),0);
        mergeSort(res,array,0,nums.size()-1);
        return res;
    }
};
