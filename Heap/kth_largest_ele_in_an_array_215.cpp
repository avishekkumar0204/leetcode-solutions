// first solution
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n - k];
    }
};

// Second solution

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int i = 0;
        for (; i < k; i++)
            minHeap.push(nums[i]);
        for (; i < n; i++)
        {
            if (nums[i] > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};
