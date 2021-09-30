


#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

// efficient way to find phi(n) from 1 to n, where n <= 10^6
// modify the sieve algo to calculate etf(n).

// so the formula for etf(n) = n * ((p1-1)/p1) * ((p2-1)/p2) * ..... * ((pk-1)/pk)
// where p1, p2,..., pk are the different prime factors of n

// In fact we precalculate the value of etf(n) for all n upto 10^6
// first we initialise phi array of each element with that element itself 
// because we need to multiply the element itself in the final answer.
// Now, for every prime that we encounter we go to each multiple of that prime
// and then do this : (phi[i] * (prime-1) / prime) 

int n = 1e6+1;
vi phi(n,0);

void sievealgo() {
    for (int i = 1; i < n; i++)
        phi[i] = i;
    phi[0] = phi[1] = 0;

    for (int i = 2; i < n; i++)
    {
        if(phi[i] == i) {
            for (int j = i; j < n; j+=i)
            {
                phi[j] = (phi[j] * (i-1)) / i;
            }
        }
    }
}

int main()
{
    sievealgo();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<phi[n]<<endl;
    }
    
    
    return 0;
}


