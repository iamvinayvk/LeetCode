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
    TreeNode* bt(unordered_map<int,int>& mp,int startIn,int endIn,vector<int>& postorder,int startPos,int endPos){
        if(startIn>endIn||startPos>endPos){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[endPos]);
        int rootIndex=mp[postorder[endPos]];
        int leftSubtreeElements=rootIndex-startIn;
        root->left=bt(mp,startIn,rootIndex-1,postorder,startPos,startPos+leftSubtreeElements-1);
        root->right=bt(mp,rootIndex+1,endIn,postorder,startPos+leftSubtreeElements,endPos-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=NULL;
        root=bt(mp,0,n-1,postorder,0,n-1);
        return root;
    }
};