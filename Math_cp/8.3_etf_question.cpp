

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

// question is to find the [ summation of gcd(i,N) ] : where N is user input and i ranges from 1 to N
// we will use etf and primes
// first we will calculate all divisors of n in sqrt(n) time and then for each divisor 'd' we can get 
// the number of integers from 1 to n that are having gcd with n as 'd' in constant time. Constant time
// is possible because first we use math to simplify the idea and then use etf precalculate the required 
// result. Precalculation take O(nlog n) time

// total tc: O ( nlog n + (q*sqrt(n) ) )

int maxn = 1e6+1;
vi phi(maxn);

// precalculating phi(n) for all n upto 10^6
void sievealgo() {
    for (int i = 1; i < maxn; i++)
        phi[i] = i;
    phi[0] = phi[1] = 0;

    for (int i = 2; i < maxn; i++)
    {
        if(phi[i] == i) {
            for (int j = i; j < maxn; j+=i)
            {
                phi[j] = (phi[j] * (i-1)) / i;
            }
        }
    }
}
// returns how many integers are there from 1 to n that have gcd with n = d
int getcount(int d, int n){
    return phi[n/d];
}

// tc: O(nlog n) + O(q*sqrt(n))
// (nlog n) time for precomputing phi[] function that stores at particular index i
// the number from 1 to i-1 that are co prime with i
int main()
{
    int q ; cin>>q;
    while(q--){
        int n; cin>>n;
        int res = 0;
        for (int i = 1; i*i <= n; i++)
        {
            if(n%i==0){
                int d1 = i;
                int d2 = n/i;

                // getcount(d1,n) will return how many numbers are there from 1 to n that have
                // gcd(i,n) = d1;
                res += d1*getcount(d1,n);
                if(d2!=d1) res += d2*getcount(d2,n);
            }
            cout<<res<<endl;
        }
    }
    return 0;
}



