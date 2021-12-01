

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;


vi maxsubarray( vi&arr, int k ) {
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

    for(int i=k; i<n; i++) {

        // front will always give you the max ele in the current window
        cout<<(arr[q.front()])<<" ";

        // removing elements that are not a part of current window
        while( !q.empty() && q.front()<=(i-k) )
            q.pop_front();
        // removing that are smaller than the element in the current window
        while( !q.empty() && arr[i]>=arr[q.back()] )
            q.pop_back();
        
        q.push_back(i);
    }
    cout<<(arr[q.front()])<<" ";
}

int main()
{
    //int n; cin>>n;
    
    
    return 0;
}





