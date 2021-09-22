
/*
Implement 0/1 Knapsack problem using dynamic programming.Analyze its time efficiency

*/
#include <bits/stdc++.h>
using namespace std;
 

int knapSackRec(int W, int wt[],
                int val[], int i,
                int** dp)
{
    // base condition
    if (i < 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];
 
    if (wt[i] > W) {
 
        
        dp[i][W] = knapSackRec(W, wt,
                               val, i - 1,
                               dp);
        return dp[i][W];
    }
    else {
        
        dp[i][W] = max(val[i]
                      + knapSackRec(W - wt[i],
                                   wt, val,
                                   i - 1, dp),
                       knapSackRec(W, wt, val,
                                   i - 1, dp));
        return dp[i][W];
    }
}
 
int knapSack(int W, int wt[], int val[], int n)
{
    
    int** dp;
    dp = new int*[n];
 
    
    for (int i = 0; i < n; i++)
        dp[i] = new int[W + 1];
 
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    return knapSackRec(W, wt, val, n - 1, dp);
}
 

int main()
{   
    int n;
    cout<<"Enter the size\n";
    cin>>n;
    
    int val[n];
    int wt[n];
    int W;
    cout<<"Enter the values and weight in ascending order only\n";
    cout<<"Enter the values\n";
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    
    cout<<"Enter the weight\n";
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout<<"Enter the Weight of Bag\n";
    cin>>W;
    cout<<"Profit is "<< knapSack(W, wt, val, n);
    return 0;
}