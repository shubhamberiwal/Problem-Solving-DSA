#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;


// given 2 sorted arrays arr1 and arr2 of size m and n resp. and an element k. Task is to find
// the element that would be at the kth position of the final sorted array
int fine(vi&nums1, vi&nums2, int k) {
    
    if(nums1.size() > nums2.size()) return fine(nums2,nums1,k);
    int n1 = nums1.size(), n2 = nums2.size();
    
    int low = max(0,k-n2), high = min(n1,k);

    while(low<=high) {
        int cut1 = (low+high)>>1;
        int cut2 = k - cut1;
        if(cut2<0){

        }
        int left1 = cut1==0? INT_MIN: nums1[cut1-1];
        int left2 = cut2==0? INT_MIN: nums2[cut2-1];
    
        int right1 = cut1==n1? INT_MAX: nums1[cut1];
        int right2 = cut2==n2? INT_MAX: nums2[cut2];

        if( left1 <= right2 && left2 <= right1 )
            return max(left1,left2);
        else if ( left1 > right2 )
            high = cut1 - 1;
        else 
            low = cut1+1;
    }
    return 1;
}



// find the median of 2 sorted arrays
double findmediansortedarrays(vi&nums1,vi&nums2) {
    if(nums1.size()>nums2.size()) return findmediansortedarrays(nums2,nums1);
    int n1 = nums1.size(), n2 = nums2.size();
    int low = 0, high = n1;
    
    while(low<=high) {
        int cut1 = low + (high-low)/2;
        int one_side = (n1+n2+1)/2;
        int cut2 = one_side-cut1;

        int left1 = cut1==0? INT_MIN: nums1[cut1-1];
        int left2 = cut2==0? INT_MIN: nums2[cut2-1];
    
        int right1 = cut1==n1? INT_MAX: nums1[cut1];
        int right2 = cut2==n2? INT_MAX: nums2[cut2];
    
        if( left1 <= right2 && left2 <= right1 ) {
            if( ( n1 + n2 ) % 2 == 0 )
            {
                int ans = max(left1,left2) + min(right1,right2);
                return (ans/2.0);
            }
            else return max(left1,left2);
        }
        else if(left1 > right2)
            high = cut1-1;
        else // right1 < left2
            low = cut1+1;
    }
    return 0.0;
}

int main()
{
    //int n; cin>>n;
    
    
    return 0;
}



