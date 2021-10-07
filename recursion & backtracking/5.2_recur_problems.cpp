



#include<bits/stdc++.h>
using namespace std;


// *****
// 6 - kth Permutation Sequence
// given a value n and a value k. Here n means a set of [1,2,3,....,n]. 
// And this set contains a total of n! unique permutations. So return the kth 
// permutation when written in lexicographical order
// eg: n=3 and k=3 we have [1,2,3] that is 3!=6 permutations in total
// and 3rd permutation is 2, 1, 3 so print that

string permutation(int n, int k){
    int fact = 1;
    vector<int> numbers;
    for (int i = 1; i < n; i++){
        fact*=i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k=k-1;
    while(true){
        ans = ans + to_string( numbers[k/fact]);
        numbers.erase(numbers.begin() + (k/fact));
        if( numbers.size()==0 )
            break;
        k=k%fact;
        fact = fact / numbers.size();
    }
    return ans;
}

// 7.1 - print all possible permutations of a string/array, return ans in any order [Approach 1]
// eg: given [1,2,3] print [ [1,2,3], [1,3,2], [2,1,3] , [2,3,1], ....] there are n! total permutations print all 
// tc: O(n!*n) sp: O(n) + O(n) [ds + visited]. Space complexity can be bettered
void recurpermute( vector<int> &visited, vector<int> &ds, int arr[], int n, vector<vector<int>> &ans){

    if(ds.size() == n){
        // either print the permutation or push into ans 2d matrix
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if( !visited[i] ){
            visited[i] = 1;
            ds.push_back(arr[i]);
            recurpermute( visited, ds, arr, n, ans);
            ds.pop_back();
            visited[i] = 0;
        }
    }
}
// 7.2 - [Approach 2] same question as above but here we eliminate the space comp. used above like ds and visited
// to remove them we make use of swapping technique, i.e, at every step just swap with all elements
// in front of the current index and then keep recursively calling and then 
// backtrack or undo the swap after recursion call.
// tc: O(n! * n) [n! for generating all permutations and n for we are running a loop for swapping]
// but space complexity is reduced drastically. only space in use is auxiliary space of recursion depth of O(n)
void recurpermute(int index, vector<int> &arr, int n, vector<vector<int>> &ans){
    if(index == n){
        ans.push_back(arr);
        return;
    }
    for (int i = index; i < n; i++)
    {
        swap( arr[i], arr[index] );
        recurpermute( index+1, arr, n, ans);
        swap( arr[i], arr[index]);
    }
}




int main()
{
    // cin.tie(NULL);
    int arr[] = {2,3,6,7};
    vector<int> ds;
    vector<vector<int>> ans;
    // combinationsum( 0, 7, ds, arr, 4, ans);

    return 0;
}



