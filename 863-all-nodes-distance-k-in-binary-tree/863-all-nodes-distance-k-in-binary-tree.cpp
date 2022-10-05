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
    void designParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
        if(root==NULL)
            return ;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    parent[curr->left]=curr;
                }
                if(curr->right){
                    q.push(curr->right);
                    parent[curr->right]=curr;
                }
            }
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        designParent(root,parent);
        vector<int> ans;
        // go upto K from target
        queue<TreeNode*> q;
        q.push(target);
        int currDistance=0;
        unordered_map<TreeNode*,bool> visited;
        visited[target]=true;
        while(!q.empty()){
            int size=q.size();
            if(currDistance==k){
                break;
            }
            currDistance++;
            while(size--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left&&visited[curr->left]==false){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right&&visited[curr->right]==false){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(parent.find(curr)!=parent.end()&&visited[parent[curr]]==false){
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                }
            }
        }
        while(!q.empty()){
            TreeNode* curr=q.front();
            ans.push_back(curr->val);
            q.pop();
        }
        return ans;
    }
};