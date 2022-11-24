class Solution {
public:
    bool dfs(vector<vector<char>>& board,int i,int j,int n,int m,string word,int curr_word_index){
        if(i<0||j<0||i>=n||j>=m||board[i][j]=='*'||curr_word_index>=word.size())
            return false;
        if(word[curr_word_index]!=board[i][j])
            return false;
        if(curr_word_index==word.size()-1)
            return true;
        char temp=board[i][j];
        board[i][j]='*';
        if(dfs(board,i+1,j,n,m,word,curr_word_index+1))
            return true;
        if(dfs(board,i-1,j,n,m,word,curr_word_index+1))
            return true;
        if(dfs(board,i,j-1,n,m,word,curr_word_index+1))
            return true;
        if(dfs(board,i,j+1,n,m,word,curr_word_index+1))
            return true;
        board[i][j]=temp;
        return false;
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        // saare cell me chalenge 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // first character word ka match kre to dfs me 
                if(board[i][j]==word[0]){
                    bool ans=dfs(board,i,j,n,m,word,0);
                    if(ans==true)
                        return true;
                }
            }
        }
        return false;
    }
};