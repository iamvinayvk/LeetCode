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
    bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    return judge(root->left,root->right);
     
}
bool judge(TreeNode* l, TreeNode* r){
    return (!l||!r) ?l==r: l->val==r->val&&judge(l->right,r->left)&&judge(l->left,r->right);
    }
};