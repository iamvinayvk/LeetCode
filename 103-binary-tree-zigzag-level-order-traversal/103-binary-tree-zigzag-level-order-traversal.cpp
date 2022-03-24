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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool upward=true;
        while(!q.empty()){
            int s=q.size();
            vector<int> temp(s);
            for(int i=0;i<s;i++){
               // temp.push_back(q.front()->val);
                // cout<<q.front()->val<<"\n";
                TreeNode* curr=q.front();
                q.pop();
                int index=upward?i:s-i-1;
                temp[index]=curr->val;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                
                
                
            }
            ans.push_back(temp);
            upward=!upward;
            
        }
        return ans;
    }
};