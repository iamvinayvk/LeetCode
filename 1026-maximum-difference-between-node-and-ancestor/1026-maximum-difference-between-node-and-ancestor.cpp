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
class Solution {
public:
    int solve(TreeNode* root,int maxi,int mini){
        if(root==NULL)
            return abs(maxi-mini);
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        int left=solve(root->left,maxi,mini);
        int right=solve(root->right,maxi,mini);
        return max(left,right);
        
        
    }
    int maxAncestorDiff(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        int mini=root->val;
        int maxi=root->val;
        return solve(root,maxi,mini);
    }
};