
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

struct matrix{
    int mat[2][2];
};
matrix mul(matrix A, matrix B){
    matrix C;
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 2; col++)
        {
            int here = 0;
            for (int i = 0; i < 2; i++){
                here += A.mat[row][i]*B.mat[i][col];
            }
            C.mat[row][col] = here;            
        }
    }
    return C;
}
matrix identity(){
    matrix A;
    A.mat[0][0] = 1, A.mat[1][1] = 1;
    A.mat[0][1] = 0, A.mat[1][0] = 0;
    return A;
}
// any matrix when multiplied with identity matrix returns same matrix
// eg: A * (A^0) = A or (A^3) * (A^0) = (A^3) [here (A^0) means identity matrix]

// power of a matrix
matrix power(matrix A, int n){
    if(n==0){
        return identity();
    }
    matrix X = power( A, (n/2));
    if(n&1==1){
        return mul(mul(X,X),A);
    }
    else return mul(X,X);
}

//
int get_nth_fibonacci(int n){
    matrix fib;
    fib.mat[0][0] = 1, fib.mat[0][1] = 1;
    fib.mat[1][0] = 1, fib.mat[1][1] = 0;
    // now as fo = 1 and f1 = 1 and fib.mat^n * {fo, f1} = {fn+1, fn}
    // we can just return the sum of lower row of fib.mat^n matrix
    matrix A = power(fib, n);
    return A.mat[1][0]+A.mat[1][1];
}


int main()
{
    //int n; cin>>n;
    

    
    return 0;
}

