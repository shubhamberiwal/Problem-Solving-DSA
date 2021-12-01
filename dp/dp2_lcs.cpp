


// coin change dynamic programming question

#include<bits/stdc++.h>
#define fer(i,a,b) for(re i = a; i<b; ++i)
#define re register int
#define sf(x) scanf("%d", &x)
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    int t=1; cin>>t;
    while(t--)
    {
        int n=1; cin>>n; vector<int> arr(n);
        fer(i,0,n)
            cin>>(arr[i]);
        
        
    }
    return 0;
}





// normal recursive function of lcs
int lcs( int i, int j, string s1, string s2)
{
    if(i>=s1.size() || j>=s2.size()) {
        return 0;
    }
    if(s1[i] == s2[j] )
    {
        int c = lcs(i+1,j+1,s1,s2);        
        return c+1;
    }
    int left = lcs(i+1,j,s1,s2);
    int right = lcs(i,j+1,s1,s2);
    return max(left,right);
}





// bottom up dp approach of lcs
// 
int lcs( int i, int j, string s1, string s2, vector<vi>&dp)
{
    if(i>=s1.size() || j>=s2.size()) {
        return 0;
    }
    if( dp[i][j] != -1 ) return dp[i][j];
    
    if( s1[i] == s2[j] ) {
        dp[i][j] = 1 + lcs(i+1,j+1,s1,s2);
        return dp[i][j];
    }
    int left = lcs(i+1,j,s1,s2);
    int right = lcs(i,j+1,s1,s2);
    dp[i][j] = max(left,right);
    return dp[i][j];
}





int fib(int n)
{
    if(n<2) return n;
    return fib(n-1)+fib(n-2);

}

// int fib(int n, vi&dp)
// {
//     if(n<=1) return n;
//     // if previously the state has been visited
//     // then return the value straight away
//     if( dp[n]!=-1 ) return dp[n];
//     // memoize the answer
//     dp[n] = fib(n-1,dp) + fib(n-2,dp);
//     // return the answer
//     return dp[n];
// }
// int main()
// {
//     int n;
//     vi dp(n+1,-1);
//     int ans = fib(n,dp);
//     cout<<ans;
// }
// longest common subsequence





