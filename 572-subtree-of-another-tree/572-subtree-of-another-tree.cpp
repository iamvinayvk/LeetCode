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
    bool isSameTree(TreeNode* root,TreeNode* subRoot){
        if(root==NULL||subRoot==NULL){
            return root==NULL&&subRoot==NULL;
        }
        if(root->val==subRoot->val){
            return isSameTree(root->left,subRoot->left)&&isSameTree(root->right,subRoot->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)
            return false;
        if(isSameTree(root,subRoot)){
            return true;
        }
        else if(root->left&&root->right)
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
        else if(root->left){
            return isSubtree(root->left,subRoot);
        }
        else if(root->right){
            return isSubtree(root->right,subRoot);
        }
        return false;
    }
};