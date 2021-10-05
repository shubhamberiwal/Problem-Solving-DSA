
#include<bits/stdc++.h>
using namespace std;


// 8 - 
// refer to problem 7 then understand this.
// count the number of paths from start to end in a matrix
// where it will be filled with either 0's or 1's and you
// are allowed to go only in 1's and not in 0's
int matrix[][10];
int oneand0matrixdest(int i, int j, vector<vector<int>> &vis){

    if( i>=n || j>=m || i<0 || j<0 || vis[i][j] == 1 || matrix[i][j] == 0) return 0;

    if( i==n-1 && j==m-1 ){
        return 1;
    }

    vis[i][j] = 1;
    int cnt = 0;
    for (int a = 0; a < 4; a++){
        cnt += oneand0matrixdest( i+di[a], j+dj[a], vis);
    }
    vis[i][j] = 0;
    return cnt;
}


// 7 - Matrix recursion [similar to rat in a maze prob]
// follow up to problem 6. Here you can go L, R, D, U
// and also an addition is that you cannot visited a given coordinate
int n, m;
string din = "DRUL"; // if the question says to print in the lexicographical order then
// just sort the string in the lexicographical order and thus the corresponding values in di and dj
vector<int> di = { 1, 0, -1, 0}, dj = { 0, 1, 0, -1};
void findpathsadv(int i, int j, string s, vector<vector<int>> &vis)
{

    if( i>=n || j>=m || i<0 || j<0 || vis[i][j] == 1 ) return;

    if( i==n-1 && j==m-1 ){
        cout<< s << endl;
        return;
    }

    vis[i][j] = 1;

    for (int a = 0; a < 4; a++)
    {
        s += din[a];
        findpathsadv( i+di[a], j+dj[a], s, vis);
        s.pop_back();
    }
//    ^
//    |
//    |
    // s += "D";
    // findpathsadv(i+1,j,s,vis);
    // s.pop_back();
    // s += "R";
    // findpathsadv(i,j+1,s,vis);
    // s.pop_back();
    // s += "U";
    // findpathsadv(i-1,j,s,vis);
    // s.pop_back();
    // s += "L";
    // findpathsadv(i,j-1,s,vis);
    // s.pop_back();

    vis[i][j] = 0;

}

int main()
{
    cin>>n>>m;
    // n X m vector created
    vector<vector<int>> vis(n, vector<int> (m,0));
    findpathsadv( 0, 0, "", vis);
    
    return 0;
}


// 6 - Matrix recursion [easy or basic version]
// given an n*m matrix, you're allowed to move in either right or down direction
// question is to figure out the possible paths from a start index to an end index
// in the below code snippet assume start point is (0,0) and the end point is (n,m)
// also assume that matrix is globally defined and you have to print the path like "RDDR" [ R - right, D - down ]
void findpaths(int i, int j, string s){

    // one base here is to check if we have
    // crossed the boundaries or not
    if( i>=n || j>=m ) return;

    // base case if we actually manage to reach the final coordinate
    if( i==n-1 && j==m-1 ){
        cout<<s<<endl;
        return;
    }
    // once move downwards
    s += 'D';
    i++; 
    findpaths( i, j, s);
    // backtrack or undo the string and i value
    s.pop_back();
    i--;
    // once move towards right bro
    s += 'R';
    j++;
    findpaths( i, j, s);
    s.pop_back();
    j--;
}



// 5 - return the count of the number of subsequences such that their 
// sum is divisible by k or (sum % k) == 0
int count( int ind, int sum, int arr[], int n, int k){
    
    if( ind>= n){
        if(ind==n){
            if(sum%k==0) return 1;
            else return 0;
        }
    }
    sum+=arr[ind];
    int left = count(ind+1, sum, arr, n, k);
    sum-=arr[ind];
    int right = count(ind+1, sum, arr, n, k);
    return left+right;
}

// 4 - print all subsequences that are divisible by 3
void subdivby3( int ind, vector<int> &ds, int sum, int arr[], int n ){
    
    // base condition
    if( ind >= n ){
        // checking if sum is divisible by 3 and then printing the subsequence
        if( sum%3== 0){
            for(auto it: ds) cout<< it << " ";
            cout<<endl;
        }
        return;
    }

    // we have 2 choices either to add element or leave
    // first we choose the element and call to see all subsequences with the given ds
    ds.push_back( arr[ind] ); sum+=arr[ind];
    subdivby3( ind+1, ds, sum, arr, n);
    // now for the 2nd possibility we have to pop the element and revert the sum back
    // now call the recursion and this time we don't have the element at index 'ind'
    ds.pop_back(); sum-=arr[ind];
    subdivby3( ind+1, ds, sum, arr, n);

    return;
}


// 3 - print all subsequences using recursion
// int arr[] = {1,2,3,4,5};int n=5;
void subsequence(int ind, vector<int> &ds, int arr[], int n){
    
    if( ind>=n ){
        for(auto x: ds){
            cout<< x <<" ";
        }
        cout<<endl;
        return;
    }
    ds.push_back(arr[ind]);
    subsequence(ind+1, ds, arr, n);
    ds.pop_back();
    subsequence(ind+1, ds, arr, n);
}
void printds(vector<int> v){

}

// 2 - checking if string is palindrome
bool palinrecur(string s, int i){
    int n = s.size();
    if( i>=(n>>1) )
        return true;
    if( s[i] == s[n-1-i] )
        return palinrecur(s, i+1);
    return false;
}

// 1 - reversing an array
void reversearray(int arr[], int i, int n){
    if(i>=n/2){
        return ;
    }
    swap(arr[i], arr[n-1-i]);
    reversearray(arr, i+1, n);
}
