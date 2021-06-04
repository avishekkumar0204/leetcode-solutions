/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path(TreeNode *root,TreeNode *key,vector<TreeNode *> &p)
    {
        if(root==NULL)
            return false;
        if(root->val==key->val)
        {
            p.push_back(root);
            return true;
        }
        bool temp=path(root->left,key,p) || path(root->right,key,p);
        if(temp)
            p.push_back(root);
        return temp;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* A, TreeNode* B, TreeNode* C) {
        vector<TreeNode *> pathB,pathC;
        bool b= path(A,B,pathB);
        bool c= path(A,C,pathC);
        int n1=pathB.size(),n2=pathC.size();
        int i=n1-1,j=n2-1;
        TreeNode *lca;
        while(i>=0 && j>=0)
        {
            if(pathB[i]!=pathC[j])
                break;
            lca=pathB[i];
            i--;j--;
        }
        return lca;
        
    }
};