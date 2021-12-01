


#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;


void insert_at_the_bottom(int x, stack<int>&s) {
    if(s.size()==0)
        s.push(x);
    int a = s.top();
    s.pop();
    insert_at_the_bottom(x,s);
}
void reverse( stack<int>&s ) {
    if(s.size()==1) 
        return;
    int a = s.top();
    s.pop();
    reverse(s);
    insert_at_the_bottom(a, s);
}

int main()
{
    //int n; cin>>n;
    
    
    return 0;
}



