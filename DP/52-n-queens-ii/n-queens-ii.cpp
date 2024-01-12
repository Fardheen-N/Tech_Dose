class Solution {
public:
    int totalNQueens(int n) {
        vector<string> bd(n,string(n,'.'));
        return solve(bd,n,0);
    }
    int solve(vector<string>&bd,int n,int i){
        if(i==n) return 1;
        int pos =0;
        for(int j=0;j<n;j++){
            if(valid(bd,i,j)){
                bd[i][j]='Q';
                pos+=solve(bd,n,i+1);
                bd[i][j]='.';
            }
        }
        return pos;
    }
    bool valid(vector<string> &board, int row, int col)
    {
        for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;

        for(int i=row, j=col; i>=0 && j>=0; i--,j--)
            if(board[i][j] == 'Q') return false;

        for(int i=row,j=col;i>=0 && j<board.size(); i--,j++)
            if(board[i][j] == 'Q') return false;
        return true;
    }
};