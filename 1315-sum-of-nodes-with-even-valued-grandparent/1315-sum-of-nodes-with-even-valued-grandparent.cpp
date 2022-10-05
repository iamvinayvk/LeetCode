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
    int find(TreeNode* root,TreeNode* parent,TreeNode* grandParent){
        if(root==NULL)
            return 0;
        int left=find(root->left,root,parent);
        int right=find(root->right,root,parent);
        if(grandParent!=NULL&&grandParent->val%2==0){
            return root->val+left+right;
        }
        return left+right;
    
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        TreeNode* parent=NULL;
        TreeNode* grandParent=NULL;
        ans=find(root,parent,grandParent);
        return ans;
    }
};