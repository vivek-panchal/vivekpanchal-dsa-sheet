class Solution {
    
bool isSafe(int row,int col,vector<string>&board,int n){
    int x=row;
    int y=col;
    
    //check for same row
    while(y>=0){
        if(board[x][y]=='Q')
            return false;
        y--;
    }
    x=row;
    y=col;
    
    // check for diagnol
    while(x>=0 && y>=0){
        if(board[x][y]=='Q')
            return false;
        y--;
        x--;
    }
    x=row;
    y=col;
    // check for diagnol
    while(x<n && y>=0){
        if(board[x][y]=='Q')
            return false;
        y--;
        x++;
    }
    return true;  
}
void solve(int col,vector<vector<string>>&ans,vector<string>&board,int n){
    //base case
    if(col==n){
        ans.push_back(board);
        return;
    }
    
    // solve  1 case rest recursion will handel
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            //if this position is safe for queen placement
            board[row][col]='Q';
            solve(col+1,ans,board,n);
            //backtraking
            board[row][col]='.';
        }
    }
}
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        vector<vector<string>>ans;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,ans,board,n);
      return ans;
    }
};
