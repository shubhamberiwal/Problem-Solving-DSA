
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
#define NIL -1
// Memoization (top down)
int lookup[MAX];
void _initialize()
{
    for (int i = 0; i < MAX; i++){
        lookup[i] = NIL;
    }
}
int fib(int n)
{
    if(lookup[n] == NIL)
    {
        if( n<=1 )
            lookup[n] = n;
        else
            lookup[n] = fib(n-1) + fib(n-2);
    }
    return lookup[n];
}

// tabulation bottom up
int fib(int n)
{
    int f[n+1];
    int i;
    f[0] = 0; f[1] = 1;
    for (int i = 2; i <= n; i++)
        f[i] = f[i-1] + f[i-2];
    return f[n];
}
int main()
{
    
    
    return 0;
}

// longest increasing subsequence problem
// it returns only the length of the lis
// but it also prints the subsequence and it is stored in vector
int lis(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {

        lis[i] = 1;
        for (int j = 0; j <=i ; j++)
        {
            if(arr[j]<arr[i] && lis[i]<lis[j]+1)
                lis[i]++;
        }
    }
    // finding the largest value stored in the array and that will be length of lcs
    int maxi = lis[0], ind=0;
    for (int i = n-1; i >=0; i--)
    {
        if(lis[i]>maxi){
            maxi = lis[i]; ind = i;
        }
    }

    // printing the subsequence
    vector<int> sq;
    sq.push_back(arr[ind]);
    for (int i = ind-1; i>=0; i--)
    {
        if( lis[ind] - lis[i] == 1 && arr[i]<arr[ind]){
            sq.push_back(arr[i]);
            ind = i;
        }
    }
    reverse(sq.begin(),sq.end());
    for(auto x: sq)
        cout<<x<<" ";
    cout<<endl;
    
    return *max_element(lis,lis+n);
}

