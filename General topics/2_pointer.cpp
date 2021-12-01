
#include<bits/stdc++.h>
using namespace std;

// tuf - striver

// 1 - 3 Sum problem optimal
// find 3 elemets in array that sum up to give 0
void question3sum(vector<int> &nums,int n)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    
    for (int i = 0; i < n-2; i++)
    {
        if(i==0 ||  (i>0 && nums[i] !=nums[i-1])){
            int a = 0 - nums[i];
            int low=i+1; int high = n-1;
            
            while( low < high ){
                int temp = nums[low]+nums[high] ;
                if(temp == a){
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[low]);
                    t.push_back(nums[high]);
                    res.push_back(t);
                    while(low<high && nums[low] == nums[low+1]) low++;
                    while(low<high && nums[high] == nums[high-1]) high--;
                    low++;high--;
                }
                else if(temp<a)low++;
                else high--;
            }
        }
    }
    for(auto x: res){
        for( auto y: x){
            cout<<y<< " ";
        }
        cout<<endl;
    }
}
// 2 - Trapping Rainwater
// brute method at each step apart from the end indexes calculate the
// max tower on left and max on right take min of both and subtract tower height at that position
// you will get the rain trapped in that index
// tc: O(n^2) sp: O(1) below implemented by O(n) sc
void trappingwater(vector<int> nums, int n){
    vector<int> trap(n);
    for (int i = 1; i < n-1; i++)
    {
        int leftmax = 0, rightmax = 0; 
        for (int j = i; j >=0 ; j--)
            leftmax= max(leftmax, nums[j]);
        for (int j = i; j < n; j++)
            rightmax = max(rightmax, nums[j]);
        trap[i] = min(leftmax, rightmax) - nums[i];
    }
    int ans=0;
    for(auto x: trap) ans+=x;
    cout<<ans<<endl;
}
// 2 - Trapping RainWater
// better method. Calculating prefix max height from both the sides and then storing them in arrays
// now traverse throught and calculate the water stored in each index
// tc: O(3N) sp: O(2N)
void trappingwater2(vector<int> nums, int n){
    int res=0;
    vector<int> prefixleft(n), prefixright(n);
    prefixleft[0] = nums[0] , prefixright[n-1] = nums[n-1];
    for (int i = 1; i < n; i++)
        prefixleft[i] = max(prefixleft[i-1], nums[i]);
    for (int i = n-2; i >=0 ; i--)
        prefixright[i] = max(prefixright[i+1], nums[i]);
    for (int i = 1; i < n-1; i++)
        res += (min(prefixleft[i], prefixright[i]) - nums[i]);
    cout<<res<<endl;
}
// 2 - Trapping Rainwater
// Optimal. Take 2 pointers on either end. Take leftmax and rightmax too
// 
void trappingwater3(vector<int> height, int n){
    int left=0, right = n-1;
    int leftmax = 0, rightmax=0, res=0;
    while(left<=right){

        if( height[left] <= height[right]){
            if( height[left]>=leftmax) leftmax=height[left];
            else res += (leftmax-height[left]);
            left++;
        }
        else{
            if( height[right]>=rightmax) rightmax = height[right];
            else res+= (rightmax-height[right]);
            right--;
        }
    }
}

// 3 - Remove Duplicates from Sorted Array
// eg: {1,1,2}, output: {1,2} only 2 numbers are unique
// return the number of unique numbers in the array
// tc: O(n) sp: O(1)
int removeduplicates(int n, vector<int> nums)
{
    if(n==0) return 0;
    int count=0;
    for (int i = 1; i < n; i++)
    {
        if( nums[count]!= nums[i] )
        {   count++;
            nums[count] = nums[i];
        }
    }
    // return the number of unique elemens in the array
    return count+1;
}

// 4 - Max Consecutive ones
// given a binary array find maximum consecutive number of 1's
// Eg: {1,1,0,1,1,1}, output will be : 3
int countconsecutiveones(vector<int> nums){
    int n = nums.size();
    int maxi = 0, currentcount = 0;
    for (int i = 0; i < n; i++){
        if(nums[i]){
            currentcount++;
            maxi = max(maxi, currentcount);
        }
        else currentcount=0;
    }
    return maxi;    
}
// 5 - question 4-SUM . Hashing and 2 pointer approach
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

                    if( left < right && quartet[2] == nums[left] ) ++left;
                    if( left < right && quartet[3] == nums[right] ) right--;
                }
            }
            if(j+1 < n && nums[j] == nums[j+1]) j++;
        }
        if(i+1 < n && nums[i] == nums[i+1]) i++;
    }
    return res;
}

int main()
{
    int n; cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin>>nums[i];
    }
    question3sum(nums, n);
    
    return 0;
}

