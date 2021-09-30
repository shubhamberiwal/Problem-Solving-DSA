

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

// given p1,p2,r1,r2, you have to find x.
// now x is some integer such that x%p1 = r1
// and x%p2 = r2

// 
// const ll mod = 1e9+7;

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
    int p1,p2,r1,r2; cin>>p1>>p2>>r1>>r2;
    

    // 3rd method - 
    // answer is X : (r1 + k * P1) and K = (r2-r2) (P1^-1) (mod P2)
    // find k using fermats theorem
    ll k = ((r2-r1) * inverse(p1, p2)) % p2;
    // now k can be negative if r1>r2 so to prevent it from being negative
    // we can do k+=p2. Why because we are taking mod p2 and if we add P2 to that number
    // the remainder won't change of (k+p2) % p2
    if( k < p2) k+=p2;
    cout<< r1 + k*p1 <<endl;

    // 2nd method - O(min(p1,p2))
    // now we know that number given remainder r1 with % p1 so 
    // number 'x' can be written in the form ( r1 + x*p1 ). With this we will always
    // get r1 as remainder with mod P. Now we have to find x
    // such that (r1 + x*p1) % p2 = r2.
    // the upper bound for x in loop will be at max it can be 
    // (r1 + x*p1) such that it is still < p1*p2. Why because we figured that 
    // x has to lie between 0 < x < p1*p2
    // naive way here would be run loop from 0 to p2
    // so now the time complexity is reduced to O(p2)
    
    for (int x = 0; r1 + x*p1 < p1*p2; x++)
    {
        if( (r1 + (x*p1))%p2 == r2 ){
            cout<< r1+(x*p1) <<endl;
        }
    }
    
    
    
    
    
    // O(p1*p2) - 1 - Naive way 
    // lets say x is the solution to problem then (x+p1*p2) is also a solution
    // this won't change the remainder with r1 or r2 because (p1*p2) is a multiple of both p1 and p2
    // and taking mod with this number, the remainder still depends on x
    // so if we add or subtract p1*p2 it doesn't change the answer at all. So if we keep subtracting
    // p1*p2 from x such that x lies between 0<x<p1*p2. Now x is the lowest value for the possible answer.
    // So we can conclude that x lies between (0 to p1*p2). So run a loop and till that and find the answer.

    // for (int i = 0; i < p1*p2; i++)
    // {
    //     if(i%p1==r1 && i%p2==r2)
    //         cout<<i<<endl;
    // }
    return 0;
}


