


// https://www.codechef.com/problems/KNPSK
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
    int n=1; cin>>n;
    vi ans(n);
    
    vi one; vi two;
    int totalwt=0;
    for(int i = 1; i<=n; i++ )
    {
        int w,c;cin>>w>>c;
        totalwt += w;
        if(w==1) one.pb(c);
        else two.pb(c);
    }
    sort(one.begin(),one.end());
    sort(two.begin(),two.end());

    vi ONE = one, TWO = two;

    ll cur = 0;
    for(int w = 2; w<=totalwt; w++)
    {
        int cost1=0, cost2=0;
        
        if(two.size()>=1) {
            cost1=two.back();
        }
        int flag = 1;
        if(one.size()>=2) {
            cost2 = one.back();
            cost2 += one[one.back()-2];
        }
        else if( one.size()>=1 ){
            flag = 2;
            cost2 = one.back();
        }
        // seeing where to add
        if(cost1>cost2) {
            cur+=cost1;
            two.pop_back();
        }
        else {
            cur += cost2;
            if(flag==1){
                one.pop_back();
                one.pop_back();
            } else one.pop_back();
        }
        ans[w] = cur;
    }

    // construct odd
    one = ONE, two = TWO;
    cur = 0;
    if(one.size()>=1) {
        cur = one.back();
        one.pop_back();
    }
    ans[1] = cur;
    for(int w=3; w<=totalwt; w+=2) {
        int cost1=0,cost2=0;
        if(two.size()>=1) {
            cost1= two.back();
        }
        int flag=1;
        if(one.size()>=2) {
            cost2 = one.back();
			cost2 += one[one.size() - 2];
        } else if (one.size() >= 1) {
            flag = 2;
            cost2 = one.back();
        }
        if(cost1>cost2){
            cur+=cost1;
            two.pop_back();
        }
        else {
            cur+=cost2;
            one.pop_back();
            if(flag==1) one.pop_back();
        }
        ans[w] = cur;
    }

    for(int i=1; i<=totalwt; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    // for(int i = 2 ; i<=totalwt; i+=2)
    // {
    //     cur += two[i];
    //     ans[i] = cur;
    // }
    
    // cur = 0;
    // if( one.size()>=1 ){
    //     cur = one[0];
    // }

    return 0;
}




// https://www.codechef.com/problems/FGFS

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
// bool cmp(vi&a,vi&b){
//     if(a[2]!=b[2])
//         return a[2]<b[2];
//     if(a[1]!=b[1])
//         return a[1]<b[1];
//     else 
//         return a[0]<=b[0];
// }
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
//         int n=1,k=1; cin>>n>>k;
//
//         vector<vector<int>> mpp(n,vi(3));
//         fer(i,0,n)
//             cin>>mpp[i][0]>>mpp[i][1]>>mpp[i][2]      
//         sort(mpp.begin(),mpp.end(),cmp);
//
//         int cnt = 0;
//         for(int i =0; i<n; i++)
//         {
//             int ref_compartment = mpp[i][2];
//             int dep = mpp[i][1];
//             cnt++;
//             int j = i+1;
//             if(j>=n) break;
//             int flag = 0;
//             while( mpp[j][2] == ref_compartment ) {
//                 // current customer : mpp[i][0] & mpp[i][1];
//                 // if the arrival of subse
//                 if( mpp[j][0]>=dep) {
//                     cnt++;
//                     dep = mpp[j][1];
//                 }
//                 i++;
//                 j++;
//                 if(j>=n) {
//                     flag = 1; break;
//                 }
//             }
//             if(flag) break;
//         }
//         cout<<cnt<<endl;
//     }
//     return 0;
// }





// https://www.codechef.com/submit/LEMUSIC

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
//         int n=1; cin>>n;
//         vector<pi> mpp(n);
//         for(int i=0; i<n; i++) {
//             int b,l; cin>>b>>l;
//             mpp[i] = {b,l};
//         }
//         sort(mpp.begin(),mpp.end());
//     
//         vi band; ll total_time = 0;
//
//         // finding each bands shortest song and also adding rest of the songs length
//         for(int i = 0; i<n; i++)
//         {
//             if( i==0 || mpp[i-1].first < mpp[i].first )
//                 band.pb(mpp[i].second);
//             else
//                 total_time += mpp[i].second;
//         }
//         int diff_songs = band.size();
//
//         sort(band.begin(),band.end());
//         ll ans = diff_songs * total_time;
//         for(ll i =0; i<band.size(); i++ ) {
//             ans = ans + ((i+1)*band[i]) ;
//         }            
//         cout<<ans<<endl;   
//     }
//     return 0;
// }


