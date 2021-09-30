

// https://www.codechef.com/problems/GCDQ
// practice problem on prefix gcd


// here take the prefix gcd from left to right in 1st array
// and take the suffix gcd from right to left in 2nd array
// tc: O(t*n)
#include<bits/stdc++.h>
#define fer(i,a,b) for(re i = a; i<b; ++i)
#define re register int
#define sf(x) scanf("%d", &x)
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;

int gcdd(int a, int b) {
    if(b==0)
        return a;
    return gcdd(b,a%b);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    cin.tie(NULL);
    int t; cin>>t;
    // O(t*n)
    while(t--)
    {
        int n,q; cin>>n>>q; vector<int> arr(n);
        fer(i,0,n)
            sf(arr[i]);
        vi prefixgcd1(n,0);
        prefixgcd1[0] = arr[0];
        for (int i = 1; i < n; i++)
            prefixgcd1[i] = gcdd(prefixgcd1[i-1],arr[i]);
        vi prefixgcd2(n,0);
        prefixgcd2[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--)
            prefixgcd2[i] = gcdd(prefixgcd2[i+1],arr[i]);
        fer(i,0,q) {
            int a, b;
            cin>>a>>b;
            a--; b--;
            int ans1 = 0;
            if(a>0){
                ans1 = prefixgcd1[a-1];
            }
            int ans2 = 0;
            if(b<n-1) { 
                ans2 = prefixgcd2[b+1];
            }
            int result = gcdd(ans1,ans2);
            cout<<result<<endl;
        }
    }
    return 0;
}





// brute force approach
// will only pass only 40% of test cases
// tc: O(t*q*n)
// #include<bits/stdc++.h>
// #define fer(i,a,b) for(re i = a; i<b; ++i)
// #define re register int
// #define sf(x) scanf("%d", &x)
// #define pb push_back
// using namespace std;
// typedef vector<int> vi;
// typedef pair<int,int> pi;
// typedef long long ll;
// int gcdd(int a, int b){
//     if(b==0)
//         return a;
//     return gcdd(b,a%b);
// }
// int main()
// {
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r", stdin);
//         freopen("output.txt","w", stdout);
//     #endif
//     cin.tie(NULL);
//     int t; cin>>t;
//     while(t--)
//     {
//         int n,q; cin>>n>>q;
//         vector<int> arr(n);
//         fer(i,0,n)
//             sf(arr[i]);
//         fer(i,0,q) {
//             int a,b;
//             cin>>a>>b;
//             a--; b--;
//             int ans1=0, ans2=0;
//             for (int j = 0; j < a; j++) {
//                 ans1 = gcdd(arr[j],ans1);
//             }
//             for (int j = b+1; j < n; j++) {
//                 ans2 = gcdd(arr[j],ans2);
//             }
//             int ans = gcdd(ans1,ans2);
//             cout<<ans<<endl;
//         }
//     }
//     return 0;
// }



