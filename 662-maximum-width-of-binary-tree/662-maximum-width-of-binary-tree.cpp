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
    int widthOfBinaryTree(TreeNode* root) {
        long long  ans=0;
        if(root==NULL)
            return ans;
        queue<pair<TreeNode*,long long >> q;
        q.push({root,0});
        while(!q.empty()){
            int s=q.size();
            int minimum=q.front().second;
            long long first,last;
            for(int i=0;i<s;i++){
                long long curr_index=q.front().second-minimum;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0)
                    first=curr_index;
                if(i==s-1)
                    last=curr_index;
                if(node->left){
                    q.push({node->left,curr_index*2+1});
                }
                if(node->right){
                    q.push({node->right,curr_index*2+2});
                }
                
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};