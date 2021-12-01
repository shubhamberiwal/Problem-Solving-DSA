


// 1 - https://www.spoj.com/problems/BAISED/
// 2 - https://www.spoj.com/problems/BALIFE/
// 3 - https://www.spoj.com/problems/GCJ101BB/
// 4 - https://www.spoj.com/problems/ARRANGE/
// 5 - https://www.spoj.com/problems/FASHION/



// 1 - https://www.spoj.com/problems/BAISED/

// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r", stdin);
//         freopen("output.txt","w", stdout);
//     #endif
//     cin.tie(NULL);
//     cout.tie(0);
//     int t=1; cin>>t;
//     while(t--)
//     {
//         ll n; cin>>n;
//         vector<ll> mpp(n);
//         for(ll i=0; i<n; i++) {
//             string s; cin>>s;
//             cin>>mpp[i];
//         }
//         sort(mpp.begin(),mpp.end());
//         ll inc=0;
//         for(ll i=0; i<n; i++)
//             inc += abs(mpp[i]-(i+1));
//         cout<<inc<<endl;
//     }
//     return 0;
// }





// 2
// https://www.spoj.com/problems/BALIFE/

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
//     while(true)
//     {
//         int n=1; cin>>n; if(n==-1) break;
//         vi arr(n);
//         int sum=0;
//         fer(i,0,n) {
//             cin>>(arr[i]);
//             sum+=arr[i];
//         }
//         if(sum%n!=0){
//             cout<<-1<<endl;
//             continue;
//         }
//         ll avg = sum/n;
//         int op = 0;
//         for(int i =0; i<n-1; i++)
//         {
//             int x = avg - arr[i];
//             if( x<0 ) { // dena hoga right ko
//                 x = abs(x);
//                 arr[i] = avg;
//                 arr[i+1] = arr[i+1] + x;
//                 op = max(op, x);
//                 // op = abs(avg-arr[i]);
//             }
//             else { // lena hoga bagal wale se
//                 arr[i] = avg;
//                 arr[i+1] = arr[i+1] - x;
//                 op = max(op,x);
//             }
//         }
//         cout<<op<<endl;
//     }
//     return 0;
// }





// 3 - https://www.spoj.com/problems/GCJ101BB/

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
//
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r", stdin);
//         freopen("output.txt","w", stdout);
//     #endif
//     int q=1; cin>>q;
//     int z=1;
//     while(q--)
//     {
//         int n,k,b,t; cin>>n>>k>>b>>t;
//         vector<int> location(n); fer(i,0,n) cin>>(location[i]);
//         vector<int> velocity(n); fer(i,0,n) cin>>(velocity[i]);
//         //O(c*2n)
//         vector<float> timetaken(n);
//         int cnt = 0;
//         for(int i =0; i<n; i++)
//         {
//             timetaken[i] = ((b - location[i])*1.0) / velocity[i];
//             if(timetaken[i] <= t){ 
//                 cnt++;
//             }else timetaken[i] = -1;
//         }
//         if(cnt<k) {
//             cout<<"Case #"<<z<<": IMPOSSIBLE"<<endl;
//             z++;
//             continue;
//         }
//         cnt = 0;
//         int swaps = 0;
//         int jumps = 0;
//         for(int i = n-1; i>=0; i--) {
//             if(cnt == k) break;
//             if(timetaken[i]>=0){
//                 cnt++;
//                 swaps += jumps;
//             }
//             else jumps++;
//         }
//         cout<<"Case #"<<z<<": "<<swaps<<endl;
//         z++;
//     }
//     return 0;
// }





// 4 - https://www.spoj.com/problems/ARRANGE/

// #include<bits/stdc++.h>
// #define fer(i,a,b) for(re i = a; i<b; ++i)
// #define re register int
// #define ll long long
// using namespace std;
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
//         int ones = 0;
//         fer(i,0,n) {
//             cin>>(arr[i]);
//             if(arr[i]==1) ones++;
//         }
//         sort(arr.begin(),arr.end(),greater<int>());
//
//         for(int i=0; i<ones; i++) cout<<1<<" ";
//      
//         if( (n-ones)==2 && arr[0]==3 && arr[1]==2 )
//             cout<<"2 3"<<endl;
//         else {
//             for(int i = 0; i<(n-ones); i++) cout<<arr[i]<<" ";
//             cout<<endl;
//         }
//     }
//     return 0;
// }





// 5 - https://www.spoj.com/problems/FASHION/

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
//         vi hm(n); fer(i,0,n) cin>>(hm[i]);
//         vi hw(n); fer(i,0,n) cin>>(hw[i]);
//         sort(hm.begin(),hm.end(),greater<int>());
//         sort(hw.begin(),hw.end(),greater<int>());
//         int count = 0;
//         for(int i = 0; i<n; i++ )
//         {
//             count += (hw[i] * hm[i]);
//             if( hw[i]==0 || hm[i]==0 ) break;
//         }
//         cout<<count<<endl;
//     }
//     return 0;
// }




