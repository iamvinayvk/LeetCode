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
    void paths(TreeNode* root,vector<string>& ans,string res){
        if(root==NULL){
         
            return;
        }
        
        if(res.size()>0){
            res+="->";
        }
            
        res+=to_string(root->val);
        if(root->left==NULL&&root->right==NULL)
        {
            ans.push_back(res);
            return ;
        }
        paths(root->left,ans,res);
        paths(root->right,ans,res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==NULL)
            return ans;
        paths(root,ans,"");
        return ans;
    }
};