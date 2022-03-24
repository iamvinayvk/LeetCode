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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> curr=q.front();
            q.pop();
            mp[curr.second.first][curr.second.second].insert(curr.first->val);
            if(curr.first->left){
                q.push({curr.first->left,{curr.second.first-1,curr.second.second+1}});
            }
            if(curr.first->right){
                q.push({curr.first->right,{curr.second.first+1,curr.second.second+1}});
            }
        }
        for(auto x:mp){
            vector<int> temp;
            for(auto y:x.second){
                temp.insert(temp.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};