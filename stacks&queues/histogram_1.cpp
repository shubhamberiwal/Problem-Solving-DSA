
#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

vi nextlowerright(vi&arr) {
    int n = arr.size();
    stack<pair<int,int>> s;
    vi ans;
    for(int i=n-1; i>=0; i--) {
        if(s.size()==0)
            ans.pb(n);
        else if(s.size()>0 && s.top().first<arr[i])
            ans.pb(s.top().second);
        else {
            while(s.size()>0 && s.top().first>arr[i] )
                s.pop();
            if(s.size()==0)
                ans.pb(n);
            else ans.pb(s.top().second);
        }
        s.push({arr[i],i});
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
vi nextlowerleft(vi&arr) {
    int n = arr.size();
    stack<pair<int,int>> s;
    vi ans;
    for(int i=0; i<n; i++) {
        if(s.size()==0) 
            ans.pb(-1);
        else if(s.size()>0 && s.top().first<arr[i]) 
            ans.pb(s.top().second);
        else {
            while(s.size()>0 && s.top().first>arr[i]) 
                s.pop();
            if(s.size()==0) ans.pb(-1);
            else ans.pb(s.top().second);
        }
        s.push({arr[i],i});
    }
    return ans;
}
// maximum area histogram
int histogram(vi&arr) 
{
    vi nll = nextlowerleft(arr);
    vi nlr = nextlowerright(arr);
    vi width;
    int n = arr.size();
    int area = INT_MIN;
    for(int i=0; i<n; i++) {
        width.pb(nlr[i]-nll[i]-1);
        int temp = width[i] * arr[i];
        area = max(area,temp);
    }
    return area;
}
int main()
{
    //int n; cin>>n;
    vi arr = {6,2,5,4,5,1,6};
    cout<<histogram(arr)<<endl;
    return 0;
}




