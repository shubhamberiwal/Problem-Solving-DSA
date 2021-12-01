

// https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

struct petrolpumps {
    int petrol, distance;
};

int printtour(petrolpumps arr[], int n) {
    int start ;
    
    // figuering out the start pos
    for(int i=0; i<n; i++ ) {
        if(arr[i].petrol >= arr[i].distance) {
            start = i;
            break;
        }
    }
    // store excess petrol
    int cur_petrol = 0;
    int i=0;

    for(int i=start; i<n; ) {
        cur_petrol += (arr[i].petrol - arr[i].distance);
        if(cur_petrol<0) {
            i++;
            for(; i<n; i++) {
                if(arr[i].petrol>=arr[i].distance) {
                    start = i;
                    cur_petrol = 0;
                    break;
                }
            }
        }
        else {
            i++;
        }
    }
    if(cur_petrol<0) return -1;
    for(int j=0; j<start; j++) {
        cur_petrol += (arr[j].petrol-arr[j].distance);
        if(cur_petrol<0) return -1;
    }
    return start;
}

int main()
{
    //int n; cin>>n;
    
    
    return 0;
}




