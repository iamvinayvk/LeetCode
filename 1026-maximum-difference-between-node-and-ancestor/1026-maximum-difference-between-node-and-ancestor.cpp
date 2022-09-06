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
    void solve(TreeNode* root,int maxi,int mini,int& ans){
        if(root==NULL)
            return;
        ans=max({ans,abs(maxi-root->val),abs(root->val-mini)});
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        solve(root->left,maxi,mini,ans);
        solve(root->right,maxi,mini,ans);
        
        
    }
    int maxAncestorDiff(TreeNode* root) {
        
        int ans=0;
        if(root==NULL)
            return ans;
        int mini=root->val;
        int maxi=root->val;
        solve(root,maxi,mini,ans);
        // solve(root->right,root,ans);
        return ans;
    }
};