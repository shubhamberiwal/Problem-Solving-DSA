
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
    matrix(int a, char c)  {
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
matrix multiplication_matrix(matrix A, matrix B, int dim) {
    matrix C(dim);
    for (int row = 0; row < dim; row++) {
        for (int col = 0; col < dim; col++) {
            for (int i = 0; i < dim; i++) {
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
    // naive method, takes O(power) time
    // for (int i = 0; i < power; i++)
    // {
    //     res = multiplication_matrix(res,A,dim);
    // }
    
    return res;
}

// recursive way
matrix recur_multiply(matrix A, int power, int dim){
    if(power==0) {
        matrix B(dim, 'I');
        return B;
    }
    matrix X = recur_multiply(A, power/2, dim);
    if(power&1){
        return multiplication_matrix(multiplication_matrix(X,X,dim),A,dim);
    }
    else return multiplication_matrix(X,X,dim);
}

int main()
{
    //int n; cin>>n;
    int dimen; cin>>dimen;
    int power; cin>>power;
    matrix A(dimen);
    for (int i = 0; i < dimen; i++) {
        for (int j = 0; j < dimen; j++)
            cin>>A.mat[i][j];
    }
    // input done

    matrix B = matrix_expo(A, power, dimen);
    // print the answer that is A^power stored in matrix B
    for(auto x: B.mat){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}

