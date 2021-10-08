

#include<bits/stdc++.h>
using namespace std;

class NQueen1st{

    public:
    // 1st soln. - checking part if queen is safe to put in a cell
    bool checkqueenissafe( int row, int col, vector<string> &board, int n)
    {
        // if col is 0 that means it is checking for the 1st queen on the board
        if(col==0) return true;

        for (int i = 0; i < col; i++)
        {
            if( board[row][i] == 'Q' ) return false;
        }
        

        int duprow = row;
        int dupcol = col;

        // check if a queen already in the upper diagonal
        while(col>=0 && row>=0){
            if(board[row][col]=='Q') return false;
            col--; row--;
        }

        // row = duprow;
        // col = dupcol;

        // checking if any previous queen on the same row    
        // while( col>=0 ){
        //     if( board[row][col] == 'Q' ) return false;
        //     col--;
        // }

        row = duprow;
        col = dupcol;

        // check if a queen already in the lower diagonal
        while( row<n && col>=0){
            if ( board[row][col] == 'Q') return false;
            row++; col--;
        }
        return true;
    }

    // part of 1st soln. - n queen problem
    void nqueen(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if(col==n){
            // print matrix;
            ans.push_back(board);
            return;
        }
        // for loop starting from the zeroth row each time
        for (int row = 0; row < n; row++)
        {
            if( checkqueenissafe( row, col, board, n) )
            {
                board[row][col] = 'Q'; // first add queen in cell in this column
                col++; // increase the column by 1

                // call recursion
                nqueen( col, board, ans, n);

                col--; // backtracking the column too
                board[row][col] = '.'; // now backtrack and remove queen from cell
            }
        }
    }

    // 1st soln. - starting function
    vector<vector<string>> solveNqueens(int n){
        vector<vector<string>> ans;
        vector<string> board(n);
        string p(n, '.');
        for (int i = 0; i < n; i++){
            board[i] = p;
        }
        nqueen(0, board, ans, n);
        return ans;
    }
    
    void printnqueen( vector<vector<string>> &ans) {
        for(auto x: ans){
            for(auto y: x){
                cout<<y<<endl;
            }
            cout<<endl<<endl;
        }
    }

};





class NQueen2nd{
    
    // 2nd soln. - optimised function for checking nqueen
    // optimization is done by hashing or storing the previous queens 
    // and their positions in a array for checking for left row, upper left diagonal and lower left diagonal
    void nqueen2( int col, vector<string> &board, vector<vector<string>> &ans, int n,
                vector<int> &leftrow, vector<int> &upperdiagonal, vector<int> &lowerdiagonal)
    {
        if( col == n){
            ans.push_back(board);
            return;
        }
        
        for (int row = 0; row < n; row++)
        {
            if( leftrow[row] == 0 && lowerdiagonal[row+col]==0
                && upperdiagonal[ n-1 + col-row]==0) {

                    board[row][col] = 'Q';
                    leftrow[row] = 1;
                    lowerdiagonal[row+col] = 1;
                    upperdiagonal[n-1+col-row] = 1;
                    nqueen2(col+1, board, ans, n, leftrow, upperdiagonal, lowerdiagonal);
                    board[row][col] = '.';
                    leftrow[row] = 0;
                    lowerdiagonal[row+col] = 0;
                    upperdiagonal[n-1+col-row] = 0;
            }
        }
    }

    public:
    // 2nd soln. - starting function
    vector<vector<string>> solveNqueens2(int n){
        vector<vector<string>> ans;
        vector<string> board(n);
        string p(n, '.');
        for (int i = 0; i < n; i++){
            board[i] = p;
        }
        vector<int> leftrow(n,0), upperdiagonal(2*n-1, 0), lowerdiagonal(2*n-1, 0);
        nqueen2(0, board, ans, n, leftrow, upperdiagonal, lowerdiagonal);
        return ans;
    }

    void printnqueen( vector<vector<string>> &ans ){
        for(auto x: ans){
            for(auto y: x){
                cout<<y<<endl;
            } cout<<endl;
        }
    }

};



int main()
{
    // NQueen1st nq1;
    // vector<vector<string>> ans = nq1.solveNqueens(4);
    // nq1.printnqueen(ans);

    // not working currently
    NQueen2nd nq2;
    vector<vector<string>> ans2 = nq2.solveNqueens2(5);
    nq2.printnqueen(ans2);
}


