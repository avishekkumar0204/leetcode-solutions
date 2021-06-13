class Solution
{
public:
    bool isInPath(TreeNode *root, TreeNode *target, vector<TreeNode *> &targetToRoot)
    {
        if (root == NULL)
            return false;
        if (root == target)
        {
            targetToRoot.push_back(target);
            return true;
        }
        bool lft = isInPath(root->left, target, targetToRoot);
        bool rt = isInPath(root->right, target, targetToRoot);
        if (lft || rt)
            targetToRoot.push_back(root);
        return lft || rt;
    }
    void allNodeBelowK(TreeNode *root, int k, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (k == 0)
        {
            ans.push_back(root->val);
            return;
        }
        allNodeBelowK(root->left, k - 1, ans);
        allNodeBelowK(root->right, k - 1, ans);
        return;
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<TreeNode *> targetToRoot;
        isInPath(root, target, targetToRoot);
        
        vector<int> ans;
        allNodeBelowK(targetToRoot[0], k, ans);
        int n = targetToRoot.size();
        k--;
        for (int i = 1; i < n; i++)
        {
            if (k == 0)
            {
                ans.push_back(targetToRoot[i]->val);
                break;
            }
            if (targetToRoot[i]->right == targetToRoot[i - 1])
                allNodeBelowK(targetToRoot[i]->left, k - 1, ans);
            else
                allNodeBelowK(targetToRoot[i]->right, k - 1, ans);
            k--;
        }
        return ans;
    }
};