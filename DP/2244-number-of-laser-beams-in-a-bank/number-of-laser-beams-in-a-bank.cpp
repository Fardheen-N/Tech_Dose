class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
       int res=0;
       int pow=0,prev=0;
       for(int i=0;i<bank.size();i++)
       {   int temp=0;
           for(int j=0;j<bank[0].size();j++)
           {
               if(bank[i][j]=='1') temp++;
           }
           if(temp!=0)
           {
               if(prev!=0)
               {
                   res+=(prev*temp);
                   prev=temp;
               }
               prev=temp;
           }
       }
       return res; 
    }
};