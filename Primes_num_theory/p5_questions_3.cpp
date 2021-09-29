
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;

// 2 - given N <= 10^12. Tell if it exactly has 3 positive divisors
// there are T(<=10^5) test cases

// for a number to have exactly 3 divisors it has to be a 
// perfect square and that perfect square should also be prime
// eg: 25: 1,5,25 now 36 is not and example because: 6 has more factors so 36 has more than 3 +ve divisors

// 1st method to solve
// tc for just 1 number: O( sqrt(n) + sqrt(sqrt(n)) ) ~ O(sqrt(n))
// total tc is O(n*sqrt(n)) not optimal will give tle
bool isprime(int n){
    if(n==1) 
        return false;
    for (int i = 2; i*i <= n; i++){
        if(n%i==0)
            return false;
    }
    return true;
}
bool check_3_divisors_1(ll n) {
    int A = sqrt(n);
    if(A==-1){
        return false;
    }
    if(isprime(A))
        return true;
    else return false;
}
// end of 1st method

// 2nd method - optimal for T<=10^5 test cases and N<=10^12
// here we calculate all prime number till 10^6 and then create a set 
// and store the sqaures of all the primes that are in the range of 10^6
// this will give us number till 10^12. and now we can easily check if a number n
// is present in the set or not and return. Because the set only contains number
// that have exactly 3 divisors.
const int maxn = 1e6+5;
set<ll> my_bucket;
vector<bool> is_prime(maxn,true);
void prime_sieve(){
    is_prime[0]=is_prime[1] = false;
    for (int i = 2; i*i < maxn; i++) {
        if(is_prime[i]) {
            for (int j = i*i; j < maxn; j+=i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < maxn; i++) {
        if(is_prime[i]) {
            my_bucket.insert(i*i);
        }
    }
}
bool check_3_divisors_2(ll n) {
    if(my_bucket.find(n)!=my_bucket.end()) {
        return true;
    }
    return false;
}
// end of 2nd method


// follow up question 
// 3 - given N <= 10^12. Tell if it exactly has 5 positive divisors
// there are T(<=10^5) test cases
// This is a tricky question just playing with your mind
// the answer is very simple and same to above just take and example and analyse
// factor of any number is: if it's prime factorization is : 2^a1 X 3^a2 X 5^a3 and so on
// the number of factors are: (1+a1)(1+a2)(1+a3)and so on.
// but we have to find numbers with exactly 5 divisors and 5 cannot be represented in the form of (x*y)
// so, it can only be possible if a number is made up of a prime number to the power 4 or 
// N should be for form = p^4 [where p is a prime number]
// example is 16: 2*2*2*2 here total divisors are exactly 5: 1,2,4,8,16
// THEREFORE, in the above solution just replace the line 
// "my_bucket.insert(i*i)" with "my_bucket.insert(i*i*i*i)"

int main() {
    int t; cin>>t;
    prime_sieve();
    while(t--) {
        ll N; cin>>N;
        if(check_3_divisors_2(N))
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

