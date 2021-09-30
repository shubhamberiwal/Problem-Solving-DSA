#include<bits/stdc++.h>
#define pb push_back
#define mod 1000000007
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

// if you dont precompute TC: O(t*n)
// if you only precompute factorial of n numbers then TC: O(n + t * log (mod))
// if you precompute both factorial and inverse of factorial then TC: O( N*log(mod) + T )
// 4th method is the best way, here tc: O(N + T). Check notes for understanding theory of it

// tc: O( n + log (mod) )
// O(n) for precomputing factorial
ll power(ll a, ll n){
    if(n==0) {
        return 1;
    }
    ll res = power(a,n/2);
    ll ans = 1;
    if(n&1) {
        ans = (res * res) % mod;
        ans = (res * a) % mod;
    }
    else ans = (res*res) % mod;
    return ans;
}
ll inverse(ll n) {
    return power(n, mod-2);
}

// 1st solution - brute for way - contributes to O(t*n)
// ll fact(int n){
//     ll ans = 1;
//     for (int i = 2; i <= n; i++) {
//         ans = (ans*i) % mod;
//     }
//     return ans;
// }

// 3rd method
// precompute factorial and inverse factorial and store it in an array
// it contributes to O(n*log(mod) + t) time
// const int maxn = 1e6+1;
// ll factorial[maxn];
// ll inverse_factorial[maxn];
// ll precompute_factorial(){
//     factorial[0] = 1;
//     for(int i=1; i<maxn; i++){
//         factorial[i] = (factorial[i-1] * i) % mod;
//     }
//     for (int i = 1; i < maxn; i++) {
//         inverse_factorial[i] = inverse(factorial[i]);
//     }
// }

// 4th solution - best way
// here tc: O(n+t)
const int maxn = 1e6+1;
ll factorial[maxn];
ll inverse_factorial[maxn];
ll precompute_factorial(){
    factorial[0] = 1;
    for(int i=1; i<maxn; i++){
        factorial[i] = (factorial[i-1] * i) % mod;
    }
    inverse_factorial[maxn-1] = inverse(factorial[maxn-1]); 
    for (int i = maxn-2; i >= 0; i--) {
        inverse_factorial[i] = (inverse_factorial[i+1] * (i+1)) % mod ;
    }
}

int main()
{
    //int n; cin>>n;
    int t; cin>>t;
    precompute_factorial();
    while(t--) {
        int n,r; cin>>n>>r;
        ll nfact = factorial[n];
        // ll rfact = factorial[r];
        // ll nrfact = factorial[n-r];
        ll irfact = inverse_factorial[r];
        ll inrfact = inverse_factorial[n-r];
        // ll numerator = nfact;
        // ll denom = (nrfact * rfact) % mod;
        // ll ans = (numerator * inverse(denom)) % mod;
        ll ans = (nfact * ( (irfact * inrfact) % mod )) % mod;
        cout<<ans<<endl;
    }
    
    return 0;
}