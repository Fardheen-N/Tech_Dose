class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n-1]!='0') return false;

        queue<int> q;
        q.push(0);
        
        int in = 0;
        int max_path = 0;
        while(!q.empty()){
             in = q.front();q.pop();
            if(in==n-1) return true;
           
            for(int i = max(in+minJump,max_path);i<=min(in+maxJump,n-1);i++){
                if(s[i]=='0') q.push(i);
            }
            
            max_path = min(in+maxJump+1,n);
        }
        return false;
    }
};