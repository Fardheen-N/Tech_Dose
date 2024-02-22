class Solution {
    public int findJudge(int n, int[][] trust) {
        int []record = new int[n+1];
        int []vote = new int[n+1];
        for(int i=0;i<trust.length;i++)
        {
          record[trust[i][0]]++;
          vote[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++) {
         if(record[i] == 0&& vote[i] == n-1) return i;
       }return -1;
    }
}