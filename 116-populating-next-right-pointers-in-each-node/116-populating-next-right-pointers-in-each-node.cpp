/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // vector<vector<Node*>> storeBFS;
        queue<Node*> q;
        if(root==NULL)
            return root;
        q.push(root);
        int level=1;
        while(!q.empty()){
            // level=level*2;
            
            // vector<Node*> levelNode;
            Node* rightNode=NULL;
            for(int i=0;i<level;i++){
                Node* curr=q.front();
                q.pop();
                // levelNode.push_back(curr);
                curr->next=rightNode;
                rightNode=curr;
                
                if(curr->right){
                    q.push(curr->right);
                }
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                // q.pop();
            }
            // storeBFS.push_back(levelNode);
            // for(int i=0;i<levelNode.size()-1;i++){
            //     levelNode[i]->next=levelNode[i+1];
            // }
            // levelNode[levelNode.size()-1]->next=NULL;
            level=level*2;
        }
        return root;
        
    }
};