


#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vi> dp(n+1,vi(m,-1));
    vector<vi>matrix(n,vi(m));
    min_cost_path_dp(0,0,n,m,matrix,dp);
    return 0;
}

// minimum cost path dynamic programming
int min_cost_path( int i, int j, int n, int m, vector<vi>&matrix)
{
    if( i==n-1 && j==m-1 ) {
        return matrix[i][j];
    }
    // abhi ka add karke aage ka call kar dijiye
    // matrix[i][j] + 
    int curr = matrix[i][j];
    int restd=100,restr=100;
    if(i<n-1) {
        restd = min_cost_path(i+1,j,n,m,matrix);
    }
    if(j<m-1){
        restr = min_cost_path(i,j+1,n,m,matrix);
    }
    return curr+min(restr,restd);
}


// so the parameters that were changing here were i and j
// i ranged from 0 to n-1 and j from 0 to m-1
// aur dp[i][j] store karega the minimum cost 
// from that point to the destination
int a = 1;
int min_cost_path_dp( int i, int j, int n, int m, vector<vi>&matrix, vector<vi>&dp)
{
    if( i==n-1 && j==m-1 )
        return matrix[i][j];
    
    if( i>=n || j>=m ) return INT_MAX;

    if( dp[i][j]!=-1 ) return dp[i][j];

    int rest_down = min_cost_path_dp(i+1,j,n,m,matrix,dp);
    int rest_right = min_cost_path_dp(i,j+1,n,m,matrix,dp);

    dp[i][j] = matrix[i][j]+min(rest_right,rest_down);

    return dp[i][j];
}




