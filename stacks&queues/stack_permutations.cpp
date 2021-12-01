







#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

int stack_permutations(vi&arr, vi&nums) {
    stack<int> s;
    queue<int> q;
    int n = arr.size();
    int ind = 0;
    for(int i=0; i<n; i++) {
        if(arr[i]==nums[ind]) {
            ind++;
            while ( s.size()!=0 && s.top()==nums[ind] ) {
                s.pop();ind++;
            }
        }
        s.push(arr[i]);
    }
    if(s.size()!=0) {
        cout<<"Permutation not possible"<<endl;
    }
    else cout<<"Possible"<<endl;

}

int main()
{
    //int n; cin>>n;
    
    
    return 0;
}










