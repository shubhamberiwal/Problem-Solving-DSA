
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;


// gcd(a,b) = gcd(b,a%b) = gcd(a%b, b%(a%b)) = ... and so on

// complexity is: O(log b)
// after 2 steps b becomes b%(a%b) as shown above,
// which is < b/2. So tc can be approximated to O(log b) and O(log a)
// as b is smaller than a and will reach 0 first

int gcd(int a, int b){
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

int main()
{
    int n,m;
    // cin>>n>>m;
    cout<<gcd(102,249);
    return 0;
}


