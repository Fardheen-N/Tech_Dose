class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      //nums1.resize(nums1.size());
      for(int i:nums2)
      {
        //nums1.resize(nums1.size()+1);  
        nums1.push_back(i);
      }
      sort(nums1.begin(),nums1.end()); 
      for(int i:nums1) 
      cout<<i<<" ";
      int fst=nums1[nums1.size()/2];
      int sed=nums1[(nums1.size()-1)/2];
      //cout<<fst<<" "<<sed; 
      double res = (fst+sed)/2.0;
      return res;
    }
};