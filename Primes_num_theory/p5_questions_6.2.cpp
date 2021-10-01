#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

// given N, and given q queries, in each query given a number k you have to find
// the count of divisors of N that are also divisible by k
// N <= 10^12, K <= 10^12 and Q <= 5*10^5

// best approach is to first get the prime factorization of n in sqrt(n) time
// and store it in some map variable then for each query input k.
// now total factors of N are (cnt(p1)+1) * (cnt(p2)+1) * ... * (cnt(pk)+1)
// also prime factorization of k will be something now for factors that are divisible by k
// the factors must have atleast the prime factors of k in their own prime factorization
// we will use this logic to find our answer


long long total_factors=1;
map<int,int> primefactorization(int n) {
    map <int,int> mpp;
    int cnt;
    for (int i = 2; i*i <= n; i++)
    {
        if(n%i==0) {
            cnt=0;
            while(n%i==0) {
                n/=i;
                cnt++;
            }
            total_factors *= (cnt+1);
            mpp[i] = cnt;
        }
    }
    if(n>1) mpp[n] = 1;
    return mpp;
}


int main()
{
    int n; cin>>n;
    map<int,int> primes_of_n = primefactorization(n);
    int q; cin>>q;
    while(q--){
        int k; cin>>k;
        map <int,int> pf_of_k = primefactorization(k);
        int cnt;
        // map <int,int> base;
        vi arrd;
        int res = 1;
        int flag = 0;
        for( auto primes: pf_of_k) {
            int p = primes.first;
            int cnt1 = primes.second;
            int cnt2 = primes_of_n[p];
            int diff = cnt2-cnt1+1;
            if( diff > 0 ) {
                res = res * (diff);
                arrd.pb(p);
            }
            else {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        for(auto prime: primes_of_n) {
            int p = prime.first;
            if( find(arrd.begin(),arrd.end(),p)==arrd.end() ) {
                res = res * (prime.second+1);
            }
        }
        if(flag){
            res = 0;
        }
        cout<<"# of Divisors of n that k divides are: "<<res<<endl;
    }
    return 0;
}






