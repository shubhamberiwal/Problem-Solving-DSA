



#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define ll long long
typedef vector<int> vi;
typedef pair<int,int> pi;


// fermats theorem states that
// a^(p-1) % p = 1 where p is a prime number and 1<=a<=p

// this is the proof of fermats theorem a bit difficult. So if you don't 
// want to proceed i can understand
// a%p, (2a)%p, ...., ((p-1)a)%p = 1,2,3,4,5,6,....,p-1
// for 2 no.s (i*a)%p == (j*a)%p condition for this is (a*(i - j))%p==0
// proof of this is that a is not a multiple of p and i and j are from 
// 1 to p-1 so they too cant be multiple of p so we will get all distinct
// numbers from this

// (a*2a*3a*...*(p-1)a) % p = ((p-1)! * (a^(p-1)) % p)
// now (a*2a*3a*...*(p-1)a) % p = (1.2.3.4.5...p-1)%p
// so from above we conclude that (p-1)!%p = (p-1)!*(a^(p-1))%p
// cancelling from both sides we get 1 = (a^(p-1))%p hence we prove the fermats theorem

const ll mod = 101;

ll power_expo(ll a, ll b){
    if(b==0)
        return 1;
    ll x = power_expo(a, (b/2));
    ll ans = 1;
    if(b&1){
        ans = ( x * x )%mod;
        ans = ( ans * a )%mod;
    }
    else ans = ( x * x ) % mod;
    return ans;
}


// calculating modulo inverse
// for ((a/b) % mod) = (a * b^(mod-2)) % mod
int compute(int a, int b){
    return (a * power_expo(b,mod-2))%mod;
}

int values[mod];
int main()
{
    // int a = 23;
    // int inva = power_expo(a,mod-2);
    // cout<<inva;
    cout<<compute(3,7);
    return 0;
}

