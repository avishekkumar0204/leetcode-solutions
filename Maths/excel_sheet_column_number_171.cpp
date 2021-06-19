class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int n = columnTitle.size();
        int colNo = 0;
        for (int i = n - 1; i >= 0; i--)
            colNo += (columnTitle[i] - 64) * pow(26, n - i - 1);
        return colNo;
    }
};