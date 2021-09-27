

// https://www.spoj.com/problems/PRIME1/

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

int maxn = 1e5+1;
vi sieve(maxn,1);
vi primes;
vi customsieve;

void sievealgo() {
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i*i < maxn; i++) {
        if(sieve[i]) {
            for (int j = i*i; j < maxn; j+=i)
                sieve[j] = 0;
        }
    }
    for (int i = 2; i < maxn; i++) {
        if(sieve[i]) {
            primes.pb(i);
            // if(primes.size()==sqrt(r)){
            //     break;
            // }
        }
    }
}

void segmented_sieve(int l, int r){
    
    if(l==1) l++; // if not done this then it will give 1 as prime in the range l to r

    // for each prime p in primes array (which is in the range 2 to sqrt(r))
    // mark every multiple of each prime
    int siz = r-l+1;
    customsieve.assign(siz,1);
    
    for ( auto p : primes ) {
        if( p*p <= r ) {

            int x = (l/p) * p;
            if(x<l) x+=p;
            
            for (int j = x; j <= r; j+=p ) {
                if( j!=p )
                customsieve[j-l] = 0;
            }
        }
        else break;
    }
    for (int i = 0; i < siz ; i++) {
        if(customsieve[i]) {
            cout<<l+i<<endl;
        }
    }
}


int main()
{
    sievealgo();
    int t; cin>>t;
    while(t--){
        int l,r; cin>>l>>r;
        segmented_sieve(l,r);
    }
    return 0;
}




