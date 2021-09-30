


// https://codeforces.com/problemset/problem/742/A

#include<bits/stdc++.h>
#define fer(i,a,b) for(re i = a; i<b; ++i)
#define re register int
#define sf(x) scanf("%d", &x)
#define pb push_back
#define lli long long int
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;

lli power( lli a, lli n, lli p){
    lli res = 1;
    while(n){
        if(n&1) {
            res = (res * a)%p;
            n--;
        }
        else{
            a=(a*a)%p;
            n=n>>1;
        }
    }
    return res;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    cin.tie(NULL);
    int n; cin>>n;
        cout<<power(8,n,10);
    return 0;
}



