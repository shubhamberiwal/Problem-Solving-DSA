

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

// this program is to calculate binomial coefficient, i.e, 
// C(n,k) in a efficient method


int P = 1e9+7;
// mod should be greater than n and should be prime 
// so for example we can take mod as 1e9+7
const int m = 1e6+1;
vi f(m);

int power(int a, int n) {
    int res = 1;
    while(n) {
        if(n&1) res = (res*1LL*a)%P;
        n=n/2;
        a = (a*1LL*a) % P;
    }
    return res;
}

int C(int n, int k) {
    
    // you cannot choose k elements from n if k>n
    if(k>n) return 0; 
    
    // res currently has (n! % p)
    int res = f[n]; 
    
    // to divide res with (k!%p) we first need to first find the 
    // modulo inverse of f[k] which is (k! % p) and then multiply with res
    res = (res * 1LL * power(f[k],P-2)) % P; 

    // again do the same thing with ((n-k)! % p)
    res = (res * 1LL * power(f[n-k], P-2)) % P;
    
    return res;
    // res /= f[k];
}

int main()
{
    //int n; cin>>n;
    f[0] = f[1] = 1;
    // precomputing factorial of each number till 1e6
    for (int i = 2; i < 1000000; i++)
        f[i] = ( f[i-1] * 1LL * i ) % P; 
    // during multiplication int capacity can overflow so temporarylily 
    // we need to multiply with 1LL (1 long long) and then when we take % p, int range is restored
    int q; cin>>q;
    while(q--){
        int n,k;
        cin>>n>>k;
        cout<<C(n,k)<<endl;
    }
    
    return 0;
}







