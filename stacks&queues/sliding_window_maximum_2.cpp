


#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

vector<int> maxSlidingWindow(vector<int>&nums, int k) {
    deque<int> q;
    vector<int> ans;
    int n = nums.size();
    for( int i=0; i<n; i++ )
    {
        if( !q.empty() && q.front()==(i-k) )
            q.pop_front();
// [1,3,1,2,0,5]
// 3
        while( !q.empty() && nums[i]>=nums[q.back()] )
            q.pop_back();
        
        q.push_back(i);
        if( i>=k-1)
            ans.push_back(nums[q.front()]);
    }
    return ans;
}

int main()
{
    //int n; cin>>n;
    
    
    return 0;
}



