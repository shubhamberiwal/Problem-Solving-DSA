

#include<bits/stdc++.h>
using namespace std;

// Rat in a Maze (gfg)
// rat placed at (0,0) in square matrix of n*n. Destination is (n-1, n-1).
// Rat can move in 4 directions {U, D, R, L}. Now maze/matrix is filled with
// either 0 or 1. Rat cannot take path with 0, can only go in squares with 1.

class ratinmaze2{
    void ratinamaze( int i, int j, string storepath, vector<string> &ans, vector<vector<int>> &vis, 
                    string path, vector<int> &di, vector<int> &dj, int n, vector<vector<int>> &matrix )
    {
        if( i<0 || j<0 || i>=n || j>=n || (matrix[i][j] == 0) || (vis[i][j]==1) )
            return;
        // base case for true condition
        if( i==n-1 && j==n-1 ){
            ans.push_back(storepath);
            return;
        }
        for (int k = 0; k < 4; k++)
        {
            vis[i][j] = 1;
            storepath += path[k];
            ratinamaze( i+di[k], j+dj[k], storepath, ans, vis, path, di, dj, n, matrix );
            storepath.pop_back();
            vis[i][j] = 0;
        }
    }
    public:
    vector<string> ratrat(int n, vector<vector<int>> &matrix)
    {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n,0));
        string path = "DLRU";
        vector<int> di = {1, 0, 0, -1};
        vector<int> dj = {0, -1, 1, 0};
        ratinamaze( 0, 0, "" , ans, vis, path, di, dj, n, matrix);
        return ans;
    }
    void printanswers(vector<string> &ans){
        for(auto x: ans){
            cout<<x<<endl;
        }
    }
};


// 2nd solution same as above just a little different
// more organised than above tho
class Ratinamaze {
    
    void solverat( int i, int j, int n, vector<vector<int>> &vis, vector<vector<int>> &matrix,
                   vector<string> &ans, string storepath, string demopath, vector<int> &di, vector<int> &dj){

        if( i==n-1 && j==n-1 ){
            ans.push_back(storepath);
            return;
        }
        for (int ind = 0; ind < di.size(); ind++)
        {
            int newi = i+di[ind];
            int newj = j+dj[ind];
            if( newi >= 0 && newj >= 0 && newi < n && newj < n && vis[newi][newj] == 0 && matrix[newi][newj] == 1 ) {
                vis[i][j] = 1;
                storepath += demopath[ind];
                solverat( newi, newj, n, vis, matrix, ans, storepath, demopath, di, dj);
                storepath.pop_back();
                vis[i][j] = 0;
            }
        }
    }

    public:
    vector<string> ratrat(vector<vector<int>> &matrix, int n){

        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n,0));
        string demopath = "DLRU";
        vector<int> di = {1,0,0,-1};
        vector<int> dj = {0,-1,1,0};
        solverat( 0, 0, n, vis, matrix, ans, "", demopath, di, dj);
        return ans;
    }
    void printanswers(vector<string> &ans){
        for(auto x: ans){
            cout<<x<<endl;
        }
    }
};

int main()
{
    // (5,vector<int>(5))
    vector<vector<int>> matrix = {  {1,1,1,0,1},
                                    {1,1,0,1,0},
                                    {1,1,1,1,1},
                                    {0,1,0,1,1},
                                    {1,1,1,1,1} };
    // Ratinamaze maze;
    // vector<string> ans1 = maze.ratrat(matrix, 5);
    // maze.printanswers(ans1);
    
    ratinmaze2 maz;
    vector<string> ans2 = maz.ratrat(5, matrix);
    maz.printanswers(ans2);
    return 0;
}