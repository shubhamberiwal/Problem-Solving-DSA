
#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

// given weights and value of n items, put these items in a knapsack of capacity W to get the 
// the bag has to filled in such a way that his bag is not overfilled and the value is maximised


int knapsack( int ind, int W, vi&val, vi&wt, int n)
{
    if(ind>=n) return 0;

    if(W==0) return 0;

    if( wt[ind] <= W ) {
        int left = val[ind] + knapsack( ind+1, W-wt[ind], val, wt, n);
        int right = knapsack( ind+1, W, val, wt, n);
        return max(left,right);
    }
    else {
         return knapsack( ind+1, W, val, wt, n);
    }
}

// now ind is changing from 0 to n-1. Total no. of values of ind is n
// and w is changing from 0 to W. Total no. of values of W is W+1
int knapsack_dp( int ind, int W, vi&val, vi&wt, int n, vector<vi>&dp)
{
    if(ind>=n) return 0;

    if(W==0) return 0;

    if(dp[ind][W]!=-1) return dp[ind][W];

    if( wt[ind] <= W ) {
        int left = val[ind] + knapsack_dp( ind+1, W-wt[ind], val, wt, n, dp);
        int right = knapsack_dp( ind+1, W, val, wt, n, dp);
        dp[ind][W] = max(left,right);
        return dp[ind][W];
    }
    else {
        dp[ind][W] = knapsack_dp( ind+1, W, val, wt, n, dp);
        return dp[ind][W];
    }
}


int main()
{
    int n=3;
    vi wt={25,25,30};
    vi val={100,100,180};
    int W=50;
    
    cout<<knapsack(0,2,val,wt,n);    
    
    vector<vi> dp(n,vi(W+1,-1));
    cout<<knapsack_dp( 0, W, val,wt, n, dp);

    return 0;
}




