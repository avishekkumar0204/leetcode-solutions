class Solution
{
public:
#define mib map<int, bool>
    // Assuming false as safe and true as unsafe
    bool nQueen(vector<vector<string>> &ans, vector<string> &board, int row, mib isColSafe, mib isDiag1Safe, mib isDiag2Safe, int n)
    {
        if (row == n)
        {
            ans.push_back(board);
        }
        for (int col = 0; col < n; col++)
        {
            if ((!isColSafe[col]) && (!isDiag1Safe[row - col]) && (!isDiag2Safe[row + col]))
            {
                isColSafe[col] = true;
                isDiag1Safe[row - col] = true;
                isDiag2Safe[row + col] = true;
                board[row][col] = 'Q';
                if (nQueen(ans, board, row + 1, isColSafe, isDiag1Safe, isDiag2Safe, n))
                    return true;
                isColSafe[col] = false;
                isDiag1Safe[row - col] = false;
                isDiag2Safe[row + col] = false;
                board[row][col] = '.';
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        mib isColSafe, isDiag1Safe, isDiag2Safe;
        nQueen(ans, board, 0, isColSafe, isDiag1Safe, isDiag2Safe, n);
        return ans;
    }
};