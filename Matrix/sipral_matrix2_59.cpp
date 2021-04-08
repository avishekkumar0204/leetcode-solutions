class Solution
{
public:
    void gen(vector<vector<int>> &mat, int si, int sj, int ei, int ej, int num)
    {
        if (si > ei || sj > ej)
            return;
        for (int p = sj; p <= ej; p++)
        {
            mat[si][p] = num;
            num++;
        }
        for (int p = si + 1; p <= ei; p++)
        {
            mat[p][ej] = num;
            num++;
        }
        for (int p = ej - 1; p >= sj; p--)
        {
            mat[ei][p] = num;
            num++;
        }
        for (int p = ei - 1; p >= si + 1; p--)
        {
            mat[p][sj] = num;
            num++;
        }
        gen(mat, si + 1, sj + 1, ei - 1, ej - 1, num);
    }
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        gen(res, 0, 0, n - 1, n - 1, 1);
        return res;
    }
};