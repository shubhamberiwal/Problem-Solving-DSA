

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;



// 12 - given an array "arr" and a number "n". Return all the
// indexes in the array where the number "n" is found
vector<int> alloccurence(int arr[], int target, int index, int n, int count){
    if(index==n){
        vector<int> result(count);
        return result;
    }
    if(arr[index] == target)
        count++;
    vector<int> result = alloccurence(arr, target, index+1, n, count);
    if( arr[index] == target ){
        count--;
        result[count] = index;
    }
    return result;
}

int main()
{
    //int n; cin>>n;
    int arr[] = {1,2,3,4,5,3,4,3,5};
    vector<int> result = alloccurence(arr, 7, 0, 9, 0);
    for(int i = 0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}


// 11 - given an array and a number n return the last index of that number
int lastoccurence(int arr[], int target, int index, int n){
    if(index==n)
        return -1;
    int last = lastoccurence(arr, target, index+1, n);
    if(target==arr[index] && last==-1){
        last = index;
    }
    return last;
}

// 10 - given an array and a number n
// return the first occurence of that number n in the given array
// if not present in array return -1
int firstoccurence(int arr[], int target, int index, int n){
    
    if( index==n )
        return -1;
    if( target==arr[index] )
        return index;
    else
        return firstoccurence(arr, target, index+1, n);
}
// 10.2 - lengthy approach. Avoid this.
int first(int arr[], int n, int target, int index){

    int mind = first(arr, n, target, index+1);
    if( target == arr[index] )
        return index;
    else return mind;
}


// 9.1 - print maximum of the array
// sample initial maxinarray call: ({23,17,45,22,49}, 5, 0, 0)
void maxinarray(int arr[], int n, int i, int maxi) {
    if(i==n){
        cout<<maxi<<endl;
        return;
    }
    maxi = max(maxi, arr[i]);
    maxinarray(arr, n, i+1, maxi);
}
// 9.2 - another method to return max
int maxinaarray(int arr[], int n, int index){
    if(index==n-1){
        return arr[index];
    }
    int maxi = maxinaarray(arr, n, index+1);
    return max(maxi, arr[index]);
}

// 8 - print an array using recursion
void printarray(int arr[], int i, int n){
    if(i==n)
        return;
    cout<<arr[i];
    printarray(arr, i+1, n);
}


// 7 - tower of hanoi(TOH)
// high level thinking: expectation that if given toh(3,A,B,C)
// [meaning to put 3 disk from pole A to pole B via pole c]
// for this humko faith chahiye ki agar I do toh(2,A,B,C) then
// [matlab upar ki 2 disk ko A se B mai rakhu via C].
// now, expectation and faith is established and now if i assume faith works then I can write
// the link between exp and faith that is
// for toh(3,A,B,C) = first toh(2,A,C,B) then just 3rd[A,B] then toh(2,C,B,A)

// to sum up the logic: if our toh function knows how to print the instructions
// to move 2 disks [acc. to rules ofc] then can we make toh to print the 
// instructions to move 3 disks
void toh(int n, int tow1, int tow2, int tow3){
    if(n==0){
        return;
    }
    toh( n-1, tow1, tow3, tow2);// will print instructions to move n-1 disks from t1 to t3 using t2
    cout<< n << "(" << tow1 << " -> " << tow2 << ")"<<endl;
    toh( n-1, tow3, tow2, tow1);// will print instructions to move n-1 disks from t3 to t2 using t1
}
// analyse the code yourself by making a complete euler trail of the function
// and one thing to notice is that there is no pre order or post order, all printing of instruction
// takes place at inorder position. Use this and euler trail to analyse the function


// 6 - function to calculate x^n in logarithmic time complexity
int logarithmicpower(int x, int n){
    if(n==0){
        return 1;
    }
    
    int temp = logarithmicpower(x,(n/2));
    int res = temp*temp;
    if (n%2!=0){
        res =  res*x;
    }
    return res;
}

// 5 - print x^n, given x and n
int tothepower(int x, int n){
    if(n==0){
        return 1;
    }
    return x*tothepower(x,n-1);
}

// 4 - print factorial
int factorial(int n){
    if(n<2){
        return 1;
    }
    return n*factorial(n-1);
}

// 3 - given n print first in decreasing order then in increasing order
// eg: n=3 print 3 2 1 1 2 3
void printdecreasingincreasing(int n){
    if(n==0)
        return;
    cout<<n<<endl;
    printdecreasingincreasing(n-1);
    cout<<n<<endl;
}

// 2 - print increasing
// given n=5 print 1 2 3 4 5
void printincreasing(int n){
    if(n==0){
        return;
    }
    printincreasing(n-1);
    cout<<n<<endl;
}

// 1 - print decreasing
// given n=5 print 5 4 3 2 1
void printdecreasing(int n){
    if(n==0)
        return;
    cout<<n<<endl;
    printdecreasing(n-1);
}

