
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

// 1 - find number of natural numbers <=N which is almost a prime
// almost a prime means if it is of the form (p1*p2), where p1!=p2
// and p1,p2 are primes.

//  The factors of a number can only be prime number and they should be appearing once only
// like 12 is not almost prime because 2*2*3 here 2^2 is not considered
// but 35 is almost prime because 5*7, both no.s are prime and appear once only and are not equal to each other.
// on further analysis we can say that the number with only 4 factors including itself and 1 are called almost primes. Think on this!


const int maxn = 1e5+1;

// 3rd method to solve
// problem statement is given below in 1st method
// using prime factorization
int spf[maxn];
void primeseive(){
    for (int i = 2; i <= maxn; i++)
        spf[i] = i;
    for (int i = 2; i*i < maxn; i++)
    {
        if(spf[i]==i){
            for (int j = i*i; j < maxn; j+=i)
            {
                if(spf[j]==j)
                    spf[j] = i;
            }        
        }
    }
}
int compute_answer(int n){
    int ans=0;
    for (int i = 1; i <= n; i++)
    {
        int a = spf[i];
        int b = spf[i/a];
        if( a!=b && spf[a]==a && spf[b]==b && a*b==i)
            ans++;
    }
    return ans;
}
// 3rd method ends

// 2nd method to solve the question
vi sieve(maxn,1);
void almostprime() {
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i < maxn; i++)
    {
        if(sieve[i] == 1) {
            for (int j = i*i; j < maxn; j+=i)
                sieve[j] = 0;
        }
    }
}
bool almost_prime[maxn];
int almost_prime_efficient(int n) {
    
    for (int i = 2; i <= n; i++) {
        if(sieve[i]) {
            for (int j = i; j <= n; j+=i)
            { // j = i*something, now this someting should be prime and not equal to i
                if(n%i==0) {
                    if( sieve[(n/i)]==1 && i!=(n/i) )
                        almost_prime[j] = true;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if(almost_prime[i]){
            ans++;
        }
    }
    return ans;
}
// 2nd method ends



// Solution for if N<=3000. 1st method
bool isprime(int n){
    if(n==1) return false;
    int lim = sqrt(n);
    for (int i = 2; i <= lim; i++){
        if(n%i==0)
            return false;
    }
    return true;
}
// complexity here is intereseting to analyse too. here tc is just O(sqrt(n)+sqrt(n)) ~ O(sqrt(n))
// complexity is NOT O(sqrt(n)*sqrt(n))
// this is because outer loop can run upto O(sqrt(n)) true but once we get to inner loop we will run 
// it once and we will return inside that loop so it's tc is also O(sqrt(n))
bool is_almost_prime(int n) {
    int lim = sqrt(n);
    for (int i = 2; i <= lim; i++) {
        if(n%i==0) {
            // i is prime, n/i is prime and i!=(n/i)
            if( isprime(i) && isprime(n/i) && i!=(n/i) ) {
                return true;
            }
            else return false;
        }
    }
    return false;
}








// end of problem 1


int main()
{
    //int n; cin>>n;
    int n=100, ans=0;
    for (int i = 1; i <= n; i++)
    {
        if(is_almost_prime(i)){
            // cout<<i<<" ";
            ans+=1;
        }
    }
    cout<<endl<<ans<<endl;
    
    
    
    return 0;
}



