

// 1 - https://www.codechef.com/problems/ALTARAY
// 2 - https://www.codechef.com/problems/DELISH



// 3 - https://www.codechef.com/problems/DBOY

#include<bits/stdc++.h>
#define fer(i,a,b) for(re i = a; i<b; ++i)
#define re register int
#define sf(x) scanf("%d", &x)
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    int t=1; cin>>t;
    while(t--)
    {
        int n=1; cin>>n; 
        vector<int> arrn(n);
        fer(i,0,n)
            cin>>(arrn[i]);
        vector<int> arrk(n);
        fer(i,0,n)
            cin>>(arrk[i]);
        
        
    }
    return 0;
}



// 1 - https://www.codechef.com/problems/ALTARAY

// #include<bits/stdc++.h>
// #define fer(i,a,b) for(re i = a; i<b; ++i)
// #define re register int
// #define sf(x) scanf("%d", &x)
// #define pb push_back
// #define ll long long
// #define mod 1000000007
// using namespace std;
// typedef vector<int> vi;
// typedef pair<int,int> pi;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r", stdin);
//         freopen("output.txt","w", stdout);
//     #endif
//     int t=1; cin>>t;
//     while(t--)
//     {
//         int n=1; cin>>n; vector<int> arr(n);
//         fer(i,0,n)
//             cin>>(arr[i]);        
//         if(n==1) {
//             cout<<1<<endl;
//             continue;
//         }
//         vi ans(n,1);
//         for(int i=n-2; i>=0; i--)
//         {
//             if( (arr[i]>0 && arr[i+1]<0) || (arr[i]<0 && arr[i+1]>0) ) {
//                 ans[i] += ans[i+1];
//             }
//         }
//         for(int i=0; i<ans.size(); i++)
//             cout<<ans[i]<<" ";
//         cout<<endl;
//     }
//     return 0;
// }





// 2 - https://www.codechef.com/problems/DELISH

// #include<bits/stdc++.h>
// #define fer(i,a,b) for(re i = a; i<b; ++i)
// #define re register int
// #define sf(x) scanf("%d", &x)
// #define pb push_back
// #define ll long long
// #define mod 1000000007
// using namespace std;
// typedef vector<int> vi;
// typedef pair<int,int> pi;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r", stdin);
//         freopen("output.txt","w", stdout);
//     #endif
//     int t=1; cin>>t;
//     while(t--)
//     {
//         int n=1; cin>>n; vector<int> arr(n);
//         fer(i,0,n)
//             cin>>(arr[i]);
        
//         for(int i=0; i<n; i++)
//         {

//         }
        
//     }
//     return 0;
// }




