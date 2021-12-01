

#include<bits/stdc++.h>
using namespace std;


// 6 - longest substring without repeating characters
// optimal approach
// 
int longestsubstr(string s)
{
    int n = s.size();
    map<char,int> hashmap;
    int start = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if( hashmap.find(s[i]) != hashmap.end()) start = max(start, hashmap[s[i]] +1);
        hashmap[s[i]] = i;
        maxi = max( maxi, i-start+1);
    }
    return maxi;
}

// left and right pointer method
int longsub(string s)
{
    int n = s.size();
    int left = 0;
    int right = 0; int maxi=0;
    set<char,greater<char>> hashset;
    while( right<n)
    {
        if( hashset.count(s[right])){
            //if hashset contains move left pointer and delete
            while( hashset.count(s[right])){
                hashset.erase(s[left]);
                left++;
            }
            hashset.insert(s[right]);
        }
        else{
            // just push
            hashset.insert(s[right]);
            maxi = max(maxi, right-left+1);
        }
        right++;
    }
    return maxi;
}


// 5 - Count the number of subarrays having a given xor
// arr[] and m given, count the number of subarray having xor of their elements as m
// {4,2,2,6,4}, m=6 subarrays are: (4,2), (4,2,2,6,4), (2,2,6) and (6) therefore total count is 4
int countxor(vector<int> &nums, int m)
{
    int n = nums.size();
    map<int,int> hashmap;
    int xorsum=0, count=0;
    for (int i = 0; i < n; i++)
    {
        xorsum ^= nums[i];
        if(xorsum == m){
            // here just increase the count
            count++;
        }
        
        int y = xorsum ^ m;
        if( hashmap.find(y) == hashmap.end()){
            if( hashmap.count(xorsum)){
                hashmap[xorsum] ++;
            }
            else{
                hashmap[xorsum] = 1;
            }
        }
        else{
            int temp = hashmap[y];
            count= count+temp;
            if( hashmap.count(xorsum)){
                hashmap[xorsum] ++;
            }
            else{
                hashmap[xorsum] = 1;
            }
        }
    }
    return count;   
}
// very optimal
int countxor2(vector<int> &nums, int m)
{
    map<int,int> hashmap;
    int xorsum=0, count=0;
    for (auto it: nums)
    {
        xorsum = xorsum ^ it;

        if(xorsum==m)
            count++;
        
        if(hashmap.find(xorsum^m)!=hashmap.end())
            count += hashmap[xorsum^m];
        
        hashmap[xorsum] += 1;
    }
    return count;
}


// 4 - largest subarray with 0 as its sum
// optimal approach
// store prefix sum with its index in a hashmap
int largestsubarrayzero(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> hashmap;
    int sum = 0;int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if( sum == 0 ){
            //compare max with the size i directly
            maxi = i+1;
        }
        else if ( hashmap.count(sum) ){
            // till found index the sum was same so the following indexes result in 0
            // int temp = i - (hashmap.find(sum))->second;
            int temp = i - hashmap[sum];
            maxi = max(maxi, temp);
        }
        else{
            hashmap[sum] = i;
            // hashmap.insert(sum,i);
        }
    }
    return maxi;
}

// 4 - largest subarray with 0 as its sum
// brute force 
int largestzerosub(vector<int> &nums)
{
    int n = nums.size();
    int maxsofar = 0, current=0;
    int maxi=-1,sum;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum+=nums[j];
            int length = j-i+1;
            if(sum == 0)
                if(maxi<length) maxi = length;
        }   
    }
    return maxi;
}


// 3 - longest consecutive sequence
// eg: [ 102, 4, 100, 1, 101, 3, 2] here there are 2 streaks: 1,2,3,4 and 100,101,102; return the longest.
// o(nlogn + n) time is when you sort and then find the longest consecutive sequence
// below is o(3n) time
int longestconsecutive(vector<int> &arr)
{
    set<int> hashset;
    for( auto x: arr){
        hashset.insert(x);
    }
    int longestStreak = 0;
    for(int num: arr){
        if( !hashset.count(num-1)){

            int currentele = num;
            int counter = 1;
            while( hashset.count(currentele+1) ){
                currentele++;
                counter++;
            }
            longestStreak = max(longestStreak, counter);
        }
    }
    return longestStreak;
}


// 2 - four sum problem  INCOMPLETE **
// brute force method
// first sort the array, then use 3 pointer method 
// each loop will start from the element right to previous pointer
// then run binary search on the right half of array to search for quartet
// left half is taken care off by the pointer system
vector<vector<int>> foursum2(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> result;
    for (int i = 0; i < n-3; i++)
    {
        for (int j = i+1; j < n-2; j++)
        {
            for (int k = j+1; k < n-1; k++)
            {
                int temp = nums[i] + nums[j] + nums[k];
                vector<int>:: iterator it1 = nums.begin();
                it1 = it1+k+1;
                cout<<*it1<<endl;
                binary_search( it1 , nums.end() , (target-temp) );
                // incomplete
            }
        }
    }
    return result;
}

// 2 - optimal four sum. 2 Pointer and hashing concept
// take i and j and then left and right for the rest of right part
// make sure to jump over duplicates in each step
vector<vector<int>> foursum(vector<int>&nums, int target)
{
    vector<vector<int>> res;
    if(nums.empty())
        return res;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int target2 = target - nums[i] - nums[j];
            int left = j+1;
            int right = n-1;
            while(left < right){
                int twosum = nums[left] + nums[right];
                if(twosum<target2)
                    left++;
                else if(twosum>target2)
                    right--;
                else{
                    vector<int> quartet(4,0);
                    quartet[0] = nums[i];
                    quartet[1] = nums[j];
                    quartet[2] = nums[left];
                    quartet[3] = nums[right];
                    res.push_back(quartet);

                    while( left < right && quartet[2] == nums[left] ) ++left;
                    while( left < right && quartet[3] == nums[right] ) right--;
                }
            }
            while(j+1 < n && nums[j] == nums[j+1]) j++;
        }
        while(i+1 < n && nums[i] == nums[i+1]) i++;
    }
    return res;
}


// 1 - two sum Problem
// optimal
pair<int,int> twosum( vector<int> &arr, int target)
{
    pair<int,int> ans;
    int n = arr.size();
    cout<<n<<endl;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        // check if target - arr[i] , the number is there in the hashset
        int temp = target - arr[i];
        if(mpp.find(temp)!=mpp.end()){
            ans.first = mpp[temp];
            ans.second = i;
            // map<int,int>:: iterator it = (mpp.find(temp));
            // ans.second = (*it).second;
        }
        else mpp[arr[i]] = i;
    }
    return ans;
}




int main()
{
    vector<int> arr = {2,7,8,18};
    // pair<int, int> ans = twosum(arr, 9);
    // cout<< arr[ans.first]<<endl;
    // cout<< arr[ans.second];
    
    // vector<int> arr2 = {1,-1,3,2,-2,-8,1,7,10};
    // int k = largestsubarrayzero( arr2);
    // int p = largestzerosub( arr2);
    // cout<<p;

    string s = "abcaabcdba";
    cout<<longestsubstr(s);
    return 0;
}