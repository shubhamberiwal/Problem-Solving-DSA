

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;

class BS{

    int binarysearch(int start, int end, vi &nums, int target) {
        
        if(start>end)
            return -1;
        
        int mid = start + (end-start)/2;
        if(target==nums[mid])
            return mid;
        else if(target<nums[mid])
            return binarysearch(start, mid-1, nums, target);
        else
            return binarysearch(mid+1, end, nums, target);
    }
    
    public:
    // 9.2 -
    // recursive approach
    int ceilele( vi&nums, int start, int end, int target ){
        if(start>end)
            return -1;
        if( target < nums[start] ){
                return start;
        }
        int mid = start + (end - start)/2;
        if( target == nums[mid] )
            return mid;
        if( mid < nums.size()-1 && target>nums[mid] && target<=nums[mid+1] )
            return mid+1;
        
        if( target < nums[mid] )
            return ceilele( nums, start, mid-1, target );
        return ceilele( nums, mid+1, end, target );
    }

    // 9.1 - Ceil of an element in a sorted array
    // similar to floor of an element
    // ceil is the smallest element that is greater than target element
    int ceilofele( vi&nums, int target){
        int start = 0;
        int end = nums.size()-1;
        int ceil = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if( nums[mid] == target )
                return mid;
            else if ( target<nums[mid] ){
                ceil = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return ceil;
    }

    // 8.3 -
    // different recursive way for better understanding
    int floorofanelement( vi &nums, int start, int end, int target)
    {
        if(start>end)
            return -1;
        if(target>=nums[end])
            return end;
        int mid = start + (end-start)/2;
        if( target == nums[mid] )
            return mid;
        if( target < nums[mid] ){
            if( mid>0 && target>nums[mid-1] )
                return mid-1;
            return floorofanelement( nums, start, mid-1, target);
        }
        else{
            if( mid+1<nums.size() && target<nums[mid-1] )
                return mid;
            return floorofanelement( nums, mid+1, end, target);
        }
    }

    // 8.2 - 
    // recursive approach
    int floorofelerecur( vi&nums, int start, int end, int target ){
        
        if(start>end)
            return -1;
        if(target>=nums[end])
            return end;
        int mid = start + (end - start)/2;
        if( target == nums[mid] )
            return mid;
        // if you want recursion approach then you have to check for ele between 
        // mid-1 and mid, if yes then return mid-1 as index
        // analyse and compare with iterative approach
        if( mid>0 && target>nums[mid-1] && target<nums[mid])
            return mid-1;
        // on further analysing, you can replace the above if condition with this one.
        // the reason this works is because it doesn't matter if you check left or right of mid but
        // it matters that you're checking if the number is not present in array, then you have to 
        // look for the largest no. smaller than target
        // if( mid<nums.size()-1 && target<nums[mid+1] && target>nums[mid] )
        //     return mid;
        if( target< nums[mid])
            binarysearch( start, mid-1, nums, target );
        if( target> nums[mid])
            binarysearch( mid+1, end, nums, target );

    }

    // 8.1 - Floor of an element in a sorted array
    // if target ele. is present in array then return it's position
    // if not present then return the greatest element that is less than
    // the target element
    int floorofele( vi&nums, int target){
        int start = 0;
        int end = nums.size()-1;
        int floor = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if( nums[mid] == target )
                return mid;
            else if ( target<nums[mid] )
                end = mid-1;
            else if ( target>nums[mid] ){
                floor = mid;
                start = mid+1;
            }
        }
        return floor;
    }

    // 7 - search in a nearly sorted array
    // by nearly sorted: some elements that are supposed to be at ith 
    // position can be at [i+1] or at [i-1]
    int nearlysorted( vi&nums, int start, int end, int target ){
        
        if(start>end)
            return -1;

        int mid = start + (end-start)/2;
        if( target == nums[mid] )
            return mid;
        else if( mid > start && target==nums[mid-1] )
            return mid-1;
        else if( mid < end && target==nums[mid+1] )
            return mid+1;

        if( target < nums[mid] )
            return nearlysorted( nums, start, mid-2, target );
        else
            return nearlysorted( nums, mid+2, end, target );
    }

    // 6.2 -
    // improved approach for the same question
    // analyse and keep solving, the answer will come on it's own, just think a little
    int findelerotated( vi&nums, int target, int start, int end ){

        if(start>end)
            return -1;

        int mid = start + (end-start)/2;
        if( nums[mid] == target )
            return mid;

        if(nums[start]<nums[mid]){
            if( target>=nums[start] && target <= nums[mid])
                return binarysearch(start, mid-1, nums, target);// instead of calling binarysearch you can call the same function also
                // but to provide more clarity on what is going on binarysearch is chosen here, because array is sorted in this range.
            return findelerotated(nums, target, mid+1, end);
        }
        else{
            if( target>=nums[mid] && target<=nums[end])
                return binarysearch(mid+1, end, nums, target);// same logic here as above
            return findelerotated(nums, target, start, mid-1);
        }
    }


    // 6.1 - find an element in the rotated array
    // first find the times the array is rotated or the index of the 
    // smallest element if rotated clockwise. Then we can divide the
    // array into 2 sorted arrays, one before the smalles ele and one
    // after. Now do binary search on either array and find the answer
    int findeleinrotated( vi &nums, int target ){
        int lowindex = numberofrotations(nums);
        if(lowindex==0){
            return binarysearch(0,nums.size()-1, nums, target);
        }
        else{
            int start1 = 0;
            int end1 = lowindex-1;
            int start2 = lowindex;
            int end2 = nums.size()-1;
            int find1 = binarysearch(start1, end1, nums, target);
            int find2 = binarysearch(start2, end2, nums, target);
            return max(find1, find2);
        }
    }


    // 5.2 -
    // recursive approach
    int noofrotations( vi&nums, int start, int end){
        // this condition will come into place when the array is not 
        // rotated then the lowest number will be at 0th index
        // try with : 5,6,7,8,1,2,3,4, you will understand everything
        if( start>end )
            return 0;
        int mid = start + (end-start)/2;
        // Checking if element (mid+1) is minimum element.
        // Consider the cases like {3, 4, 5, 1, 2}
        if( mid<end && nums[mid+1]<nums[mid])
            return (mid+1);
        // mid can itself be lowest element
        if( mid>start && nums[mid]<nums[mid-1] )
            return mid;
        if( nums[mid]>nums[start] )
            return noofrotations( nums, mid+1, end);
        return noofrotations( nums, start, mid-1);
        }

    // 5 - How many times is a sorted array rotated
    // you will be given a sorted array which will be rotated by say x
    // eg: given 11, 12, 15, 18, 2, 5, 6, 8. This is rotated 4 times
    // because then sorted array will be: 2, 5, 6, 8, 11, 12, 15, 18
    int numberofrotations( vi&nums ){
        int start = 0;
        int end = nums.size()-1;
        int n = nums.size();
        while(start<=end){
            int mid = start + ((end-start)/2);
            int next = ((mid+1)%n);
            int prev = (mid-1+n)%n;
            if( mid<end && nums[mid+1]<nums[mid] )
                return mid+1;
            if( nums[mid] <= nums[next] && nums[mid] <= nums[prev] ){
                return mid;
            }
            else if( nums[start] <= nums[mid] )
                start = mid+1;
            else if( nums[mid] <= nums[end] )
                end = mid-1;
        }
        return 0;
    }
};

int main()
{
    //int n; cin>>n;
    BS b;
    vi nums = {1,3,5,7,9,11,13};
    cout<<b.ceilele(nums, 0, 6, 2);
    
    return 0;
}

