class MedianFinder {
    ArrayList<Integer> res;
    public MedianFinder() {
        res=new ArrayList<Integer>();
    }
    
    public void addNum(int num) {
        int i;
        for( i=0;(i<res.size()&&res.get(i)<num);i++) 
        if(i==-1) i=0;
        res.add(i,num);
    }
    
    public double findMedian() {
        int len=res.size();
        int mid=len/2;
        if(len%2==0)
        return (double)(res.get(mid-1)+res.get(mid))/2.0;
        else
        return (double)(res.get(mid));
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */