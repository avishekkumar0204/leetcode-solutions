// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
class Solution
{
public:
    TreeNode *build(vector<int> &in, vector<int> &post, int s, int e, int pos, unordered_map<int, int> &mp)
    {
        if (s > e)
            return NULL;

        int inIdx = mp[post[pos]];
        int noOfEleInRight = e - inIdx;
        TreeNode *root = new TreeNode(in[inIdx]);
        root->left = build(in, post, s, inIdx - 1, pos - noOfEleInRight - 1, mp);
        root->right = build(in, post, inIdx + 1, e, pos - 1, mp);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        TreeNode *root;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        return build(inorder, postorder, 0, n - 1, n - 1, mp);
    }
};