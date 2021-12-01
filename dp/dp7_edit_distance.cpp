

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;



// if you reach the end of s1 then you have to just add rest of s2, so it takes s2.size() - j operations
// similarly, if you reach the end of s2 then you have to just remove rest of s1, so that takes s1.size() - i operations

// if characte is same tab kuch nai karna hai aage badh jao

// INSERTION/LEFT mei tum s1 mei insert karke uska size badha rha hai aur s2 ka jth character match kara rha hai
// toh recursive call mai (i,j+1) hoga
// REMOVAL/MID mai tum s1 ka size gatha rha ith char delete karke hai kyuki s2 ka jth char match nai hua
// toh recursive call mai (i+1, j) hoga
// REPLACE/RIGHT mai dono match karake aage badh rha hai toh (i+1,j+1)

int edit(int i, int j, string s1, string s2)
{
    if( i==s1.size()) return s2.size()-j;

    if( j==s2.size()) return s1.size()-i;

    if( s1[i]==s2[j] ) {
        return edit(i+1,j+1,s1,s2);
    }
    else {
        // here you add +1 because you're doing 1 operation 
        // be it removal, deletion or replacement
        int left = 1 + edit(i,j+1,s1,s2);
        int mid = 1 + edit(i+1,j,s1,s2);
        int right = 1 + edit(i+1,j+1,s2,s2);
        return min(left,min(right,mid));
    }
}

// so i and j are changing from 0 to n-1 and 0 to m-1 resp.
// bottom up approach
int edit_dp(int i, int j, string s1, string s2, vector<vi>&dp)
{
    if( i==s1.size()) return s2.size()-j;

    if( j==s2.size()) return s1.size()-i;

    if( dp[i][j]!=-1 ) return dp[i][j];

    if( s1[i]==s2[j] ) {
        return dp[i][j] = edit_dp(i+1,j+1,s1,s2,dp);
    }
    else {
        int left = 1 + edit_dp(i,j+1,s1,s2,dp);
        int mid = 1 + edit_dp(i+1,j,s1,s2,dp);
        int right = 1 + edit_dp(i+1,j+1,s2,s2,dp);
        return dp[i][j] = min(left,min(right,mid));
    }
}

int main()
{
    //int n; cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    cout<<edit(0,0,s1,s2);
    vector<vi> dp(n,vi(m,-1));
    cout<<edit_dp(0,0,s1,s2,dp);
    
    return 0;
}




