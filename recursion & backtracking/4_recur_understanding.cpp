
#include<bits/stdc++.h>
using namespace std;


// 8 - 
// refer to problem 7 then understand this.
// count the number of paths from start to end in a matrix
// where it will be filled with either 0's or 1's and you
// are allowed to go only in 1's and not in 0's
int matrix[][10];
int oneand0matrixdest(int i, int j, vector<vector<int>> &vis){

    if( i>=n || j>=m || i<0 || j<0 || vis[i][j] == 1 || matrix[i][j] == 0) return 0;

    if( i==n-1 && j==m-1 ){
        return 1;
    }

    vis[i][j] = 1;
    int cnt = 0;
    for (int a = 0; a < 4; a++){
        cnt += oneand0matrixdest( i+di[a], j+dj[a], vis);
    }
    vis[i][j] = 0;
    return cnt;
}

