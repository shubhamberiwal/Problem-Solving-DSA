

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

// so the formula for etf(n) = n * ((p1-1)/p1) * ((p2-1)/p2) * ..... * ((pk-1)/pk)
// where p1, p2,..., pk are the different prime factors of n

int etf(int n){
    int res = n;
    for (int i = 2; i*i <= n; i++) {
        if( n%i == 0){
            while( n%i==0 ){
                n = n/i;
            }
            res = (res * (i-1)) / i ;
        }
    }
    if( n>1 ) {
        res = (res * (n-1)) / n;
    }
    return res;
}

int main()
{
    int n; cin>>n;
    cout<<"Etf("<<n<<") = "<<etf(n);
    return 0;
}




