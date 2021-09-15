


// 1 - Co-growing sequences - [1574 D] [*1300]
#include<bits/stdc++.h>
#define fer(i,a,b) for(re i = a; i<b; ++i)
#define re register int
#define sf(x) scanf("%d", &x)
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n; int arr[n];
        fer(i,0,n)
            sf(arr[i]);
        vector<int>nums(n);
        nums[0] = 0;
        int xorsum, temp;
        fer(i,1,n){
            xorsum = nums[i-1] ^ arr[i-1];
            temp = xorsum & arr[i];
            if( temp == xorsum)
                nums[i] = 0;
            else nums[i] = xorsum ^ temp;
        }
        fer(i,0,n)
            cout<< nums[i]<<" ";
        cout<<endl;
    }
    return 0;
}


// 2 - Mikasa [1544 - C] [*1800]
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int m; cin>>m;
        m++;
        int ans=0;
        // n^k>=(m+1)
        for (int i = 31; i >=0 ; i--)
        {
            int k,l;
            k = n>>i ; l = m>>i ;
            // n->1 and m->1 then take k=0
            if( (k&1) == 1 && (l&1) ==1){

            }
            // n->0 and m->1 then take k=1
            else if( (k&1) == 0 && (l&1) == 1){
                ans+=(1<<i);
            }
            // n->1 and m->0 then take k=1 and break that will be answer because n^k resulting will always be greater than m+1
            else if( (k&1) == 1 && (l&1) == 0){
                // ans+=(1<<i);
                break;
            }
            // n->0 and m->0 then take k=0
            else ( (k&1) == 0 && (l&1) == 1);
        }
        cout<<ans<<endl;
    }
    return 0;
}



// 3 - Peter and combination lock (Power set example question)
bool combination(vector<int> nums){
    int n = nums.size();
    int sum=0, flag=0;
    for (int i = 0; i < ((1<<n)-1); i++)
    {
        sum=0;
        for (int j = 0; j < n; j++) // this is while we are assuming this is a 32 bit number
        {
            if( i & (1<<j) )
                sum+=nums[j];
            else sum-=nums[j];
        }
        if(sum%360 == 0){
            flag = 1; break;
        }
    }
    if(flag) return true;
    else return false;
}
// recursion or dfs method or way to solve the same problem
// #include<bits/stdc++.h>
// using namespace std;
// int a[20];
// int n;
// bool dfs(int i,int sum){
//     if(i==n) return sum%360==0;
//     if(dfs(i+1,sum+a[i])) return true;
//     if(dfs(i+1,sum-a[i])) return true;
//     return false;
// }
// int main(){
//     cin>>n;
//     for(int i=0;i<n;i++){
//         scanf("%d",a+i);
//     }
//     bool flag=dfs(0,0);
//     if(flag){
//         printf("YES");
//     }else{
//         printf("NO");
//     }
//     return 0;
// }

