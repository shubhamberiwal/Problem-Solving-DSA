


// Basics to Medium - Greedy Algorithm




// 1 - https://www.codechef.com/problems/TACHSTCK
// 2 - https://www.codechef.com/problems/CIELRCPT
// 3 - https://www.codechef.com/problems/MAXDIFF
// 4 - https://www.codechef.com/problems/CHEFST
// 5 - https://www.codechef.com/problems/CLETAB
// 6 - https://www.codechef.com/problems/TADELIVE
// 7 - https://www.codechef.com/problems/MANYCHEF
// 8 - https://www.codechef.com/problems/CHEFTMA
// 9 - https://www.codechef.com/problems/STICKS



// 1
// https://www.codechef.com/problems/TACHSTCK

// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;
// typedef vector<int> vi;
// int main()
// {
//     // ios_base::sync_with_stdio(false);
//     // #ifndef ONLINE_JUDGE
//     //     freopen("input.txt","r", stdin);
//     //     freopen("output.txt","w", stdout);
//     // #endif
//     // cin.tie(NULL);
//     // cout.tie(0);
//     ll n,d; cin>>n>>d;
//     vi arr(n);
//     for (ll i = 0; i < n; i++)
//         cin>>arr[i];
//     sort(arr.begin(),arr.end());
//     ll count = 0;
//     for (ll i = 0; i < n-1; )
//     {
//         if( (arr[i+1]-arr[i]) <= d ){
//             count++; i+=2;
//         }
//         else i++;
//     }
//     cout<<count;
//     return 0;
// }





// 2
// https://www.codechef.com/problems/CIELRCPT

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
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r", stdin);
//         freopen("output.txt","w", stdout);
//     #endif
//     cin.tie(NULL);
//     cout.tie(0);
//     int t; cin>>t;
//     while(t--)
//     {
//         int p; cin>>p;
//         int count = 0;
//         for (int i = 11; i >=0; i--)
//         {
//             int power_of_2 = (1<<i);
//             int quo = p/power_of_2;
//             if(quo!=0) {
//                 count += quo;
//             }
//             p = p%power_of_2;
//             if(p==0) break;
//         }
//         cout<<count<<endl;
//     }
//     return 0;
// }





// 3
// https://www.codechef.com/problems/MAXDIFF

// #include<bits/stdc++.h>
// #define fer(i,a,b) for(re i = a; i<b; ++i)
// #define re register int
// #define pb push_back
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
//     int t; cin>>t;
//     while(t--)
//     {
//         int n,k; cin>>n>>k; vector<int> arr(n);
//         fer(i,0,n)
//             cin>>arr[i];
//         sort(arr.begin(),arr.end());
//         int p = k;
//         if( p>n/2) p = n-p;
//         int sum1=0,sum2=0;
//         for (int i = 0; i < n; i++)
//         {
//             if( (i+1)<=p) {
//                 sum1+=arr[i];
//             }
//             else {
//                 sum2+=arr[i];
//             }
//         }
//         cout<<abs(sum2-sum1)<<endl;
//     }
//     return 0;
// }






// 4
// https://www.codechef.com/problems/CHEFST

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
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r", stdin);
//         freopen("output.txt","w", stdout);
//     #endif
//     cin.tie(NULL);
//     cout.tie(0);
//     int t; cin>>t;
//     while(t--)
//     {
//         ll n1,n2,m;
//         cin>>n1>>n2>>m;
//         ll minn = (m*(m+1))/2;
//         if( n1>=minn && n2>=minn) {
//             n1 = n1-minn;
//             n2 = n2-minn;
//             cout<<(n1+n2)<<endl;
//             continue;
//         }
//         else {
//             ll mini = min(n1,n2);
//             n1 = n1-mini;
//             n2 = n2-mini;
//             cout<<(n1+n2)<<endl;
//         }
//         // for (ll i = m; i>=1 ; i--)
//         // {
//         //     if(n1>=i && n2>=i) {
//         //         n1=n1-i,
//         //         n2=n2-i;
//         //     }
//         // }
//         // cout<<(abs(n1+n2))<<endl;
//     }
//     return 0;
// }






// 5
// https://www.codechef.com/problems/CLETAB

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
// bool search( int key ,vi&occupied)
// {
//     for (int i = 0; i < occupied.size(); i++)
//         if(key==occupied[i])
//             return true;
//     return false;
// }
// int magic(vi&customers, vi&occupied, int m, int ind) {
//     // customers[ind] baithana hai
//     // occupied mai i se
//     // check karenge uska last placement
//     int farthest = ind;
//     int res = -1;
//     for(int i = 0; i<occupied.size(); i++)
//     {
//         int j = ind+1;
//         for ( j = ind+1; j < m; j++)
//         {
//             if(occupied[i]==customers[j]) {
//                 if(j>farthest){
//                     res = i;
//                     farthest = j;
//                 }
//                 break;
//             }
//         }
//         if(j==m) return i;
//     }
//     return res==-1?0:res;
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r", stdin);
//         freopen("output.txt","w", stdout);
//     #endif
//     cin.tie(NULL);
//     cout.tie(0);
//     int t; cin>>t;
//     while(t--)
//     {
//         int n,m; cin>>n>>m; vector<int> customers(m);        
//         fer(i,0,m) {
//             cin>>(customers[i]);
//         }
//         vi occupied;
//         int curr=0, exclude=0;
//         for(int i=0; i<m; i++) {
//             if(search(customers[i], occupied)) exclude++;
//             else if( curr<n ) {
//                 occupied.pb(customers[i]);
//                 curr++;
//             }
//             else {
//                 int j = magic(customers,occupied,m,i);
//                 occupied[j] = customers[i];
//             }
//         }
//         cout<<(m-exclude)<<endl;
//     }
//     return 0;
// }





