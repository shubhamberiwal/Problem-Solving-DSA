

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;


vi nextlowerleft(vi&arr) {
    int n = arr.size();
    stack<int> s;
    vi ans;
    for(int i=0; i<n; i++) {
        if( s.size()==0  ) {
            ans.pb(-1);
        }
        else if( s.size()>0 && s.top()<arr[i] ) {
            ans.pb(s.top());
        }
        else {
            while( s.size()>0 && s.top()>arr[i]) {
                s.pop();
            }
            if(s.size()==0) ans.pb(-1);
            else ans.pb(s.top());
        }
        s.push(arr[i]);
    }
}

vi nextgreaterleft(vi&arr) {
    int n = arr.size();
    stack<int> s;
    vi ans;
    for(int i=0; i<n; i++) {
        if( s.size()==0  ) {
            ans.pb(-1);
        }
        else if( s.size()>0 && s.top()>arr[i] ) {
            ans.pb(s.top());
        }
        else {
            while( s.size()>0 && s.top()<arr[i]) {
                s.pop();
            }
            if(s.size()==0) ans.pb(-1);
            else ans.pb(s.top());
        }
        s.push(arr[i]);
    }
}
vi nextgreaterright(vi&arr) {
    int n = arr.size();
    stack<int> s;
    vi ans;
    for(int i=n-1; i>=0; i--) {
        if( s.size()==0  ) {
            ans.pb(-1);
        }
        else if( s.size()>0 && s.top()>arr[i] ) {
            ans.pb(s.top());
        }
        else {
            while( s.size()>0 && s.top()<arr[i])
                s.pop();
            if(s.size()==0) ans.pb(-1);
            else ans.pb(s.top());
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
}
vi nextlowerright(vi&arr) {
    int n = arr.size();
    stack<int> s;
    vi ans;
    for(int i=n-1; i>0; i++) {
        if( s.size()==0  ) {
            ans.pb(-1);
        }
        else if( s.size()>0 && s.top()<arr[i] ) {
            ans.pb(s.top());
        }
        else {
            while( s.size()>0 && s.top()>arr[i]) {
                s.pop();
            }
            if(s.size()==0) ans.pb(-1);
            else ans.pb(s.top());
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
}


int main()
{
    //int n; cin>>n;
    
    
    return 0;
}



