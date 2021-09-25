

#include<bits/stdc++.h>
using namespace std;


// Problem 1 - given some queries and each query has a number k 
// output q lines and each line having that particular k(th) prime number
// k can be as big as 5*10^6, i.e, you can be asked to return the 5000000th prime number
const int N = 1e8;
bool sieve[N+1];
vector<int> ds;
void createsieve(){
    for (int i = 2; i*i <= N ; i++)
        sieve[i] = true;

    for (int i = 2; i*i < N; i++){
        if(sieve[i] == true){
            for (int j = i*i; j<=N ; j+=i)
                sieve[j] = false;
        }
    }

    // k limit can be 5*10^6
    int limit = 5*1000000;
    int cnt=0,size=1; // cnt contains the current count of prime numbers in the array. We need till 5*10^6th prime number
    for (int i = 2; ; i++)
    {
        if(sieve[i] == true) cnt++;
        if(cnt==limit) {size = i; break;}
    }
    cout<<size<<endl;
    // we will get the limit as 86028121
    int n=86028121;
    for (int i = 2; i <= n; i++)
    {
        if(sieve[i]==true)
            ds.push_back(i);
    }
    // ds has 1 to 5000000 th prime numbers call them as ds[k-1] as 0 based indexing
}


// Problem 2 - n will be prime always and in range is 1 to 1o^6
// multiple queries q each having an integer input 'n', tell how many numbers in the range 1 to 10^6 have min prime factor as the number
// eg : n=3 then print the total number of numbers having 3 as their min. prime factor
const int M = 1000000;
int sieve[M+1];
void createSieveMinPrimeFactor(){
    for (int i = 2; i <= N; i++)
        sieve[i] = 1;
    
    for (int i = 2; i*i <= N; i++){
        if(sieve[i]==1)
        {
            for (int j = i*i; j <= N; j+=i)
            {
                if( sieve[j] != 0 ){
                    sieve[j] = 0;
                    sieve[i]++;
                }
            }
        }
    }
    // now sieve[n] will have the required count of numbers in given range that have n as min. prime factor
}


/* // IMPORTANT ** INFO: maximum array size in c++ for int datatype is 10^6 
// and for bool datatype is 10^7 if declared inside main or any other function
// but for more size you have to declare it globally
// globally constraints are int: 10^7 and bool: 10^8

// Sample sieve creation
int N = 1000000;
bool sieve[1000001];
void createsieve(){
    for (int i = 2; i <= N; i++)
    {
        sieve[i] = true;
    }
    for (int i = 2; i <= N; i++)
    {
        if( sieve[i] )
            for (int j = i+i; j <=N; j = j+i)
            {
                sieve[j] = false;
            }
    }
}
// optimized sieve
// O(n*log(log n))
void createoptimalsieve(){
    
    for (int i = 2; i <= N; i++)
        sieve[i] = true;

    for (int i = 2; i*i <= N; i++)
    {
        if(sieve[i]){
            for (int j = i*i; j <= N; j+=i)
                sieve[j] = false;
        }
    }   
}
*/

int main()
{
    // createoptimalsieve(); // O(n*log(log n))
    int t; cin>>t;
    while(t--){ // O(t)
        int n; cin>>n;
        if( sieve[n] == true)
            cout<<"Yes";
        else cout<<"No";
    }
    
    return 0;
}

