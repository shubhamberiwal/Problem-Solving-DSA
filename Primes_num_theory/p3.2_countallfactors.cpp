
#include<bits/stdc++.h>
using namespace std;

// remember one thing that 
// Factors = (1+a1) * (1+a2) * (1+a3) * … (1+an)
// where a1, a2, ... are the powers of every unique prime factor of a number

// prime factors of 12 are 2,2,3 or 2^2 and 3^1
// their total factors are 1,2,3,4,6,12, i.e, 6 factors
// count of factors of 2 is 2 and for 3 is 1
// using formula given above (2+1)*(1+1) = 6 factors

// this is exactly what has been done here
// first calculate prime factorization using sieve algorithm
// and then use the formula to find the total number of factors
// rest you can analyse

// also to mention there is another slightly simple way to calculate
// the number of factors and that is just using sieve algo
// starting from 2 just increase the count

const int N = 1e6+1;
int factor[N] = { 0 };

void generateprimefactors(){
    factor[1] = 1;
    for (int i = 2; i < N; i++)
        factor[i] = i;

    for (int i = 4; i < N; i+=2)
        factor[i] = 2;        
    for (int i = 3; i*i < N; i++)
    {
        if(factor[i]==i)
            for (int j = i*i; j < N; j+=i){
                if(factor[j] == j)
                    factor[j] = i;
            }
    }
}
int calculateNoOfFactors(int n){
    if(n==1) return 1;
    int ans = 1;
    int count = 1;
    int dup = factor[n];
    int j = n/factor[n];
    while(j!=1){
        if(factor[j]==dup)
            count+=1;
        else{
            dup = factor[j];
            ans = ans*(count+1);
            count=1;
        }
        j = j/factor[j];
    }
    ans = ans * (count+1);
    return ans;
}

int main(){
    generateprimefactors();
    int a[] = {12, 49, 2983, 22};
    int sz = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < sz; i++){
        cout<<calculateNoOfFactors(a[i])<<" ";
    }
    return 0;
}