// 6
// https://www.codechef.com/problems/TADELIVE

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
// bool cmp (pi&a,pi&b){
//     if(a.first!=b.first) 
//         return a.first>b.first;
//     return a.second<b.second;
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r", stdin);
//         freopen("output.txt","w", stdout);
//     #endif
//     cin.tie(NULL);
//     cout.tie(0);
//     // int t; cin>>t;
//     // while(t--)
//     // {
//         int n,x,y; cin>>n>>x>>y;
//         vector<int> arra(n);
//         fer(i,0,n) cin>>(arra[i]);
//         vi arrb(n);
//         fer(i,0,n) cin>>(arrb[i]);
//
//         vector<pi> diff(n);
//         for(int i = 0; i<n; i++)
//             diff[i] = {abs(arra[i]-arrb[i]),i};
//         sort(diff.begin(), diff.end(),cmp);
//
//         int a=0,b=0;
//         int tip=0;
//         for( auto iter: diff)
//         {
//             int dif = iter.first;
//             int ind = iter.second;
//             if(arra[ind]>arrb[ind])
//             {
//                 if(a+1<=x){
//                     a++;
//                     tip += arra[ind];
//                 }
//                 else {
//                     b++;
//                     tip += arrb[ind];
//                 }
//             }
//             else {
//                 if(b+1<=y){
//                     b++;
//                     tip += arrb[ind];
//                 }
//                 else{
//                     a++;
//                     tip += arra[ind];
//                 }
//             }
//         }
//         cout<<tip<<endl;        
//     // }
//     return 0;
// }





// 7
// https://www.codechef.com/problems/MANYCHEF

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
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r", stdin);
//         freopen("output.txt","w", stdout);
//     #endif
//     cin.tie(NULL);
//     cout.tie(0);
//     int t; cin>>t;
//     while(t--)
//     {
//         string s; cin>>s;
//         int n = s.size();
//         for (int i = 0; i < n-3; i++)
//         {
//             // string subb = s.substr(i,4);
//             if( (s[i]=='?' || s[i]=='C') && (s[i+1]=='?' || s[i+1]=='H') &&
//                 (s[i+2]=='?' || s[i+2]=='E') && (s[i+3]=='?' || s[i+3]=='F') )
//             {
//                 s[i] = 'C'; s[i+1] = 'H'; s[i+2] = 'E'; s[i+3] = 'F';
//                 i = i+3;
//             }
//         }
//         for (int i = 0; i < n; i++)
//             if(s[i]=='?')
//                 s[i] = 'A';
//         cout<<s<<endl;        
//     }
//     return 0;
// }





// 8
// https://www.codechef.com/problems/CHEFTMA

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
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r", stdin);
//         freopen("output.txt","w", stdout);
//     #endif
//     cin.tie(NULL);
//     cout.tie(0);
//     int t; cin>>t;
//     while(t--)
//     {
//         int n,k,m; cin>>n>>k>>m;
//         vi task(n); fer(i,0,n) cin>>(task[i]);
//         vi done(n); fer(i,0,n) cin>>(done[i]);
//         vi white(k); fer(i,0,k) cin>>(white[i]);
//         vi black(m); fer(i,0,m) cin>>(black[i]);
//         int count=0;
//         vi buttons;
//         vi diff;
//         for(int i =0 ; i<n;i++) {
//             diff.pb((task[i]-done[i]));
//         }
//         for(int i =0; i<k; i++){
//             buttons.pb(white[i]);
//         }
//         for(int i =0; i<m; i++){
//             buttons.pb(black[i]);
//         }
//         sort(diff.begin(),diff.end(),greater<int>());
//         sort(buttons.begin(),buttons.end(),greater<int>());
//         int len = k+m;
//         ll inc = 0;
//         int j = 0;
//         for(int i = 0; i<n; i++)
//         {
//             if(j<len) {
//                 while(true) {
//                     if(diff[i] >= buttons[j]) {
//                         diff[i] -= buttons[j];
//                         inc += diff[i];
//                         j++;
//                         break;
//                     }
//                     else j++;
//                 }
//             }
//             else {
//                 inc += diff[i];
//             }
//         }    
//         cout<<inc<<endl;
//     }
//     return 0;
// }





// 9
// https://www.codechef.com/problems/STICKS

// #include<bits/stdc++.h>
// #define fer(i,a,b) for(re i = a; i<b; ++i)
// #define re register int
// #define pb push_back
// #define ll long long
// using namespace std;
// typedef vector<int> vi;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r", stdin);
//         freopen("output.txt","w", stdout);
//     #endif
//     cin.tie(NULL);
//     cout.tie(0);
//     int t; cin>>t;
//     while(t--)
//     {
//         int n; cin>>n; vector<int> arr(n);
//         fer(i,0,n)
//             cin>>(arr[i]);
//         vi dup;
//         sort(arr.begin(),arr.end(),greater<int>());
//         int curr = arr[0], cnt = 1;
//         for (int i = 1; i < n; i++)
//         {
//             if(arr[i]==curr) {
//                 cnt++;
//                 if(cnt==2) dup.pb(arr[i]);
//                 if(cnt==4) dup.pb(arr[i]);
//                 if(dup.size()==2) break;
//             }
//             else {
//                 cnt = 1;
//                 curr = arr[i];
//             }
//         }
//         if(dup.size()<2) {
//             cout<<-1<<endl;
//             continue;
//         }
//         ll ans = dup[0] * dup[1];
//         cout<<ans<<endl;
//     }
//     return 0;
// }




