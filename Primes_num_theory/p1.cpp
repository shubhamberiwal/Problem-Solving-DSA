
#include<bits/stdc++.h>
using namespace std;

// Reverse Order

// count the number of factors or check for primes
// now if you use condition sqrt(n) then the time complexity is not O(sqrt(n))
// instead time complexity is O(sqrt(n)*log n). This is because
// calculating sqrt function in c++ takes log n time and it is being done for each iteration
// change condition to i*i<n. This takes O(1) time
void primeusingsqrt(int n) {
    int count=0;
    for (int i = 1; i <= sqrt(n); i++)// change condition to i*i<n
    {
        if( n%i==0 ) {
            count++;
            if( (n/i)!=i)
                count++;
        }
    }
}
// print sum of factors
void sumoffactors(int n) {
    int sum=0;
    for (int i = 1; i*i <= n; i++)
    {
        if(n%i==0){
            sum+=i;
            if( (n/i)!=i)
                sum+=(n/1);
        }
    }
}
// ** IMPORTANT **
// given n you have to find a, b & c where a*b*c = n also a!=b!=c!=1 also n<10^9
void findabc(int n) {
    int a=1,b=1,c=1;
    for (int i = 2; i*i <= n; i++)
    {
        if( n%i == 0) {
            a=i; break;
        }
    }
    int n=n/a;
    for (int i = 2; i*i < n; i++)
    {
        if( n%i==0 ){
            if( i != a ){
                b = min(b, i);
            }
            if( (n/i)!=i ){
                if( (n/i)!=a){
                    b=min(b, n/i);
                }
            }
        }
    }
    c = n/b;
    if( a!=b && b!=c && c!=1){
        printf("yes");
        return;
    }
    else printf("No");
}
// check prime
bool checkprime(int n){
    int cnt=0;
    for (int i = 1; i*i < n; i++)
    {
        if( n%i == 0 ){
            cnt++;
            if( (n/i)!=i ){
                cnt++;
            }
        }
    }
    if(cnt==2) return true;
    return false;
}
// possible for numbers n<=10^6
void sqrtprime(){
    int t;
    cin>>t;
    while(t--) {
        int n; cin>>n;
        if(checkprime(n)) {
            cout<<"Yes";
        }
        else{
            cout<<"No";
        }
    }
}

int main()
{
    int n; cin>>n;
    
    return 0;
}

