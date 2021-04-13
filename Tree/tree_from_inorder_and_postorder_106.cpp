/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *build(vector<int> &in, vector<int> &post, int start, int end, int pos, unordered_map<int, int> &mp)
    {
        if (start > end)
        {
            return NULL;
        }
        int idx = mp[post[pos]];
        TreeNode *root = new TreeNode(in[idx]);
        root->left = build(in, post, start, idx - 1, pos - 1 - (end - idx), mp);
        root->right = build(in, post, idx + 1, end, pos - 1, mp);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        TreeNode *root;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        root = build(inorder, postorder, 0, n - 1, n - 1, mp);
        return root;
    }
};