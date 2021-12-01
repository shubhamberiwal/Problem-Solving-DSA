

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;


// https://leetcode.com/problems/sum-of-square-numbers/
// Given a non-negative integer c, decide whether there're two integers a and b such that a^2 + b^2 = c.
bool judgeSquareSum(int c) {
    long long l = 0, r = sqrt(c);
    while(l<=r) {
        long long x = l*l + r*r;
        if( x == c ) 
            return true;
        else if(x<c) {
            l++;
        }
        else r--;
    }
    return false;
}

int main()
{
    //int n; cin>>n;
    
    
    return 0;
}










