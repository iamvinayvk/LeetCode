/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* root,vector<TreeNode*>& path,TreeNode* x){
        if(root==NULL)
            return false;
        path.push_back(root);
        // cout<<root->val<<"\n";
        if(root->val==x->val)
            return true;
        if(getPath(root->left,path,x)||getPath(root->right,path,x)){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1,path2;
        getPath(root,path1,p);
        getPath(root,path2,q);
        TreeNode* ans=NULL;
        for(int i=0;i<min(path1.size(),path2.size());i++){
            
            if(path1[i]->val==path2[i]->val)
                ans=path1[i];
            else{
                return ans;
            }
        }
        return ans;
    }
};