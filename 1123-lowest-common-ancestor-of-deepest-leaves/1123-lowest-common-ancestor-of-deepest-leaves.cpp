/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
    }
        TreeNode* lcaDeepestLeaves(TreeNode *root) {
            if(root==NULL)
                return root;
            int leftHeight=height(root->left);
            int rightHeight=height(root->right);
            if(leftHeight==rightHeight)
                return root;
            if(leftHeight>rightHeight)
                return lcaDeepestLeaves(root->left);
            return lcaDeepestLeaves(root->right);
        }
};