class Solution {
    bool valid(vector<vector<char>>&board,int row,int col,int y)
{
    for(int i=0;i<9;i++)
    {
        // check karo jha ham Y ko dal rahe hai kya uss row me Y phle se hai ya nhi 
        if(board[row][i]==y)
            return false;
        // same check for col 
        if(board[i][col]==y)
            return false;
        // check for 3X3 matrix
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==y)
            return false;
    }
    return true;
}
bool solve(vector<vector<char>>&board)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            // if we find any empty place , we try all possible numbers 1-9 at that place 
            if(board[i][j]=='.')
            {
                for(int y='1';y<='9';y++)
                {// we trying to put nuber from 1-9 , and check is this valid or not
                    if(valid(board,i,j,y))
                    {
                        board[i][j]=y;
                        // y ko put karne ke baad check kar rahe hai kya aage solve ho pa rha hai if yes than return true &  if solution not found than backtrack and try other number
                        if(solve(board))
                        {
                            //solution possible
                            return true;
                        }
                        else{
                           // back track bcs if we put Y at that place we cant solve whole sudku
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
