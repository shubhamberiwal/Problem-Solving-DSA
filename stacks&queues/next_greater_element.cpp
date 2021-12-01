

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

// https://leetcode.com/problems/next-greater-element-ii/

vi nge(vi&arr) {
    int n = arr.size();
    stack<int> s;
    vi ans(n);
    for(int i=(2*n-1); i>=0; i--) {
        while( !s.empty() && s.top()<=arr[i%n] ) {
            s.pop();
        }
        if(i<n) {
            if( !s.empty() )
                ans[i] = s.top();
            else ans[i] = -1;
        }
        s.push(arr[i%n]);
    }
    return ans;
}

int main()
{
    //int n; cin>>n;
    vi arr = {4,5,2,25};
    vi ans = nge(arr);
    for(auto x: ans) {
        cout<<x<<" ";
    }
    
    return 0;
}





