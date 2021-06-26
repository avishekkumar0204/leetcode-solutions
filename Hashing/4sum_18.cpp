class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        set<vector<int>> quad;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        if (nums[i] + nums[j] + nums[k] + nums[l] == target)
                        {
                            vector<int> temp;
                            temp.push_back(nums[i]);
                            temp.push_back(nums[j]);
                            temp.push_back(nums[k]);
                            temp.push_back(nums[l]);
                            sort(temp.begin(), temp.end());
                            quad.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for (auto it : quad)
        {
            vector<int> v=*it;
            ans.push_back(v);
        }
        return ans;
    }
};