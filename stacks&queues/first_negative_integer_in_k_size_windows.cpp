
#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

void first_negative(vector<int>&arr,int k) {

    int n = arr.size();
    deque<int> s;
    int i=0;
    for( ; i<k; i++) if(arr[i]<0) s.push_back(i);
    
    if(!s.empty()) cout<<arr[s.front()]<<" ";
    else cout<<"0 ";

    for( i=k ; i<n; i++) {
        
        while( !(s.empty()) && s.front()<=(i-k) )
            s.pop_front();
        if(arr[i]<0) 
            s.push_back(i);
        
        if(!s.empty())
            cout<<arr[s.front()];
        else cout<<"0 ";

    }

}

int main()
{
    //int n; cin>>n;
    
    
    return 0;
}



