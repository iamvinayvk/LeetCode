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
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev=NULL;
    void Tree(TreeNode* root){
        if(root==NULL)
            return ;
        Tree(root->left);
        if(first==NULL&&(prev!=NULL&&prev->val>=root->val)){
            first=prev;
        }
        if(first!=NULL&&(prev!=NULL&&prev->val>=root->val)){
            second=root;
        }
        prev=root;
        
        Tree(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL)
            return;
        // if(root->left&&root->left->val>root->val){
        //     // recoverTree(root->left);
        //     swap(root->left->val,root->val);
        //     return;
        // }
        // if(root->right&&root->right->val>root->val){
        //     swap(root->right->val,root->val);
        //     return ;
        // }
        // if(root->left&&)
        Tree(root);
        swap(first->val,second->val);
        // Tree(root->right);
        
    }
};