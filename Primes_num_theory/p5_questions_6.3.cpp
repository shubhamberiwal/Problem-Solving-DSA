

// https://www.codechef.com/problems/QNUMBER

#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef pair<ll, ll> pi;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;


map<ll,ll> primes_of_n;
ll total;
void primefactorization(ll n) {
    total = 1;
    for (ll i = 2; i*i <= n; i++)
    {
        if(n%i==0) {
            int cnt=0;
            while(n%i==0) 
                n/=i, cnt++;
            primes_of_n[i] = cnt;
            total *= (cnt+1);
        }
    }
    if(n>1) primes_of_n[n] = 1,total *= 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    ll n,q,k,t; 
    cin>>n>>q;
    primefactorization(n);
    
    while(q--)
    {
        cin>>t>>k;
        ll ans = 0;    
        if(t==1) {
            ll res = 1;
            for(pi p: primes_of_n) 
            {
                ll cnt = 0;
                while(k%p.first==0)
                    k=k/p.first, cnt++;
                res *= (min(p.second,cnt)+1);
            }
            cout<<res<<endl;
        }
        else{
            ll res = 1;
            for(pi pairr: primes_of_n) {
                ll cnt = 0;
                while( k % pairr.first==0)
                    cnt++, k=k/pairr.first;
                if(cnt > pairr.second){
                    res = 0;
                    break;
                }
                res *= (pairr.second - cnt+1);
            }
            if(k>1) res = 0;
            if(t==2) 
            cout<<res<<endl;
            else cout<<total-res<<endl;
        }
    }
}

// alternative way to calculate when t==2 and t==3
        // else {
        //     map <ll,ll> pf_of_k = primefactorization(k);
        //     ll cnt;
        //     // ll total = total;
        //     // map <ll,ll> base;
        //     vi arrd;
        //     ll res = 1;
        //     ll flag = 0;
        //     for( auto primes: pf_of_k) {
        //         ll p = primes.first;
        //         ll cnt1 = primes.second;
        //         ll cnt2 = primes_of_n[p];
        //         ll diff = cnt2-cnt1+1;
        //         if( diff > 0 ) {
        //             res = res * (diff);
        //             arrd.pb(p);
        //         }
        //         else {
        //             flag = 1;
        //             break;
        //         }
        //     }
        //     if(flag == 0)
        //         for(auto prime: primes_of_n) {
        //             ll p = prime.first;
        //             if( find(arrd.begin(),arrd.end(),p)==arrd.end() ) {
        //                 res = res * (prime.second+1);
        //             }
        //         }
        //     if(flag) {
        //         res = 0;
        //     }
        //     if(t==2) ans = res;
        //     else ans = total-res;
        // }






