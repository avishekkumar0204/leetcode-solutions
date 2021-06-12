class Solution {
public:
    int maxSum(TreeNode *root,int &ans)
    {
        if(root==NULL)
            return 0;
        int l=maxSum(root->left,ans);
        int r=maxSum(root->right,ans);
        ans=max(ans,max(0,l)+max(0,r)+root->val);
        return max(max(l,r),0)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int pathSum=maxSum(root,ans);
        return ans;
        
    }
};