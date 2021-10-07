



#include<bits/stdc++.h>
using namespace std;

// tuf problem set

// 1 - Combination sum
// eg: given = {2,3,6,7} and target as 7 print {2,2,3} and {7} as those give the target as 7
// here a given number can be repeated as many times as you want
void combinationsum(int index, int target, vector<int> &ds, int arr[], int n, vector<vector<int>> &ans){
    // base case
    if( index==n ){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    // one condition of picking the element at index
    if( arr[index] <= target ){
        ds.push_back(arr[index]);
        combinationsum(index, target-arr[index], ds, arr, n, ans);
        ds.pop_back();
    }
    // condition of not picking the element
    combinationsum(index+1, target, ds, arr, n, ans);
}

// 2 - Combination sum 2
// given an array of candidates and a target, find unique combinations where cand. sum to give target
// the solution set cannot have duplicate combinations
// eg: {10,1,2,7,6,1,5}, target=8; answers are: [1,1,6], [1,2,5], [1,7], [2,6]
// for this you have to have sorted array so make sure to sort the array first time you call this recursive fun.
void combinationsum2(int index, int target, vector<int> &ds, vector<vector<int>> &ans, int arr[], int n){

    if(target == 0){
        ans.push_back(ds);
        return;
    }

    for (int i = index; i < n; i++)
    {
        if( i>index && arr[i]==arr[i-1])
            continue;
        if( arr[i]>target)
            break;
        ds.push_back(arr[i]);
        combinationsum2( i+1, target-arr[i], ds, ans, arr, n);
        ds.pop_back();
    }
}



// 3 - Palindrome Partitioning
// given a string s, partition s such that every substring of the partition is a palindrome
// return all possible palindrome partitioning of s.
// eg: s="aab" and output will be: [ {"a","a","b"} , {"aa", "b"} ]
bool ispalindrome(string s, int start, int end){
    
    while(start<=end)
    {
        if( s[start++]!=s[end--] )
            return false;
    }
    return true;
}
void palinpartition( int index, string s, vector<string> &storestr, vector<vector<string>> &result )
{
    if( index == s.size() ){
        result.push_back(storestr);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        if( !ispalindrome(s, index, i) ) continue;
        storestr.push_back( s.substr(index, i-index+1));
        palinpartition( i+1, s, storestr, result);
        storestr.pop_back();
    }

}



// 4 - Subset sums 1
// given an array of n, print sums of all subsets in it. Output should be printed in INCREASING order of sums
// eg: {2,3} output: 0 2 3 5. tc: O( 2^N + log(2^N)) AND sc: O(2^NS)
// Navie soln to the problem would be to make use of power set using bit masking
// generate all the subsets here tc: (O(2^N)*N) but optimised soln is shown below, i.e, using recursion
void subsetsum1(int index, int sum, vector<int> &ans, int arr[], int n){
    if(index>=n){
        ans.push_back(sum);
        return;
    }
    // pick the element
    subsetsum1(index+1, sum+arr[index], ans, arr, n);
    // do not pick the element
    subsetsum1(index+1, sum, ans, arr, n);
}

// 5 - Subset sums 2 
// give an array nums that may have duplicate numbers return all possible subsets(the power set)
// make sure the soln. set doesn't have any duplicate subsets. Return the soln in any order.
// Sort the array before passing in the function because if not sorted then the nubers
// may not be together 
void subsetsum2(int index, int arr[], int n, vector<int> &ds, vector<vector<int>> &ans){
    ans.push_back(ds);
    for (int i = index; i < n; i++)
    {
        if( arr[i] == arr[i-1] && i>index) continue;
        ds.push_back(arr[i]);
        subsetsum2(i+1, arr, n, ds, ans);
        ds.pop_back();
    }
}




int main()
{
    // cin.tie(NULL);
    int arr[] = {2,3,6,7};
    vector<int> ds;
    vector<vector<int>> ans;
    combinationsum( 0, 7, ds, arr, 4, ans);

    return 0;
}










// void combinationsum_exp(int index, int target,int sum,vector<int> &ds, int arr[], int n){
//     // base case that sum of subsequence == target
//     if(sum>=target || index>=n){
//         if(sum==target){
//             //print or push the generated subsequence in a ds
//             for( auto x: ds )
//                 cout<<x<<" ";
//             cout<<endl;
//         }
//         return;
//     }
//     //condition where it picks itself and can pick itself again
//     sum+=arr[index];
//     ds.push_back(arr[index]);
//     combinationsum_exp(index, target, sum, ds, arr, n);
//     // condition where it picks itself moves forward and cannot pick itself again
//     combinationsum_exp(index+1, target, sum, ds, arr, n);
//     // condition where it doesn't pick itself and moves forward
//     sum-=arr[index];
//     ds.pop_back();
//     combinationsum_exp(index+1, target, sum, ds, arr, n);
//     return;
// }

