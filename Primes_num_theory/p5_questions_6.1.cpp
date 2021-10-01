#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

// given N, and given q queries, in each query given a number k you have to find
// the count of common divisors(maybe question means factors) of n and k
// N <= 10^12, K <= 10^12 and Q <= 5*10^5

// 1st Naive approach will be to generate all factors or divisors of N which can be done
// in sqrt(n) time. 
// Then for each query, for each divisor of n, if it also divides k then count++;
// tc roughly: O ( sqrt(n) + (q * (n^(1/3)) ) )

// 2nd Naive approach will be to find the gcd of N and K, and let the gcd be g
// then you can simply find the number of divisors of G and that will be your answer
// tc: O ( q * (log(n) + sqrt(gcd)) ) which is roughly (q*(n^(1/2)))

// best approach is to first get the prime factorization of n in sqrt(n) time
// and store it in some map variable then for each query input k.
// now for every prime number 'p' in prime factorization of n count the number of times
// 'p' divides k 
// now for each prime find the minimum count from both N and K and then calculate the total divisors

// tc: O((log N)^2)

map<int,int> primefactorization(int n) {
    map <int,int> mpp;
    int cnt;
    for (int i = 2; i*i < n; i++)
    {
        if(n%i==0) {
            cnt=0;
            while(n%i==0) {
                n/=i;
                cnt++;
            }
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
        map <int,int> pf_of_k;
        int cnt;

        for(auto prime: primes_of_n) {
            int p = prime.first;
            cnt = 0;
            while(k%p==0){
                k=k/p;
                cnt++;
            }
            pf_of_k[p] = cnt;
        }
        int res = 1;
        for(auto prime: primes_of_n){
            int cnt1 = prime.second;
            int cnt2 = pf_of_k[prime.first];
            int select = min(cnt1,cnt2);
            res = res * (select+1);
        }
        cout<<"Common divisors between n and k are: "<<res<<endl;
    }
    
    
    return 0;
}






