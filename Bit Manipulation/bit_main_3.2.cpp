

#include<bits/stdc++.h>
using namespace std;

// 5 - function to find where there is array of length n
// having numbers from 1 to n but 1 number is missing
// and instead of that place another single number is repeated
void repeat1andmissing1(int arr[],int n)
{
    int a[] = {2,3,4,5,3};
    int x=0,y=0,xorsum=0;
    for (int i = 0; i < n; i++){
        xorsum ^= arr[i];
    }
    for (int i = 1; i <= n; i++){
        xorsum ^= i;
    }
    // we will get (miss ^ repeat) in xorsum now
    
    // now get the right most set bit
    int setbit = (xorsum & ~((xorsum-1)));

    for (int i = 0; i < n; i++){
        if( arr[i] & setbit )
            x ^= arr[i];
        else y ^=arr[i];
    }
    for (int i = 1; i <= n; i++){
        if( i & setbit )
            x ^= i;
        else y ^= i;
    }
    int flag =0;
    for (int i = 0; i<n ; ++i){
        if( arr[i]==x )
            flag=1;
    }
    cout<<"The repeating number is: ";
    if(flag)
        cout<<x<< " and the missing number is: "<<y<<endl;
    else cout<<y<< " and the missing number is: "<<x<<endl;
}


//6 - Implement a set data structure using bit masking
// the number of elements in the ds can be upto 60 or (0<=x<=60)
// expected tc: O(1) for insertion, deletion. Also sc: O(1);
// set ds use (log n) tc. solve this using bitmasking
void bitmasking(int n){
    long long datastructure=0;
    // if we have to add the element
    datastructure = (datastructure | (1<<n));
    // to remove the element from the datastructure
    datastructure = datastructure ^ (1<<n);
    // if user wants to remove an element that doesn't 
    // exist then above statement doesn't work use below one. this is better method
    datastructure = (datastructure & ~(1<<n));
    // print the elements of datastructure in ascending order
    for (int i = 0; i <= 60; i++)
    {
        if( datastructure & (1<<i) )
            cout<<i<<" ";
        cout<<endl;
    }
}


int main()
{
    // int n; cin>>n;
    // int arr[8] = {1,2,3,4,5,3,2,1};
    // find2unique(arr, 8);
    // int arr2[10] = {1,1,1,9,2,2,3,3,2,3};
    // finduniquewhenrepeatis3second(arr2,10);
    // int arr3[6] = {1,2,3,3,4,5};
     int arr4[7] = { 1, 3, 4, 5, 5, 6, 2 };
    repeat1andmissing1(arr4,7);
    return 0;
}

