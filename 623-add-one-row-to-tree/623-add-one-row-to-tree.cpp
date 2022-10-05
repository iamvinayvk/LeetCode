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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if(root==NULL)
            return root;
        if(depth==1){
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        if(depth==2){
            TreeNode* temp=new TreeNode(val);
            temp->left=root->left;
            root->left=temp;
            TreeNode* tempR=new TreeNode(val);
            tempR->right=root->right;
            root->right=tempR;
            return root;
            
        }
        addOneRow(root->left,val,depth-1);
        addOneRow(root->right,val,depth-1);
        return root;
        
        
    }
};