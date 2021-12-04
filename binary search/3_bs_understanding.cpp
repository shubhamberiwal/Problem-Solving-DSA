
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;

class BS{
    int binarysearch(int start, int end, vi &nums, int target){
        
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

    int firstoccurence( int start, int end, vi&nums, int target){
        if(start>end)
            return -1;
        int mid = start + (end-start)/2;
        if( (mid==0 || target>nums[mid-1]) && nums[mid] == target )
            return mid;
        else if( target>nums[mid] )
            return firstoccurence( mid+1, end, nums, target);
        else return firstoccurence( start, mid-1, nums, target);
    }
    public:

    // 16 - search in a bitonic array
    // simple idea just use previous prob to find the index of the peak element
    // after that divide the array into 2 halves and do the binary search individually on each half,
    // first half will be sorted so run normal bs, but next half will be sorted in desc. order
    // so call the bs accordingly for a descending sorted array(Tread carefully while implementing)

    // 15 - find Max in Mountain array or bitonic array
    // bitonic array means first strictly increasing then strictly decreasing after a peak element
    // return the index of the peak element
    // This sort of array contains only 1 peak elelment and if we use the previous problem's code
    // for this problem's solution, it will give the correct answers
    // Still a different code implementation below just for better understanding of
    // just how this is different from previous problem
    int bitonicarray( vi&nums, int start, int end){

        if(start==end)
            return start;
        if( start+1==end && nums[start]>nums[end] )
            return start;
        if( start+1==end && nums[start]<nums[end] )
            return end;
        int mid = start + (end - start)/2;
        if( nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1] )
            return mid;
        else if( nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1] )
            return bitonicarray( nums, mid+1, end);
        else
            return bitonicarray( nums, start, mid-1);
    }

    // 14.2 - Peak Element
    // iterative way simpler to understand
    int peakele ( vi&nums, int start, int end ){
        int n = nums.size();
        if(n==1) // edge case check 
            return start;
        while(start<=end){
            int mid = start + (end-start)/2;
            if( mid>0 && mid<n-1){
                if( nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1] )
                    return mid;
                else if( nums[mid]<nums[mid-1] )
                    end = mid-1;
                else start = mid+1;
            }
            else if( mid==0 ){
                if(nums[0]>nums[1])
                    return 0;
                return 1;// if 2nd element in array is a peak
            }
            else {
                if(nums[n-1]>nums[n-2])
                    return n-1;
                return n-2; // if last second element is a peak
            }
        }
        return -1;
    }

    // 14 - Peak Element problem
    int peakelement( vi &nums, int start, int end ){
        
        int mid = start + (end-start)/2;
        if( (mid==0 || nums[mid]>=nums[mid-1]) && (nums[mid]>=nums[mid+1] || mid==nums.size()-1) )
            return mid;
        else if( mid<(nums.size()-1) && nums[mid]<nums[mid+1] )
            return peakelement( nums, mid+1, end );
        else return peakelement( nums, start, mid-1 );
    }

    // 13 - Minimum Difference Element in sorted array
    // eg: given a sorted array nums and a number target
    // return the ele. in the array with smallest 
    // absolute difference with the target element
    int mindiff( vi&nums, int start, int end, int target ){
        // check for the edge cases
        if(target<=nums[start])
            return nums[start];
        else if(target>=nums[end])
            return nums[end];
        
        // note: if the target element is not presetn in the array then binary search filters and
        // try to reach to the nearest possible values to the target element and the algo at the end 
        // will always have start and end point to the elements that bigger and smaller than the target
        // element. It's not something special it's just that it happens all the time, and this problem
        // is designed for you to notice it and remember this property dumbhead!!
        // In simpler words at end of this while loop if key is not present then
        // nums[start] is ceil of the target element and nums[end] is floor of the same
        // find the minimum abs diff b/w the 2 now.
        while(start>=end){
            int mid = start + (end-start)/2;
            if( target == nums[mid] )
                return mid;
            else if( target < nums[mid] )
                end = mid-1;
            else 
                start = mid+1;
        }
        if( (nums[start]-target) < (target-nums[end]) )
            return nums[start];
        return nums[end];
    }

    // 12 - find index of first 1 in an infinite binary sorted array
    // eg: 0000000000011111111.... , output: return the index of first 1
    // combination of last problem and problem to find first occurence of a no. in sorted array
    int infinitebinary1( vi&nums ){
        int start = 0;
        int end = 1;
        if( nums[start]==1)
            return start;
        while(nums[end]!=1){
            start = end;
            end = end*2;
        }
        return firstoccurence(start, end, nums, 1);
    }

    // 11 - return index of the element in an infinite sorted array
    // not possible ofc but assume given an infinite sorted array
    // return the index of the target element if present if not then return -1
    int infinitebs( vi&nums, int target){
        int start = 0;
        int end = 1;
        while(target>nums[end]){
            start = end;
            end = end*2;
        }
        int ans = binarysearch(start, end, nums, target);
        return ans;
    }

    // 10 - Next Character in Alphabet
    // almost similar to ceil of a number problem in integers
    // one change if even item is found return the next smallest
    // but this method is more easy to understand than written in previous answer
    // although it has extra constant time lines but is easier to understand
    int nextalpha( string&nums, int start, int end, char target){
        // char ceil = ' ';
        if(start>end)
            return -1;
        if(((int)target)<((int)nums[start]))// a simple (target<nums[start]) will also work
            return 0;
        int mid = start + (end-start)/2;
        if( nums[mid] == target)
            return nextalpha( nums, mid+1, end, target);// instead of returning the mid value
            // we are calling right of string because question states that they only want next 
            // smallest present in the given array
        if( ((int)target)<((int)nums[mid]) ){
            if( mid>start && target>=nums[mid-1] )
                return mid;
            return nextalpha( nums, start, mid-1, target );
        }
        if(mid<end && target<nums[mid+1])
            return mid+1;
        return nextalpha( nums, mid+1, end, target );
    }


    // iterative approach for ceil method
    // int ceilfound( vi&nums, int start, int end, int target){
    //     int ceil = -1;
    //     while(start<=end){
    //         int mid=start+(end-start)/2;
    //         if(nums[mid]==target){
    //             return mid;
    //         }
    //         else if(target<nums[mid]){
    //             ceil = mid;
    //             cout<<ceil<<endl;
    //             end = mid-1;
    //         }
    //         else start = mid+1;
    //     }
    //     return ceil;
    // }
};

int main()
{
    BS b;
    vector<char> nums2={'b','c','e','g','i','k'};
    string nums3 = "bdfhkmq";
    // cout<<b.peakelement(nums1, 0, 5);
    vector<int> nums1 = {-1};
    // cout<<nums1[0]<<endl;
    // cout<<nums1[1];
    cout<<b.peakele(nums1, 0, 0);
    // cout<<b.nextalpha(nums3,0,5,'h')<<endl;
    // cout<<b.ceilfound(nums, 0, 6, 10)<<endl;
    return 0;
}

