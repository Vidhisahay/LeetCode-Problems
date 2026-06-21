class Solution {
public:
    bool right_row(vector<vector<int>>& board,int coloumn,int row){
        for (int i=0;i<board.size();i++){
            if (board[i][coloumn]==1) 
            return false;
        }
        return true;
    }
    bool upper_diagnol(vector<vector<int>>& board,int coloumn,int row){
        int i=row;
        int j=coloumn;
        while(i>=0&&j>=0){
            if (board[i][j]==1){
            row=i;
            return false;}
            else{ 
                 i--;
                 j--;}
        }
        return true;
       
    }
    bool upper_right_diagnol(vector<vector<int>>& board,int coloumn,int row){
        int i=row;
        int j=coloumn;
        while(i>=0&&j<board.size()){
            if (board[i][j]==1){
            return false;}
           else{ i--;
            j++;}
        }
    return true;
    }
    bool can_place(vector<vector<int>>& board,int coloumn,int row){
    if (right_row(board,coloumn,row)&&upper_diagnol(board,coloumn,row)&&upper_right_diagnol(board,coloumn,row)){
        return true;
    }
    else return false;
    }
    void solve(vector<vector<int>>& board,int coloumn,int& count,int row,int n1){
        if ( n1==0){
            count++;
            return;
        }
        if (row>=board.size()||coloumn>board.size()) return;
        for (int i=0;i<board.size();i++){
        if (can_place(board,i,row)){
            board[row][i]=1;
            solve(board,coloumn+1,count,row+1,n1-1);
            board[row][i]=0;
        }
    }
    }

    int totalNQueens(int n) {
      vector<vector<int>> board(n, vector<int>(n, 0));
      int n1=n;
      int row=0;
      int coloumn=0;
      int count=0;
      solve(board,coloumn,count,row,n1);
      return count;
    }
};