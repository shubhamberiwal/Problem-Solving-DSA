

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

#define maxn 1000

class stk {
    int n ;
    int arr[maxn];
    int top = -1;
    stk(int x) : n(x) {}
    bool push( int x) {
        if(top!=n) { 
            arr[++top] = x;
            return true;
        }
        cout<<"Overflow"<<endl;
        return false;
    }
    int pop() {
        if(top!=-1) {
            top--;
            return arr[top+1];
        }
        cout<<"Underflow"<<endl;
        return 0;
    }
    int top() {
        if(top!=-1) return arr[top];
        cout<<"Underflow"<<endl;
        return 0;
    }
    bool empty() {
        if(top==-1) return true;
        else return false;
    }
};

int main()
{
    //int n; cin>>n;

    
    
    return 0;
}



