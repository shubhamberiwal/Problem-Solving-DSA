


#include<bits/stdc++.h>
using namespace std;


// print prime factorization of a number n
// this takes O(N) time complexity in worst case
void primefactorization(int n){
    for (int i = 2; i <= n; i++)
    {
        while(n%i==0){
            cout<<i<<" ";
            n=n/i;
        }
    }
}
// this works because every number has a prime factorization that is <= sqrt(n)
void primefactorization(int n){
    for (int i = 2; i*i <= n; i++)
    {
        while(n%i==0){
            cout<<i<<" ";
            n=n/i;
        }
    }
    if(n>1) cout<<n;
}

// given t queries (t<=10^6) each having a number n(n<=10^6)
// print prime factorization of each number
// initialise each element as i itself in sieve array or black box
// so that we, later on know that if(sieve[i] == i) then i is a prime no.
// and the prime factorization of i is i itself because prime. duh!!
const int N = 1000000;
int spf[N+1]; // stores the smallest prime factor of that number
void createprimefactorizationsieve(){
    for (int i = 2; i <= N; i++)
        spf[i] = i;
    for (int i = 2; i*i < N; i++)
    {
        if( spf[i] == i ){
            for (int j = i*i; j <= N; j+=i)
            {
                if( spf[j]==j )
                    spf[j] = i;
            }
        }
    }
}
// one thing to note is that a number at max may have log (base 2) n prime factors
// the reason is that lowest prime factor is 2 so for eg:
// 16 is 2^4, has 4 prime factors; 32 is 2^5, has 5 prime factors
// but 100 is 2^2*5^2 and has only 4 prime factors. this is because it had a prime factor 5 twice
// which is bigger than 2, so its multiplication will also be greater than 2.
// and we know that 2 is the smallest prime no. therefore we can say that log n (base 2) will
// give the maximum prime factors a number can have
int main(){
    // O(n*log(log n))
    createprimefactorizationsieve();
    int q;cin>>q;
    while(q--){
        int n; cin>>n;
        // O(log n)
        while(n!=1){
            cout<<spf[n]<<" ";
            n = n / spf[n];
        }
        cout<<endl;
    }
}
int main()
{
    int n; cin>>n;
    primefactorization(n);

    return 0;
}

