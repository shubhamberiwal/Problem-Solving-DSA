

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;

class BS{
    
    // 4.3 - find the count of a particular number in a sorted array
    int countofanumber( vi&nums, int target){
        // use the 2 previous function to find the first and last 
        // occurence of that particular number and the subtract it
        // to get the count

        // int firstindexof = findfirstoccurence(nums, target);
        // int lastindexof = findlastoccurence(nums, target);
        // return (lastindexof-firstindexof+1);
        return -1;
    }

    // 4.2 - find last occurence of a number in a sorted array
    int findlastoccurence( vi&nums, int target){

        int start = 0;
        int end = nums.size()-1;
        int res=-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(target = nums[mid]){
                res = mid;
                start = mid+1;
            }
            else if(target<nums[mid])
                end = mid-1;
            else start = mid+1;
        }
        return res;
    }

    // 4.1 - find first occurence of a number in a sorted array
    int findfirstoccurence( vi&nums, int target){

        int start = 0;
        int end = nums.size()-1;
        int res=-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(target = nums[mid]){
                res = mid;
                end = mid-1;
            }
            else if(target<nums[mid])
                end = mid-1;
            else start = mid+1;
        }
        return res;
    }

    // 3 - order agnostic search
    int binarysearchagnostic( vi&nums, int target){
        if( nums.size()==1 ){
            if(target == nums[0])
                return 0;
        }
        else{
            int start = 0, end = nums.size()-1;
            while(start<=end){
                int mid = start+ (end-start)/2;
                if(target==nums[mid])
                    return mid;
                if( target<nums[mid]){
                    if( nums[0]>nums[1] )
                        start = mid+1;
                    else end = mid-1;
                }
                else{
                    if( nums[0]>nums[1] )
                        end = mid-1;
                    else start = mid+1;
                }
            }
        }
        return -1;
    }

    // 2 - given an array in reverse sorted order
    // perform binary search on it
    int binarysearchreverse(vi &nums, int target){
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = start + ((end-start)/2) ;
            if( target == nums[mid] )
                return mid;
            else if( target < nums[mid] )
                start = mid+1;
            else
                end = mid-1;
        }
        return -1;
    }

    // 1.2 - recursive approach
    // you're given a sorted array
    int binarysearch( int start, int end, vi &nums, int target){
        if(start<=end){
            int mid = start + (end-start)/2;
            if( target == nums[mid] )
                return mid;
            else if( target < nums[mid] )
                return binarysearch( start, mid-1, nums, target);
            else
                return binarysearch( mid+1, end, nums, target);
        }
        return -1;
    }

    // 1.1 - iterative approach
    // one calculates the mid value this way because when 
    // int values are close to their specified limit then
    // (start + end) might overflow even before you divide them 
    // by 2 and then use them so this is a better way to write
    // to prevent overflow
    // mid = start + (end-start)/2
    int binarysearch1(vi &nums, int target){
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = start + ((end-start)/2) ;
            if( target == nums[mid] )
                return mid;
            else if( target < nums[mid] )
                end = mid-1;
            else
                start = mid+1;
        }
        return -1;
    }
};


int main()
{
    BS b;
    vi nums = {11,12,15,18,2,5,6,8};
    // cout<<numberofrotations( nums );
    return 0;
}

