class Solution
{
public:
#define maxSize 10005
    int numSquares(int n)
    {
        int minNumber[maxSize];
        minNumber[0] = 0, minNumber[1] = 1;
        for (int i = 2; i < maxSize; i++)
        {
            minNumber[i] = INT_MAX;
            for (int j = 1; j * j <= i; j++)
                minNumber[i] = min(minNumber[i - j * j], minNumber[i]);
            minNumber[i]++;
                }
        return minNumber[n];
    }
};