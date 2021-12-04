
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;




// 3.2 -
// very effective approach
// idea is to divide the array into 2 halves
// 1st half or left half is just before the single element
// and 2nd or right half starts from the single element
// in left half 1st instance is at even index and 2nd instance at odd index
// now at every step check if mid belongs to left half or not, if not then move to left
// else move towards right
// keep doing it till it breaks out of loop and at end start will be pointing to the 
// element that appears once
int binaryone( vi&nums)
{
    int start = 0, end = nums.size()-2;
    while(start<=end) {
        int mid = start+(end-start)/2;
        if( nums[mid] == nums[mid^1] )
            start = mid+1;
        else end = mid-1;
    }
    return nums[start] ;
}

// 3.1 - Find the element that appears once in a sorted array, while others appear twice
// Efficient Binary search but more code
int binaryonce( vi&nums, int start, int end) {
    if( nums[start]!=nums[start+1] )
        return nums[start];
    else if(nums[end]!=nums[end-1])
        return nums[end];
    while(start<=end) {
        int mid = start+(end-start)/2;
        if( (mid==0 || nums[mid]!=nums[mid-1]) && (mid==nums.size()-1 || nums[mid]!=nums[mid+1] ))
            return nums[mid];
        else if( mid!=0 && nums[mid]==nums[mid-1] ){
            if( (mid-start)%2!=0 )
                start = mid+1; //right half
            else end = mid-1;
        }
        else{
            if( end-mid&2!=0 )
                end= mid-1;// left half
            else start = mid+1;
        }
    }
    return 1000;
}

// 2 - Finding the median in a row wise sorted matrix
// very interesting but simple problem if you break it down
// Try find the initial search space. Then try to find the monotonic increasing function
// Now that function is { # <= i } where i is from [1 to 10^9]
int find_elements_smaller_and_equal( vector<vector<int>> &matrix, int n)
{
    int count=0;
    for( auto x: matrix){
        int start = 0;
        int end = x.size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if( x[mid]<=n ){
                start = mid+1;
            }
            else if( x[mid] > n){
                end = mid-1;
            }
        }
        count+=start;
    }
    return count;
}

int medianinmatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int total_ele = n*m;
    int start = 1, end = 1e9;

    while(start<=end) {

        int mid = start+(end-start)/2;
        int count = find_elements_smaller_and_equal(matrix, mid);
        
        if( count <= (total_ele/2) )
            start = mid+1;
        else end = mid-1;
    }
    return start;
}


// 1 - find the nth root of a m
// tc (if the search space had integers and not real numbers )
// tc: (nlog m) , as pow function or multiply function takes n time
// but this is not the actual complexity because we make use of real numbers
// therefore actual complexity is tc: O(nlog m*(precision of decimal))
// if you're looking for precision till 5 decimal places then tc : O(nlog (m*10^5))
double multiply(double m, int n) {
    double ans = 1.0;
    for(int i=1; i<=n; i++) {
        ans*=m;
    }
    return ans;
}
void nthroot(int n, int m) {
    double start = 1;
    double end = m;
    double esp = 1e-6;
    while( (end-start) > esp){
        double mid = start + (end-start)/2.0;
        if( pow(mid,n) < m )// multiply(mid, n) , pow(mid, n)
            start = mid;
        else end = mid;
    }
    cout<<end<<endl; // you can print high too
    cout<< pow(m,(double)(1.0/(double)n));
}

int main()
{
    //int n; cin>>n;
    // nthroot(3, 67);
    vi nums = {3,3,4,4,5,5,6,7,7};
    cout<<binaryonce(nums, 0, 8)<<endl;
    
    return 0;
}
