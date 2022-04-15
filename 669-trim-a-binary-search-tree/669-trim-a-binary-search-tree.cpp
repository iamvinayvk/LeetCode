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
     TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL){
            return root;
        }
        
        while(root!=NULL&&(root->val < low || root->val > high)){
            if(root->val < low){
                root = root->right;
            }
            else if(root->val > high){
                root = root->left;
            }
        }
        
        TreeNode* temp = root;
        
        while(temp != NULL){
            while(temp->left != NULL and temp->left->val < low){
                temp->left = temp->left->right;
            }
            temp = temp->left;
        }
        temp = root;
        
        while(temp != NULL){
            while(temp->right != NULL and temp->right->val > high){
                temp->right = temp->right->left;
            }
            temp = temp->right;
        }
        
        return root;
    }
};