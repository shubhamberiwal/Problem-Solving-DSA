
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;

// given a number 'n' and a number 'a' you have to return x.
// now x is the number that 'a' is raised to which is consisted in n!
// in other words n! has a^x * b where b is not co-prime with a or it doesn't share a prime factor with a

// this problem can also be treated as trailing zero problem 
// because if a = 5 then if you calculate x for it then it is the 
// number of consecutive zeros that n! has in the end

int power_of_p(int n, int p){
    int g = p;
    int ans = 0;
    while(g<=n){
        ans += (n/g);
        g *= p; // here 5 becomes 25 then 125 then 625
    }
    return ans;
}
// this is to find trailing zeroes in n!
// in case of n! you can only count power of 5 and tell that this is the 
// number of trailing zeroes that a number n! has. You don't need to calculate
// power of 2 because 2 will always be in surplus in n! but it's not the case for C(n,k)
int trailing_zeros(int n){
    return power_of_p(n,5);
}

// this is to find trailing zeroes in C(N,K) = (n!) / ((k!) * (n-k)!)
// here you can't just calculate the power of 5 because here denominator is involved 
// you also have to consider power of 2, now power of 2 is not surplus
// so calculate power 2 and power of 5 then return the minimum of both of those power
int trailing_zeroes(int n, int k){
    int x = power_of_p(n,2) - power_of_p(k,2) - power_of_p(n-k,2);
    int y = power_of_p(n,5) - power_of_p(k,5) - power_of_p(n-k,5);
    return min(x,y);
}


int main()
{
    
    return 0;
}

