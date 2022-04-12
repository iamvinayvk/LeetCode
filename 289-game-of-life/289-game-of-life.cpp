class Solution {
public:
    bool willLive(vector<vector<int>>& tempBoard,int i,int j){
        int numberOfOnes=0;
        if(i-1>=0){
            numberOfOnes+=tempBoard[i-1][j];
        }
        if(i+1<tempBoard.size()){
            numberOfOnes+=tempBoard[i+1][j];
        }
        if(j-1>=0){
            numberOfOnes+=tempBoard[i][j-1];
        }
        if(j+1<tempBoard[0].size()){
            numberOfOnes+=tempBoard[i][j+1];
        }
        if(i-1>=0&&j-1>=0){
            numberOfOnes+=tempBoard[i-1][j-1];
        }
        if(i-1>=0&&j+1<tempBoard[0].size()){
            numberOfOnes+=tempBoard[i-1][j+1];
        }
         if(i+1<tempBoard.size()&&j+1<tempBoard[0].size()){
            numberOfOnes+=tempBoard[i+1][j+1];
        }
        if(i+1<tempBoard.size()&&j-1>=0){
            numberOfOnes+=tempBoard[i+1][j-1];
        }
        if(tempBoard[i][j]==1){
            if(numberOfOnes==2||numberOfOnes==3)
                return true;
            else
                return false;
        }
        else if(numberOfOnes==3){
            return true;
        }
        return false;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> tempBoard(board.size(),vector<int>(board[0].size()));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                tempBoard[i][j]=board[i][j];
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(willLive(tempBoard,i,j)){
                    board[i][j]=1;
                }
                else{
                    board[i][j]=0;
                }
            }
        }
        
        
    }
};