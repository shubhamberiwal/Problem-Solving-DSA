


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
            while(s.size()>0 && s.top().first>=arr[i] )
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
        if(s.size()==0) {
            ans.pb(-1);
        }
        else if(s.size()>0 && s.top().first<arr[i])
            ans.pb(s.top().second);
        else {
            while(s.size()>0 && s.top().first>=arr[i])
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
    // for(auto x: width) {
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return area;
    // return 0;
}

int max_area_binary_matrix(vector<vi>&matrix) {
    int ans = histogram(matrix[0]);
    for(int i=1; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++) {
            if( matrix[i][j]==0 || matrix[i-1][j]==0) {
                continue;
            }
            matrix[i][j] = matrix[i-1][j] + 1;
        }
        int temp = histogram(matrix[i]);
        ans = max(ans,temp);
    }
    return ans;
}

int main()
{
    //int n; cin>>n;
    // vi arr = {6,2,5,4,5,1,6};
    // cout<<histogram(arr)<<endl;
    vector<vi> matrix = {
            { 0, 1, 1, 0 },
            { 1, 1, 1, 1 },
            { 1, 1, 1, 1 },
            { 1, 1, 0, 0 },
        };
    cout<<"Area of maximum rectangle: "<<max_area_binary_matrix(matrix);
    return 0;
}




