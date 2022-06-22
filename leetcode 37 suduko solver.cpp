class Solution {
    bool valid(vector<vector<char>>&board,int row,int col,int y)
{
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==y) return false;
        if(board[i][col]==y) return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==y) return false;
    }
    return true;
}
bool solve(vector<vector<char>>&board)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]=='.')
            {
                for(int y='1';y<='9';y++)
                {
                    if(valid(board,i,j,y))
                    {
                        board[i][j]=y;
                        if(solve(board))
                        {
                            return true;
                        }
                        else{
                            board[i][j]='.';
                        }
                    }
                }
                return false; 
            }  
        }
    }
    return true;
}
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
