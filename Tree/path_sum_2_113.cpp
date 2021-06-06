// https://leetcode.com/problems/path-sum-ii/
class Solution
{
public:
    bool allPath(TreeNode *root, int target, vector<int> &path, vector<vector<int>> &all)
    {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL)
        {
            if (root->val == target)
            {
                path.push_back(root->val);
                all.push_back(path);
                path.pop_back();
            }
            return root->val == target;
        }
        path.push_back(root->val);
        bool lft = allPath(root->left, target - root->val, path, all);
        bool rt = allPath(root->right, target - root->val, path, all);
        path.pop_back();

        return lft || rt;
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> all;
        vector<int> path;
        bool hasPath = allPath(root, targetSum, path, all);
        return all;
    }
};