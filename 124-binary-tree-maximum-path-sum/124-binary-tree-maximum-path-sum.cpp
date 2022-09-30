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
    int solve(TreeNode* root,int& ans){
        if(root==NULL)
            return 0;
        int left=solve(root->left,ans);
        int right=solve(root->right,ans);
        left=left<0?0:left;
        right=right<0?0:right;
        int considerEitherLeftorRight=max(left,right)+root->val;
        int considerBoth=left+right+root->val;
        ans=max({ans,considerEitherLeftorRight,considerBoth});
        return considerEitherLeftorRight;
        
        
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};