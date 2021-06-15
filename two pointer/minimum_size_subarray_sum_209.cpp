class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0, j = -1;
        int n = nums.size();
        int sum = INT_MIN, minLen = INT_MAX;
        while (i < n)
        {

            if (sum < target)
            {
                j++;
                if (j == n)
                    break;
                sum += a[j];
            }
            else
            {
                minLen = min(minLen, j - i + 1);
                sum -= nums[i];
                i++;
            }
        }
        return minLen;
    }
};