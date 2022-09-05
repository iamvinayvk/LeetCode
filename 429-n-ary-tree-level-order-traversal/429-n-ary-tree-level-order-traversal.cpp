/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<Node*> q;
        q.push(root);
       
        while(!q.empty()){
            int k=q.size();
            vector<int> res;
            while(k--){
                Node* curr=q.front();
                q.pop();
                res.push_back(curr->val);
                for(auto x:curr->children){
                    q.push(x);
                }
            }
            ans.push_back(res);
            
            

            
        
        }
        return ans;
    }
};