class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int minIdx = -1;
        int n = nums.size();

        int s = 0, e = n - 1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (mid + 1 < n && nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            else if (nums[mid] >= nums[0])
                s = mid + 1;
            else
                e = mid - 1;
        }
        return nums[0];
    }
};