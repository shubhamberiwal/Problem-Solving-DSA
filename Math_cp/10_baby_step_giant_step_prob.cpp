

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

// giant step baby step problem

// given a, b, p find an x where [ a^x = b % p ]
// p is a prime number, 1 <= a < p, 1 <= b < p

// if we only had a^x = b then x = log b(base a)


// see the theory for this online or in notes
// O(sqrt(p)*log p)
int main() {
    int a,b,p; cin>>a>>b>>p;
    b = b%p;

    unordered_map<ll,ll> q_value;
    ll m = floor(sqrt(p-1));
    int X=-1;

    ll D = power(a,m,p);
    ll current = D;
    for (int q = 0; q <= p/m; q++) {
        q_value[current] = q;
        current = (current*D);
    }

    ll F = inverse(a,p);
    current = 1;
    for (int r = 0; r < m; r++)
    {
        ll e = current;
        ll rhs = (b * e) % p;
        if( q_value.find(rhs) != q_value.end() ) {
            X = q_value[rhs] * m + r;
            break;
        }
        current = current * F;
    }
    if(X==-1){
        cout<<"Not Found";
    }
    else cout<<X<<endl;

    return 0;
}


// O(P) time 
// we know that a^0 , a^1, a^2, ...., a^p-2 will produce original powers, after that
// (a^x % p) will produce a duplicate value only. So we need not check for x beyond p-2
// if an answer exists it will be between 0 to p-2. 
// Now a^0, a^1, a^2 ,...., a^p-2 (mod p) will produce answers so we can 
// have a variable current initially as 1 then at each iteration of x multiply it with a
// thus we will get a^0, a^1, a^2,... , a^p-2 in constant time.
// instead of calculating power(a,x,p) in O(log p) time we did it in O(1) time
int main()
{
    int a,b,p; cin>>a>>b>>p;
    b = b%p;
    int current = 1;
    int flag = 0;
    for (int x = 0; x <= p-2; x++)
    {
        if(current==b) {
            cout<<x<<endl;
            flag = 1;
            break;
        }
        current = (current * a)%p;
    }
    if(flag) cout<<"Not Possible"<<endl;
    return 0;
}


// O(P * log p) - naive way
ll power( ll a, ll b, ll prime){
    int res = 1;
    while(b){
        if(a&1){
            res = (a*res) % prime;
            b--;
        }
        a = (a*a) % prime;
        b >>=1;
    }
}
ll inverse(ll a, ll prime){
    return power(a, prime-2, prime);
}

int main()
{
    int a,b,p; cin>>a>>b>>p;
    int flag = 0;
    for (int x = 0; x <= p-2; x++)
    {
        if(power(a,x,p)==b) {
            cout<<x<<endl;
            flag = 1;
            break;
        }
    }
    if(flag) cout<<"Not Possible"<<endl;
    return 0;
}




