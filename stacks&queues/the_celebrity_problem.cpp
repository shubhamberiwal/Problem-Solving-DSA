#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

// vector<vi> mat = { { 0, 0, 1, 0 },
//                       { 0, 0, 1, 0 },
//                       { 0, 0, 0, 0 },
//                       { 0, 0, 1, 0 } };


int celebrity(int n, vector<vi>&mat) {

    int one = n-1,two;
    for(int i=n-2; i>=0; i--) {
        two = i;
        if( mat[one][two] ) {
            one = two;
        }
    }
    int flag = 0;
    for(int i=0; i<mat.size(); i++ ) {
        if( mat[one][i]!=0 ) {
            flag = 1;
        }
        if( i!=one && mat[i][one]!=1 ) {
            flag = 1;
        }
    }
    if(flag) return -1;
    return one;
}

int main()
{
    int n=4;
    vector<vi> matrix(n,vi(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>matrix[i][j];
        }
    }
    cout<<celebrity(n,matrix);
    
    return 0;
}



// bool knows(int a, int b) { 
//     return mat[a][b];
// }
// int findceleb(int n) {
//     if(n==0) return -1;
//     int id = findceleb(n-1);
//     if(id==-1) 
//         return n-1;
//     else if(knows(id,n-1)) {
//         return n-1;
//     }
//     else if(knows(n-1,id)) {
//         return id;
//     }
//     return -1;
// }

