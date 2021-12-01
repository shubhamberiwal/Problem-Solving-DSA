
#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

void interLeave(queue<int>&q) {

    stack<int> s;
    int n = q.size();
    for(int i=0; i<(n/2); i++) {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    for(int i=0; i<(n/2); i++) {
        q.push(q.front());
        q.pop();
    }
    while(!s.empty()) {
        q.push(s.top());
        q.push(q.front());
        s.pop();
        q.pop();
    }
}

int main()
{
    //int n; cin>>n;
    
    
    return 0;
}



