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
    int ans(TreeNode* root,map<TreeNode*,int>& dp){
        if(root==NULL)
            return 0;
        // take root
        if(dp.find(root)!=dp.end())
            return dp[root];
        int take=root->val;
        if(root->left!=NULL)
            take+=ans(root->left->left,dp)+ans(root->left->right,dp);
        if(root->right!=NULL)
            take+=ans(root->right->left,dp)+ans(root->right->right,dp);
        //not take root;
        int notTake=ans(root->left,dp)+ans(root->right,dp);
        return dp[root]=max(take,notTake);
    }
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        map<TreeNode*,int> dp;
        return ans(root,dp);
    }
};