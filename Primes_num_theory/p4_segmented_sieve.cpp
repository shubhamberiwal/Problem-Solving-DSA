

#include<bits/stdc++.h>
using namespace std;

// problem states give q test cases or queries each test case has an l, r
// print all prime numbers in the range l, r
// l, r can be <=10^12 but r-l will always be <=10^6

// use segmented sieve concept to do the problem. Enjoy!!


// normal function to create a standart sieve black box or array
// of size 1e6 (shameless reminder: bool array can be upto 10^8 in global scope)
const int N = 1e6;
bool sieve[N+1];
void create_sieve(){
    for (int i = 2; i <= N; i++){
        sieve[i] = true;
    }
    
    for (int i = 2; i*i <= N; i++){
        if(sieve[i]==true){
            for (int j = i*i; j <= N; j++){
                sieve[j] = false;
            }
        }
    }
}

// store all prime numbers that occur till n in ds and return
vector<int> generate_primes(int n){
    vector<int> ds;
    for (int i = 2; i <= n; i++){
        if(sieve[i] == true)
            ds.push_back(i);
    }
    return ds;
}

int main(){
    // O(n*log(log n)) or O(n) of O(10^6)
    create_sieve();
    // O(q) as q queries or test cases here q is 10
    // so O(10)
    int q; cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;

        // step 1: generate all primes till sqrt(r)
        // at max r can be 10^12 so here TC: O(sqrt(r)) or O(10^6)
        vector<int> primes = generate_primes(sqrt(r));

        // step 2: create dummy array of size r-l+1 and mark all as 1
        // O(10^6)
        int dummy[r-l+1];
        for (int i = 0; i < r-l+1; i++){
            dummy[i] = 1;
        }

        // step 3: for all primes numbers, marks its multiple as false
        // around 10^4 primes are there and we are not running a linear loop inside
        // take tc around O(10^6) again for this step also
        for(auto pr: primes){
            int firstmultiple = (l/pr)*pr;
            if( firstmultiple<l) firstmultiple+=pr;

            for (int j = max(firstmultiple, pr*pr); j  <= r; j+=pr)            {
                dummy[j-l] = 0;
            }
            
        }
        
        // step 4: get all the primes in that range
        // already established that range in as large as 10^6
        // tc: O(10^6)
        for (int i = l; i <= r; i++)
        {
            if(dummy[i-l] == 1)
                cout<< i << " ";
        }
        cout<<endl;
    }
    // total time complexity is: O( 10^6 + 10*(10^6 + 10^6 + 10^6 + 10^6))
}

