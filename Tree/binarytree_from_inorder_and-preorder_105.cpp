// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/  
class Solution {
public:
    TreeNode *build(vector<int> &in,vector<int> &pre,int s,int e,int pos,map<int,int> &mp)
    {
        if(s>e)
            return NULL;
        int idx=mp[pre[pos]];
        TreeNode *root=new TreeNode(in[idx]);
        root->left=build(in,pre,s,idx-1,pos+1,mp);
        root->right=build(in,pre,idx+1,e,pos+1+(idx-s),mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        return build(inorder,preorder,0,n-1,0,mp);
        
        
    }
};



