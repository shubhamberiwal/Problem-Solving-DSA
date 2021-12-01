

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;


// total number of ways batana hai isme


// solve this using a recursion tree of pick and not pick
int count(int ind, int sum, vi&arr, int n)
{
    if(sum==0) return 1;
    if( ind==n || sum<0 ) return 0;
    int left = count(ind, sum-arr[ind], arr, n);
    int right = count(ind+1, sum, arr, n);
    return (left + right);
}


// kya kya change ho rha hai? index and sum
// 2d dp array with ind and sum
// ind from 0 to n-1 so total n 
// and sum from 0 to sum so total sum+1 changes
int count_dp(int ind, int sum, vi&arr, int n, vector<vi>&dp)
{
    if(sum==0) return 1;

    if( ind>=n || sum<0 ) return 0;

    if( dp[ind][sum] != -1 ) return dp[ind][sum];

    int left = count_dp(ind, sum-arr[ind], arr, n, dp);
    int right = count_dp(ind+1, sum, arr, n, dp);

    dp[ind][sum] = left+right;
    return (left + right);
}


int main()
{
    int n;
    vi arr(n);
    int sum = 4;
    vector<vi> dp(n,vi(sum+1,-1));
    cout<<count_dp(0,sum,arr,n,dp);
    return 0;
}





