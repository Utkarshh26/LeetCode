class Solution {
    vector<vector<string>> ans;
private:    
    void helper(int col, int n, vector<string>& board, vector<int>& rowUsed,
                vector<int>& diag1, vector<int>& diag2) {

        if (col == n){
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (rowUsed[row]|| diag1[row +col] ||diag2[row- col+ n -1]){
                continue;
            }
            board[row][col] = 'Q';

            rowUsed[row] = 1;
            diag1[row + col] = 1;
            diag2[row - col + n - 1] = 1;

            helper(col + 1, n, board, rowUsed, diag1, diag2);

            board[row][col] = '.';
            rowUsed[row] = 0;
            diag1[row + col] = 0;
            diag2[row - col + n - 1] = 0;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<int> rowUsed(n, 0);

        vector<int> diag1(2*n -1,0);
        vector<int> diag2(2*n -1,0);
        helper(0, n,board, rowUsed,diag1,diag2);
        return ans;
    }
};