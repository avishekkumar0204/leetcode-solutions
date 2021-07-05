// Tc-n*n and sc-n

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> reach(n, 0);
        reach[0] = true;
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (i - j <= nums[j] && reach[j])
                {
                    reach[i] = true;
                    break;
                }
            }
        }
        return reach[n - 1];
    }
};

// Tc-n,sc-1

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int reach = 0;
        for (int i = 0; i < n - 1 && reach >= i; i++)
            reach = max(reach, nums[i] + i);
        return reach >= n - 1;
    }
};
