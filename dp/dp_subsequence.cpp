

#include<bits/stdc++.h>
using namespace std;







// longest common subsequence
// eg: a,b,c,d,e,f and b,d,f,e will be b,d,f
// bottom up memoization approach (dp)
int lcs(int i, int j, string s1, string s2, vector<vector<int>>&dp )
{
    if( i>=s1.size() || j >= s2.size() )
    { return 0; }
    if( dp[i][j]!=-1 ){
        return dp[i][j];
    }
    if( s1[i] == s2[j] ){
        dp[i][j] = 1 + lcs(i+1,j+1,s1,s2,dp);
    }
    else{
        int left = lcs(i+1,j,s1,s2,dp);
        int right = lcs(i,j+1,s1,s2,dp);
        dp[i][j] = max(left,right);
    }
    return dp[i][j];
}
// top down dp
int lcs2(int i , int j, string s1, string s2, vector<vector<int>> &dp)
{
    if(i<0 || j<0)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    if( s1[i] == s2[j] )
        dp[i][j] =  1+lcs2(i-1,j-1,s1,s2,dp);
    else{
        int left = lcs2( i-1, j, s1, s2, dp);
        int right = lcs2( i, j-1, s1, s2, dp);
        dp[i][j] = max(left, right);
    }
    return dp[i][j];
}
//brute force recursive approach
int lcsRecursive(int i, int j, string s1, string s2)
{
    if( i>=s1.size() || j >= s2.size() )
    { return 0; }
    if( s1[i] == s2[j] ){
        i++; j++;
        return 1 + lcsRecursive(i,j,s1,s2);
    }
    int left = lcsRecursive(i+1, j, s1, s2);
    int right = lcsRecursive(i, j+1, s1, s2);
    return max(left,right);
}
int main()
{
    string s1,s2;
    cin>>s1;
    cout<<"sjdkfl\n";
    cin>>s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    // int k = lcs(0,0,s1,s2,dp);
    // cout<<k;
    //if using lcs2 remember to put n-1 and m-1
    cout<<lcs2(n-1,m-1,s1,s2,dp);
    return 0;
}