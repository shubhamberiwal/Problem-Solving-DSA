

#include<bits/stdc++.h>
using namespace std;

// 1 - find xor of numbers till n in O(1) time
// numbers in array are form 1 to n
// think and try to find the pattern in the xor of numbers till n
int efficientxor(int n)
{
    if(n%4==0)
        return n;
    else if (n%4==1)
        return 1;
    else if (n%4==2)
        return n+1;
    else // if (n%4==3)
        return 0;
}

// 2 - find the xor of numbers in the range (L to R)
// solution: (xor till r) ^ (xor till l-1)
int xorofrange(int l, int r){
    int left , right;
    if((l-1)%4==0) left = l-1;
    else if((l-1)%4==1) left = 1;
    else if( (l-1)%4==2) left = (l-1)+1;
    else left = 0;
    if( r%4==0) right = r;
    else if( r%4==1) right = 1;
    else if( r%4==2) right = r+1;
    else right = 0;
    return right^left;
}

// 3 - this function prints the 2 unique numbers in the array while
// other numbers are present exactly twice
void find2unique(int arr[],int n){
    int xorsum=0;
    for (int i = 0; i < n; i++){
        xorsum = (xorsum ^ arr[i]);
    }
    if(xorsum == 0 ){
        cout<<"no duplicate"<<endl;
        return;
    }
    else{
        int j = 0, temp, first = 0;
        while(1){
            temp = (xorsum & 1<<j);
            j++;
            if(temp !=0 ){
                for (int i = 0; i < n; i++)
                {
                    if( (arr[i] & temp) != 0){
                        first = first ^ arr[i];
                    }
                }
                break;
            }
        }
        int second = first ^ xorsum;
        cout<< "Non Repeating numbers are: "<<first<<", "<< second;
    }
}

// 4 - function to find a unique no. where all other numbers is present thrice
void finduniquewhenrepeatis3(int arr[], int n)
{
    int xorsum = 0;
    int a[8]={0};
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < n; j++){
            if(arr[j] & (1<<i)){
                a[i]++;
            }
        }
    }
    int setbit;
    for (int i = 0; i < 8; i++){
        if(a[i]%3!=0){
            setbit = 1<<i;
        }
    }
    // cout<<setbit;
    int uniquenumber;
    for (int i = 0; i < n; i++){
        if( arr[i] & setbit ){
            uniquenumber = uniquenumber ^ arr[i];
        }
    }
    cout<<uniquenumber<<endl;
}

// 4 (Optimal) - one another way to do the above function task is:
// this one is more efficient way
void finduniquewhenrepeatis3second(int arr[], int n){
    int result = 0;    
    for (int i = 0; i < 64; i++){
        int sum = 0;
        for (int j = 0; j < n; j++){
            if(arr[j] & (1<<i)) // getbit functionality
                sum++;
        }
        if(sum%3!=0){
            result = ( result | (1<<i) );  //setbit functionality
        }
    }
    cout << result;
}

int main()
{
    // int n; cin>>n;
    // int arr[8] = {1,2,3,4,5,3,2,1};
    // find2unique(arr, 8);
    int arr2[10] = {1,1,1,9,2,2,3,3,2,3};
    finduniquewhenrepeatis3second(arr2,10);
    // int arr3[6] = {1,2,3,3,4,5};
    return 0;
}