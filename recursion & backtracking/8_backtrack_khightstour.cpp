


#include<bits/stdc++.h>
using namespace std;

vector<int> touri = {-2,-1,+1,+2,+2,+1,-1,-2};
vector<int> tourj = {+1,+2,+2,+1,-1,-2,-2,-1};
bool isSafe( int i, int j,int n, int m, vector<vector<int>> &result){
    if( i>=0 && j>=0 && j<m && i<n && result[i][j]==-1)
        return true;
    return false;
}
int khightstour(int i, int j, int n, int m, int count, vector<vector<int>> &result){
    
    // this sort of negative base case will not work in problems like 
    // sudoku or knightstour simply because in the first recursion call
    // itself the last check of result[i][j]!=-1 will be true because result[0][0] = 0
    // so in problems like these its better to check in a separate function
    // just before progressing with a move. Don't forget this thing
    // if( i<0 || j<0 || i>=n || j>=m || result[i][j]!=-1) 
    //     return;
    
    if(count==(n*m)){
        for(auto x: result){
            for(auto y: x){
                cout<<setw(2)<<y<<" ";
            }
            cout<<endl;
        }
        return 1;
    }

    for (int x = 0; x < 8; x++)
    {
        int nexti = i+touri[x];
        int nextj = j+tourj[x];
        if( isSafe(nexti, nextj, n, m, result) ){
            result[nexti][nextj] = count;
            if( khightstour( nexti, nextj, n, m, count+1, result) )
                return 1;
            result[nexti][nextj] = -1;
        }
    }
    return 0;
}
// one cooler way is for this 'knightstour' function to have void return type
// and hence mofify all return calls now to terminate the program
// just add exit(0); line in the base case just after printing the result
// and no need to return there because program will terminate.
// This works because in question you've been asked to find 1 solution,
// as soon as you find it just terminate it mate!

int main(){
    int n=5;
    int m=5;
    // vector<vector<int>> visited(n, vector<int> (m,0));
    vector<vector<int>> result(n, vector<int> (m,-1));
    result[0][0] = 0;
    khightstour( 0, 0, n, m, 1, result);
    return 0;
}



