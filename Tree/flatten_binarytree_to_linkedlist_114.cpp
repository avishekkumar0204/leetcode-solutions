// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

class Solution
{
public:
    pair<TreeNode *, TreeNode *> flatterTree(TreeNode *root)
    {
        if (root == NULL)
            return {NULL, NULL};
        pair<TreeNode *, TreeNode *> lft = flatterTree(root->left);
        pair<TreeNode *, TreeNode *> rt = flatterTree(root->right);
        root->left = NULL;
        if (lft.first == NULL)
        {
            root->right = rt.first;
            return {root, (rt.first == NULL) ? root : rt.second};
        }
        root->right = lft.first;
        lft.second->right = rt.first;
        return {root, (rt.first == NULL) ? lft.second : rt.second};
    }
    void flatten(TreeNode *root)
    {
        pair<TreeNode *, TreeNode *> p = flatterTree(root);
    }
};