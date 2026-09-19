class Solution {
    vector<vector<string>> ans;
private:
    bool isSafe(int row,int col,vector<string>& board,int n){
        int x =row, y=col;
        while(row >=0 && col>=0){
            if(board[row][col] =='Q'){
                return false;
            }
            row--; col--;
        }
        row =x; col=y;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        col =y;
        while(row<n&& col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--; row++;
        }
        return true;
    }    
    void helper(int cols,int n, vector<string>& board){
        if(cols ==n){
            ans.push_back(board);
            return;
        }
        for(int rows=0; rows <n; rows++){
            if(isSafe(rows,cols,board,n)){
                board[rows][cols] ='Q';
                helper(cols+1,n,board);
                board[rows][cols]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        for(int i=0; i<n; i++){
            board[i] =s;
        }
        helper(0,n,board);
        return ans;
    }
};