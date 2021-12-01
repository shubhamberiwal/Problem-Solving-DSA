


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


// longest increasing subsequence
int longestis(int n, vi&arr)
{
    vi lis(n);
    lis[0] = 1;
    for(int i=1; i<n; i++)
    {
        lis[i] = 1;
        for(int j=0; j<i; j++)
        {
            if (arr[i]>arr[j] &&  lis[i] < lis[j]+1)
                lis[i] = lis[j] + 1;
        }
    }
    return *max_element(lis.begin(),lis.end());
}



