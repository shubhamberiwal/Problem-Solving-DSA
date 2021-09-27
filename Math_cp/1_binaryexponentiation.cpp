
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

// Binary Exponentiation

// calculating a^b
// time complexity is the number of bits in binary representation of b (i.e) log(2)b+1
// easy way to look at this is at every step b is being halfed
// stack space or space comp. for recursion is O(log(2)b)
int power(int a, int b){
    if(b==0)
        return 1;
    int X = power(a,(b/2));
    if(b%2==0){
        return X * X;
    }
    else return X * X * a;
}

// iterative approach
// tc: O(log n) sp: O(1)
// eg: a^21 -> (a^10)^2*a -> (a^5)^2 -> (a^2)^2*a -> (a^1)^2 (this is expected)
// how workflow works: res=a, a^2, b=10; res=a, a^4, b=5; res=a^5, a=a^8, b=2; res=a^5, a=a^16, b=1; res=a^21, a=a^32, b=0; 
int power2_iterative(int a, int b) {
    int ans = 1;
    while(b>0) {
        if(b%2==1) { // or number of bits in binary rep of b that are set, that many times we update ans
            ans = ans * a;
        }
        b = b>>1; // each step b/2
        a = a*a; // double previous value of a
    }
    return ans;
}
// 2nd iterative approach
// most easy way to learn at first
int power3_iterative(int a, int b) {
    int res = 1;
    while(b) {
        if(b%2) {
            res = res*a;
            b--;
        }
        else {
            a = a*a;
            b = b/2;
        }
    }
    return res;
}
int main()
{
    //int n; cin>>n;
    
    
    return 0;
}





