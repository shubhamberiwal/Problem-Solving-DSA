


#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

// acc. to fermats theorem [ a^(m-1) congruent 1 (mod m) ]
// or we can say that : [ a^(m-2) congruent a^-1 (mod m) ]
// so using this we will be able to calculate the modulo inverse of a number under some prime number m.

//Important: remember one thing that M must be a prime number 
// and A must be co-prime with m. only then you will get the required results
// This also indicates the fact that it modulo inverse of all numbers under another number is not possible.

// tc here is O(log m) because we need to calculate a^m-2,
// and we can do that in log m time using binary_expo ofc.


int power(int a, int n, int mod) {
    if(n==0)
        return 1;
    int ans = power(a,n/2,mod);
    if(n&1)
        return ((((ans*ans)%mod)*a)%mod);
    return ((ans*ans)%mod);
}
int power_iter(int a, int n, int mod){
    int res = 1;
    while(n){
        if(n&1){
            res = (res*a)%mod;
            n--;
        }
        else {
            a = (a * a) % mod;
            n = n>>1;
        }
    }
    return res;
}

int main()
{
    int m,a; cin>>a>>m;
    cout<< "a^-1" << power(a,m-2,m)<<endl;
    
    return 0;
}




