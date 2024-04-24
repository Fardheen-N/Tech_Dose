class Solution {
public:
     int tribonacci(int n) {
      int rec[] = {0, 1, 1};
      for(int num=3;num<=n;num++){
          rec[num%3]=rec[0]+rec[1]+rec[2];
      }
     return rec[n%3];
    }
};