class Solution {
public:
    bool isValid(vector<vector<char>>& board, int i,int j, char k){
        for(int a=0;a<9;a++){
            if(board[i][a]==k || board[a][j]==k)
                return false;
        }
        int m_x = i - i%3;
        int m_y = j - j%3;
        for(int a=m_x; a<m_x+3; a++){
            for(int b=m_y; b<m_y+3; b++){
                if(board[a][b]==k)
                    return false;
            }
        }
        return true;
    }
    
    bool sudoku(vector<vector<char>>& board){
        bool flag = false;
        int i,j;
        for(i =0;i<9;i++){
            for(j=0;j<9;j++){
                if(board[i][j] == '.'){
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(i==9 && j==9)
            return true;
        
        for(char k = '1';k<='9';k++){
            if(isValid(board,i,j,k)){
                board[i][j]=k;
                if(sudoku(board))
                    return true;
                board[i][j]='.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board);
    }
};