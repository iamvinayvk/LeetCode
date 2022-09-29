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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_map<int,int> hasParent;
        int n=descriptions.size();
        for(int i=0;i<n;i++){
            if(mp.find(descriptions[i][0])==mp.end()){
                TreeNode* temp=new TreeNode(descriptions[i][0]);
                mp[descriptions[i][0]]=temp;
            }
            if(mp.find(descriptions[i][1])==mp.end()){
                TreeNode* temp=new TreeNode(descriptions[i][1]);
                mp[descriptions[i][1]]=temp;

            }
        hasParent[descriptions[i][1]]=1;
        }
        TreeNode* root=NULL;
        for(int i=0;i<n;i++){
            TreeNode* parent=mp[descriptions[i][0]];
            TreeNode* child=mp[descriptions[i][1]];
            // cout<<hasParent[descriptions[i][0]]<<" "<<hasParent[descriptions[i][1]]<<"\n";
            if(hasParent.find(descriptions[i][0])==hasParent.end())
            {
                // cout<<"ROot "<<mp[descriptions[i][0]]->val<<"\n";
                root=mp[descriptions[i][0]];
            }
            if(descriptions[i][2]){
                parent->left=child;
            }
            else{
                parent->right=child;
            }
        }
        return root;
    }
};

/*
               74   
              /  \
            85    39                  
           /      /  \                 
          82     13    70                 
          /  
         38 
*/