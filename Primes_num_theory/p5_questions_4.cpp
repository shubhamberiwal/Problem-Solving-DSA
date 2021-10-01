

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

// 1 - given A, count the number of right angled triangles with integer lengths in which 
// the length of a non hypotenuse edge is A. Also 1<=A<=1e5
// to reframe question: count pair of (B,C) where A^2 + B^2 = C^2 and A,B,C are integers

// we know A^2 + B^2 = C^2 given A so we can write A^2 = C^2 - B^2
// A^2 = (C-B)(C+B) which means a^2 has 2 factors in (c-b) and (c+b)
// lets say 2 factors are x and y now conditions are:
// FIRST, x!=y because that means b is 0 and then a2 = c2, which is wrong
// SECOND, if say factors are either one even and one odd then we won't get integer answers
// and why is that because then 2*C = (even + odd) which is equal to odd and hence c is not integer and so is b
// that is why both the factors have to be EITHER BOTH EVEN OR BOTH ODD

// tc: O(n) for 1 test case
int count(int N){
    int ans = 0;
    ll lim = (ll) N*N; // because we are factorising n^2 and not n
    for (int x = 1; x*x <= lim; x++)
    {
        if(N%x==0){
            // x*y = N
            ll y = lim/x;
            if(x<y && (x%2==y%2)) { // CHECKING BOTH FIRST AND SECOND CONDITION
                ans++;
            }
        }
    }
}


int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<count(n)<<endl;
    }
    return 0;
}



// 2nd question
// https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/micro-and-prime-prime-1/
// Micro just learned about prime numbers. But he quickly got bored of them, 
// so he defined a new kind of numbers and called them Prime Prime Numbers. 
// A number X is Prime Prime if number of prime numbers from 1 to X (inclusive) are prime.
// Now he wants to find out the number of Prime Prime numbers from L to R (inclusive). 
// Help Micro with it.
// sample i/o
// 2
// 3 10 - 4
// 4 12 - 5

const int maxn = 1e6+1;
int sieve[maxn];
int primecount[maxn];
void sievealgo() {
    for (int i = 1; i < maxn; i++)
        sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i*i < maxn; i++)
    {
        if(sieve[i]) {
            for (int j = i*i; j < maxn; j+=i) {
                sieve[j] = 0;
            }
        }
    }
    int count = 0;
    for (int i = 1; i < maxn; i++)
    {
        if(sieve[i])
            count++;
        // if ith number is prime prime then in primecount that number will be stored as a 1
        // now further we can store the cumulative sum
        if(sieve[count])
            primecount[i] = 1;
        else primecount[i] = 0;
        // primecount[i] = count;
    }
    // calculate cumulative primecount
    for (int i = 2; i < maxn; i++)
        primecount[i] += primecount[i-1];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    cin.tie(NULL);
    sievealgo();
    int t; cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        int count = 0;
        // for (int i = l; i <= r; i++)
        // {
        //     count += primecount[i];
        // }
        count = primecount[r] - primecount[l-1];
        cout<<count<<endl;        
    }
    return 0;
}