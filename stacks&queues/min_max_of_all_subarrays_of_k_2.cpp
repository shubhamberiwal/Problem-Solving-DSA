
#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

void min_max_k( vi&arr, int k) {

    map<int,int> mpp;
    int n = arr.size();

    int l = 0;
    for( int i=0; i<n; i++) {

        l++;
        mpp[arr[i]]++;
        if( l==k ) {
            auto itmax = mpp.end();
            itmax--;
            auto itmin = mpp.begin();
            cout<<itmin->first<<" "<<itmax->first<<endl;

            mpp[arr[i-k+1]]--;
            if(mpp[arr[i-k+1]]==0) {
                mpp.erase(arr[i-k+1]);
            }
            l--;
        }
    }
}

int main()
{
    //int n; cin>>n;
    vi arr = { 5, 4, 3, 2, 1, 6,
                  3, 5, 4, 2, 1 };
    int k = 3;
    int n = arr.size();
    min_max_k(arr,k);
    return 0;
}





