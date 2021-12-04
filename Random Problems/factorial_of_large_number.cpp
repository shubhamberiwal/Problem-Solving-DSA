// #include<bits/stdc++.h>
// #define pb push_back
// #define ll long long
// #define mod 1000000007
// using namespace std;
// typedef vector<int> vi;

// int main()
// {
//     int n = 1000000;    
//     vector<int> ans(n);
//     ans[n-1] = 1;
//     int numberofdigits = 1;
//     int siz = 10;

//     for(int i=2; i<=siz; i++) {
//         ll carry = 0;
//         int j;
//         for( j=n-1; j>n-1-numberofdigits; j--) {
//             ll a = (ans[j]*i)+carry;
//             ans[j] = a%10;
//             carry = a/10;
//         }
//         while(carry!=0) {
//             ll a = carry%10;
//             ans[j] = a;
//             numberofdigits++;
//             carry = carry/10;
//             j--;
//         }
//     }
//     for(int i=n-numberofdigits; i<n; i++) {
//         cout<<ans[i];
//     }
//     return 0;
// }



