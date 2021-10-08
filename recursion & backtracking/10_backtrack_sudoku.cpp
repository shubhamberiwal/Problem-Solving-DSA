

#include<bits/stdc++.h>
using namespace std;


// You just have to keep finding the next empty cell then try 
// 1 - 9 all numbers that can be valid to be in that cell 
// (you can do this by running a valid function check) then 
// keep calling the function recursively and the process terminates
// once there is no more empty space cell left then it returns true;
class Sudoku
{
    public:

    void solveSudoku(vector<vector<char>> &board) {
        solve(board);
    }

    bool solve( vector<vector<char>> &board){
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                
                if( board[i][j] == '.' ){

                    for (char c = '1'; c <= '9' ; c++){
                        if( isvalidentry(board, i, j, c) ){
                            board[i][j] = c;
                            
                            if(solve(board)==true)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isvalidentry( vector<vector<char>> &board, int row, int col, char c){
        for (int i = 0; i < 9; i++){
            if(board[i][col] == c)
                return false;
            if(board[row][i] == c)
                return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
                return false;
        }
        return true;
    }

    void printsudoku( vector<vector<char>> &board)
    {
        for(auto x: board){
            for(auto y: x){
                cout<<y<< " ";
            }
            cout<<endl;
        }
    }

};


int main()
{
    Sudoku sod;
    vector<vector<char>> board(9,vector<char> (9,'.'));
    sod.solveSudoku(board);
    sod.printsudoku(board);
    // solveSudoku(board);
    return 0;
}
