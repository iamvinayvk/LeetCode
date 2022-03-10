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
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return 0;
        int an=0;
        queue<TreeNode*> q;
        int level=0;
        q.push(root);
        while(!q.empty()){
            vector<int> a;
            int siz=q.size();
            for(int i=0;i<siz;i++){
                TreeNode* t=q.front();
                a.push_back(t->val);
                if(t->left!=NULL){
                    q.push(t->left);
                }
                if(t->right!=NULL){
                    q.push(t->right);
                }
                q.pop();
                
            }
            ans.push_back(a);
        }
        for(int i=0;i<ans[ans.size()-1].size();i++){
            an+=ans[ans.size()-1][i];
        }
        return an;
    }
};