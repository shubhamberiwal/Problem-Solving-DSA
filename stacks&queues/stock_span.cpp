


#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;


// on the lines of next greater to the left
vi stock_ngl(vi&arr) {
    int n = arr.size();
    stack<pair<int,int>> s;
    vi ans ;
    for(int i=0; i<n; i++) {
        if(s.size()==0 )
            ans.pb(-1);
        else if( s.size()>0 && s.top().first>arr[i])
            ans.pb(s.top().second);
        else {
            while(s.size()>0 && s.top().first<arr[i])
                s.pop();
            if(s.size()==0)
                ans.pb(-1);
            else
                ans.pb(s.top().second);
        }
        s.push( {arr[i],i} );
    }
    for(int i=0; i<n; i++) {
        ans[i] = i - ans[i];
    }
    return ans;
}

// general using stack wala intuition se
vi stock_span(vi&arr)
{
    int n = arr.size();
    stack<pair<int,int>> s;
    vi ans;
    for (int i = 0; i < n; i++)
    {
        int point = 1;
        if(s.size()==0 ) {
            ans.pb(1);
        }
        else if( s.top().first > arr[i]) {
            ans.pb(1);
        }
        else {
            //s.top().first < arr[i]
            // point = s.top().second;
            // s.pop();
            while(s.size()>0 && s.top().first<arr[i] ) {
                point += s.top().second;
                s.pop();
            }
            ans.pb(point);
        }
        s.push({arr[i],point});
    }
    return ans;
}

int main()
{
    //int n; cin>>n;
    vi arr = {100,80,60,70,60,75,85};
    vi ans = stock_span(arr);
    for(auto x: ans) {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}




