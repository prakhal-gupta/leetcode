class Solution {
public:
    int dir[4][2] = { {-1,0}, {0,-1}, {1,0}, {0,1}};
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    isVisited[i][j]=true;
                    if(isValid(board, word, i, j, 1, isVisited))
                        return true;
                    isVisited[i][j]=false;
                }
            }
        }
        return false;
    }
    
    bool isValid(vector<vector<char>>& board, string word, int i, int j, int k, vector<vector<bool>>& isVisited){
        if (k == word.size())
            return true;
        isVisited[i][j]=true;
        for(int x=0; x<4; x++){
            int new_x = i + dir[x][0];
            int new_y = j + dir[x][1];
            if(new_x>=0 &&  new_x<board.size() && new_y>=0 && new_y<board[0].size() && isVisited[new_x][new_y]==0 && board[new_x][new_y]==word[k]){
               if(isValid(board, word, new_x, new_y, k + 1, isVisited))
                return true; 
            }   
        }
        isVisited[i][j]=false;
        return false;
    }
};