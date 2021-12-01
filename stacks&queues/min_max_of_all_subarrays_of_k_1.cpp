

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;


vi max_of_subarrays( vi&arr, int k ) {
    deque<int> q;
    int n = arr.size();

    // calculating for the first k elements
    // push all elements and while at a particular ele
    // delete all elements that are currently in the dque that are 
    // smaller than the current elements
    for(int i=0; i<k; i++) {
        while( !q.empty() && arr[i]>=arr[q.back()] )
            q.pop_back();
        q.push_back(i);
    }

    vi ans;
    for(int i=k; i<n; i++) {

        // front will always give you the max ele in the current window
        ans.pb(arr[q.front()]);

        // removing elements that are not a part of current window
        while( !q.empty() && q.front()<=(i-k) )
            q.pop_front();
        // removing that are smaller than the element in the current window
        while( !q.empty() && arr[i]>=arr[q.back()] )
            q.pop_back();
        
        q.push_back(i);
    }
    ans.pb(arr[q.front()]);
    return ans;
}

vi min_of_subarrays( vi&arr, int k) {
    deque<int> q;
    int n = arr.size();

    for(int i=0; i<k; i++) {
        while( !q.empty() && arr[i]<=arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    vi ans;
    for(int i=k; i<n; i++) {

        ans.pb(arr[q.front()]);
        // delete ele not in current window
        while( !q.empty() && q.front()<=(i-k) )
            q.pop_front();
        while( !q.empty() && arr[i]<=arr[q.back()] )
            q.pop_back();
        q.push_back(i);
    }
    ans.pb(arr[q.front()]);
    return ans;
}


int main()
{
    //int n; cin>>n;
    // vi arr = { 5, 4, 3, 2, 1, 6, 3, 5, 4, 2, 1 };
    vi arr =  {2, -2, 3, -9, -5, -8};
    int k = 4;
    vi one = max_of_subarrays(arr,k);
    // vi one = max_of_subarrays(arr,k);
    vi two = min_of_subarrays(arr,k);
    int n = one.size();
    for(int i=0; i<n; i++) {
        cout<<two[i]<<" "<<one[i]<<endl;
    }
    
    return 0;
}





