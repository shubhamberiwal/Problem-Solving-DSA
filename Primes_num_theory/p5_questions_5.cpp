

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;


// https://codeforces.com/problemset/problem/1444/A

// Question is to find x. Given x should be a factor of p and 
// x isn't a multiple of q
// p<=1e18 and q<=1e9

// optimal approach
vi prime_factorization(int n) {
    vi primes;
    for (int i = 2; i*i <= n; i++)
    {
        if(n%i==0){
            ll cnt = 0;
            while(n%i==0)
                n/=i, cnt++;
            primes.pb(i);
        }
    }
    if(n>1) primes.pb(n);
    return primes;
}

int main()
{
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    cin.tie(NULL);
    cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        ll p,q; cin>>p>>q;
        if(p%q>0) {
            cout<<p<<endl;
            continue;
        }
        vi pf_of_q = prime_factorization(q);
        ll ans=1;

        for( int prime: pf_of_q) {
            // prime contains a prime factor of p
            ll x = p;
            while( x % q == 0) {
                x /= prime;
            }
            // at this point we can say that x isn't a multiple of q now
            // also x is a factor of p
            ans = max(ans,x);
        }
        cout<<ans<<endl;
    }
    return 0;
}

    


// not optimal because it is O(sqrt(p)) which is still 10^9
// there is slow
// int main()
// {
//     ll p,q; cin>>p>>q;
//     ll ans=0;
//     for (ll i = 2; i*i <= p; i++)
//     {
//         if(p%i==0) {
//             if(i%q!=0)
//                 ans = max(i,ans);
//             if((p/i)%q!=0)
//                 ans = max((p/i),ans);
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }




