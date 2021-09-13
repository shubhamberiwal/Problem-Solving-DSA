



#include<bits/stdc++.h>
using namespace std;

void countsort(int *arr, int n)
{
    int maxi = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxi = max(arr[i],maxi);
    }
    // int *count = new count [maxi+1];
    int count[maxi+1] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 1; i < maxi; i++)
    {
        count[i] += count[i-1];
    }
    int output[n];
    for (int i = n-1; i>=0 ; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
    
    
    
    
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    countsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;

    return 0;
}