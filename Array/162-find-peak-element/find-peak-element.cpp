class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int l=0,r=arr.size()-1;
        if(r==0) return r;
        while(l<r){
            int mid = (l+r)/2;
            if( (mid+1==arr.size()||arr[mid]>arr[mid+1]) && ((mid>0)?arr[mid]>arr[mid-1]:1)) return mid;
            else if(arr[mid]<arr[mid+1]) l=mid+1;
            else r=mid; 
        }
        return l;
    }
};