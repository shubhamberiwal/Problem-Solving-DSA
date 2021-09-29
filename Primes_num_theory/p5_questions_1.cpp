


// 2 - given an array of integers A1,A2,A3...An
// return the number of pairs Ai and Aj such that
// Ai is a multiple of Aj, and Ai != Aj
// n<=1e5 and 1<=Ai<=1e5 

// So the question really is : Ai%Aj == 0 and Ai != Aj
// tc: O(N log N)
#include<bits/stdc++.h>
#define fer(i,a,b) for(re i = a; i<b; ++i)
#define re register int
#define sf(x) scanf("%d", &x)
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    cin.tie(NULL);
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n; vector<int> arr(n);
        fer(i,0,n)
            sf(arr[i]);
        const int maxn = 1e5+1;
        // counting 
        vector<int> count (maxn,0);
        for (int i = 0; i < n; i++)
            count[arr[i]]++;
        
        // M array will contain at ith index number of multiples of i that aren't equal to i
        // for eg: M[3] will tell you number of multiple of 3 in the array A which are not equal to 3
        vector<int> M(maxn);
        for (int i = 1; i < maxn; i++)
        {
            for (int j = 2*i; j < maxn; j+=i)
                M[i] += count[j];
        }

        long long ans = 0;
        for (int i = 0; i < n; i++){
            ans += M[arr[i]];
        }
        cout<<ans<<endl;
    }

    return 0;
}




// 1 - A prime number is a positive number, which is divisible by exactly two different integers. A digit prime
// is a prime number whose sum of digits is also prime. For example the prime number 41 is a digit prime
// because 4 + 1 = 5 and 5 is a prime number. 17 is not a digit prime because 1 + 7 = 8, and 8 is not
// a prime number. In this problem your job is to find out the number of digit primes within a certain
// range less than 1000000.

//First line of the input file contains a single integer N (0 < N ≤ 500000) that indicates the total number
// of inputs. Each of the next N lines contains two integers t1 and t2 (0 < t1 ≤ t2 < 1000000)

// correct answer but more optimization needed. We need prefix sum array solution along with this method
// Mentioned method is implemented below this.

// not the optimal answer. correct answer is after this method
#include<bits/stdc++.h>
#define fer(i,a,b) for(re i = a; i<b; ++i)
#define re register int
#define sf(x) scanf("%d", &x)
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;
int n = 1e7;
vector<bool> sieve(n+1,true);
void sievealgo(){
    for (int i = 2; i*i <= n; i++){
        if(sieve[i]==true){
            for (int j = i*i; j <= n; j+=i){
                if( sieve[j]==true ) {
                    sieve[j] = false;
                }
            }
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    cin.tie(NULL);
    sievealgo();
    int t; cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        // a to b
        int counter = 0;
        for (int i = a; i <= b; i++)
        {
            int flag = 0;
            int sum = 0;
            //check if i is answer or not
            if( sieve[i] == true ){
                int k = i;
                while(k!=0){
                    int temp = k%10;
                    sum+=temp;
                    k = k/10;
                }
                if(sieve[sum]==false)
                    flag=1;
            }
            else flag=1;
            if(flag)continue;
            counter++;
        }
        cout<<counter<<endl;
    }
    return 0;
}



// 1 - same question as above
// but this is the optimised solution
// here you also take prefix array that contains sum of digits of the index of that array
// that way you save more time and answer is optimised
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+10;
int pf[N];
int arr[N];
void primes(){
   for(int i=1;i<=N;i++){
       arr[i]=1;
   } 
   arr[0]=0,arr[1]=0;
    for(int i=2;i*i<=N;i++){
        if(arr[i]==1){
            for(int j=i*i;j<=N;j+=i){
                arr[j]=0;
            }
        }
    }
    ll sum =0;
    pf[0]=0;
    for(int i=1;i<=N;i++){
        if(arr[i]==1){
            ll temp=i;
            sum=0;
            while(temp>0){
                ll x=temp%10;
                sum+=x;
                temp=temp/10;
                if(arr[sum]==1){
                    pf[i]=1;
                }else{
                    pf[i]=0;
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
        pf[i]+=pf[i-1];
    }
}
int main(){
    int t;
    
    cin>>t;
    primes();
    while(t--){
        int l,r;
        scanf("%d %d",&l,&r);
        int result=pf[r]-pf[l-1];
        printf("%d\n",result);
    }
    return 0;
}