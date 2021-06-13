class Solution
{
public:
    pair<string, string> findInPre(TreeNode *root, map<pair<string, string>, vector<TreeNode *>> &mp)
    {
        if (root == NULL)
            return {"#", "#"};
        pair<string, string> lft = findInPre(root->left, mp);
        pair<string, string> rt = findInPre(root->right, mp);
        string pre = to_string(root->val) + lft.first + rt.first;
        string in = lft.second + to_string(root->val) + rt.second;
        mp[{pre, in}].push_back(root);
        return {pre, in};
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        map<pair<string, string>, vector<TreeNode *>> mp;
        findInPre(root, mp);
        vector<TreeNode *> dup;
        for (auto it : mp)
        {
            if (it.second.size() >= 2)
                dup.push_back(it.second[0]);
        }
        return dup;
    }
};