class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &A)
    {
        int n = A.size(), m = A[0].size();
        int path[n][m];
        path[0][0] = 1 - A[0][0];
        for (int col = 1; col < m; col++)
        {
            if (A[0][col] == 1)
                path[0][col] = 0;
            else if (path[0][col - 1] == 0)
                path[0][col] = 0;
            else
                path[0][col] = 1;
        }
        for (int row = 1; row < n; row++)
        {
            if (A[row][0] == 1)
                path[row][0] = 0;
            else if (path[row - 1][0] == 0)
                path[row][0] = 0;
            else
                path[row][0] = 1;
        }
        for (int row = 1; row < n; row++)
        {
            for (int col = 1; col < m; col++)
            {
                if (A[row][col] == 1)
                    path[row][col] = 0;
                else
                    path[row][col] = path[row - 1][col] + path[row][col - 1];
            }
        }
        return path[n - 1][m - 1];
    }
};

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &A)
    {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> path(n + 1, vector<int>(m + 1, 0));
        path[1][1] = 1 - A[0][0];
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (row == 0 && col == 0)
                    continue;
                if (A[row][col] == 1)
                    path[row + 1][col + 1] = 0;
                else
                    path[row + 1][col + 1] = path[row][col + 1] + path[row + 1][col];
            }
        }
        return path[n][m];
    }
};