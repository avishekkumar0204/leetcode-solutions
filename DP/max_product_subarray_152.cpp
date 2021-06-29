class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int maxEnd = nums[0], minEnd = nums[0];
        int maxProd = nums[0];
        for (int i = 1; i < n; i++)
        {
            int temp = maxEnd;
            maxEnd = max(nums[i], max(maxEnd * nums[i], minEnd * nums[i]));
            minEnd = min(nums[i], min(temp * nums[i], minEnd * nums[i]));
            maxProd = max(maxProd, maxEnd);
        }
        return maxProd;
    }
};