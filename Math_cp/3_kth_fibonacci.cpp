
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

// defining matrix
struct matrix {
    vector<vi> mat;
    matrix(int a) {
        mat.assign(a,vi(a,0));
    }
    // for identity matrix, char c as 'I' for identity
    matrix(int a, char c) {
        if(c=='I') {
            mat.assign(a,vi(a,0));
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < a; j++) {
                    if(i==j) mat[i][j] = 1;
                }
            }
        }
    }
};

// Basic multiplication of 2 matrices
matrix multiplication_matrix(matrix A, matrix B, int dim){
    matrix C(dim);
    for (int row = 0; row < dim; row++){
        for (int col = 0; col < dim; col++){
            for (int i = 0; i < dim; i++){
                C.mat[row][col] += (A.mat[row][i] * B.mat[i][col]);
            }
        }
    }
    return C;
}

// iterative way
matrix matrix_expo(matrix A, int power, int dim) {    
    // binary exponentiation method will take O(dim^3 * log (power)) time
    // note that a matrix A multiplied with identity matrix I gives matrix A as it is.
    // This identity property of matrix
    matrix res(dim,'I');
    while( power>0 ) {
        if(power&1) {
            res = multiplication_matrix(res, A, dim);
            power--;
        }
        else {
            power = power>>1;
            A = multiplication_matrix(A,A,dim);// A = A*A
        }
    }   
    return res;
}

int kth_fibonacci(int k) {
    matrix fib(2);
    fib.mat[0][0] = 0, fib.mat[0][1] = 1;
    fib.mat[1][0] = 1, fib.mat[1][1] = 1;
    matrix X = matrix_expo(fib,k-1,2);
    return (X.mat[0][0] + X.mat[1][0]);
}

int main()
{
    cout<<"Enter the k, will return the kth number in fibonacci series\n";
    int k; cin>>k;
    int ans = kth_fibonacci(k);
    cout<<ans<<endl;
    return 0;
}

