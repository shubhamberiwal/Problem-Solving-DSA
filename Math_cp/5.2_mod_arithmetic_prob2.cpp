

// https://www.codechef.com/problems/GCDMOD
// problem to get your concepts clear on modular arithmetic, binary expo and gcd

#include<bits/stdc++.h>
#define fer(i,a,b) for(re i = a; i<b; ++i)
#define re register int
#define sf(x) scanf("%d", &x)
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;
// typedef long long int lli;

int mod = 1e9+7;

ll power(ll a, ll n, ll mymod){
    ll res = 1;
    while(n){
        if(n&1){
            res = ( res * (a % mymod)) % mymod;
            n--;
        }
        else {
            a = ((a % mymod)*(a % mymod)) % mymod;
            n=n>>1;
        }
    }
    return res;
}

ll gcd(ll a, ll b, ll n){
    if(a==b) {
        return (power(a,n,mod) + power(b,n,mod))%mod; 
    }
    ll candidate = 1;
    ll num = a-b;
    for (ll i = 1; i*i <= num ; i++)
    {
        if(num%i==0) {
            ll temp = (power(a,n,i) + power(b,n,i)) % i;
            if(temp==0) candidate = max(candidate,i);
            if( (num/i)!=i) {
                temp = (power(a,n,num/i) + power(b,n,num/i)) % (num/i);
                if(temp == 0) candidate = max(candidate, (num/i));
            }
        }
    }
    return candidate%mod;
}

// Explanation: as a-b will be the smaller number in comparison to a^n + b^n
// hence we need to find the gcd then gcd cannot exceed the smaller number in this case it's (a-b)
// now we can use the method that takes O(sqrt(a-b)) to calculate  all divisors of (a-b)
// each divisor will be a candidate for the gcd of both the numbers
// how if(a==b) then just return gcd of(a^n+b^n)(%mod) but if not then calculate
// all the divisors of (a-b) and do ((a^n % divisor) + (b^n % divisor) % divisor) if this return 0
// then it means divisor is a divisor of both the required numbers and then select maximum of 
// previous candidate and this divisor. Also for each divisor there is another divisor in (a-b)/divisor.

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    cin.tie(NULL);
    int t; cin>>t;
    while(t--)
    {
        ll a,b,n; cin>>a>>b>>n;
        // // a^n + b^n
        // ll result1 = (power(a,n)+power(b,n))%mod;
        // ll result2 = (a-b)%mod;
        // for (int i = 2; i*i <= result2; i++)
        // {
        //     if(result2%i==0){
                
        //     }
        // }
        
        // int result = gcd(result1, result2);
        // cout<<result<<endl;
        cout<<gcd(a,b,n)<<endl;

    }
    return 0;
}





