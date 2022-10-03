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
    pair<int,int> solve(TreeNode* root,int& ans){
        if(root==NULL)
            return {INT_MAX,INT_MIN};
        auto [left_min,left_max]=solve(root->left,ans);
        auto [right_min,right_max]=solve(root->right,ans);
        int curr_min=min({root->val,left_min,right_min});
        int curr_max=max({root->val,left_max,right_max});
        ans=max({ans,root->val-curr_min,curr_max-root->val});
        return {curr_min,curr_max};
        
        
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};