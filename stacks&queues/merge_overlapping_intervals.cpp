


#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

struct interval {
    int s,e;
};
bool cmp(interval&a,interval&b) {
    return a.s<b.s;
}

// most efficient way to merge overlapping intervals
// tc: O(nlog(n)), sc: O(1) because in this method we are doing
// the merging in place.
void mergeIntervals(interval arr[], int n) {
    sort( arr, arr+n, cmp) ;
    int index = 0;

    for(int i=1; i<n; i++) {
        if(arr[index].e >= arr[i].s) {
            arr[index].e = max(arr[index].e, arr[i].e);
            arr[index].s = min(arr[index].s, arr[i].s);
        }
        else {
            index++;
            arr[index] = arr[i];
        }
    }
    // now here [0...index-1] stores the merged intervals
    for(int i=0; i<=index; i++) {
        cout<<"["<<arr[i].s<<","<<arr[i].e<<"]";
    }
}

int main()
{
    //int n; cin>>n;
    interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}




