

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

vi leftsmall(vi&arr) {
    stack<int> s;
    int n = arr.size();
    vi l;
    for(int i=0; i<n; i++) {
        while(s.size()!=0 && arr[s.top()]>=arr[i]) {
            s.pop();
        }
        if( s.size()==0) l.pb(0);
        else l.pb(s.top()+1);
        s.push(i);
    }
    return l;
}

vi rightsmall(vi&arr) {
    stack<int> s;
    int n = arr.size();
    vi r;
    for(int i=n-1; i>=0; i--) {
        while(s.size()!=0 && arr[s.top()]>=arr[i]) 
            s.pop();
        if(s.size()==0) r.pb(n-1);
        else r.pb(s.top());
        s.push(i);
    }
    return r;
}

// independent function
int largest_rectangular_area_histogram(vi&arr) {
    int n = arr.size();
    stack<int>s;
    vi l(n),r(n);
    for(int i=0; i<n; i++) {
        while(s.size()>0 && arr[s.top()]>=arr[i]) s.pop();
        if(s.size()==0) l[i] = 0;
        else l[i] = s.top()+1;
        s.push(i);
    }
    while(s.size()!=0) s.pop();
    for(int i=n-1; i>=0; i--) {
        while(s.size()!=0 && arr[s.top()]>=arr[i])
            s.pop();
        if(s.size()==0) r[i] = n-1;
        else r[i] = s.top();
        s.push(i);
    }
    int maxarea = 0;
    for(int i=0; i<n; i++) {
        maxarea = max( maxarea, arr[i] * (r[i] - l[i] + 1));
    }
    return maxarea;
}

int main()
{
    
    return 0;
}






