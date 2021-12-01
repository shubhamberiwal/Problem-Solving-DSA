#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;
#define maxn 1000

class que {
    int n;
    int arr[maxn];
    int front=0,rear = 0;
    int cnt = 0;
    que(int x) : n(x) {}

    void push(int x) {
        if( cnt!=n && rear!=n ) {
            arr[rear] = x;
            rear = (rear+1)%n;
            cnt++;
        }
    }
    bool pop() {
        if( cnt!=0 ) {
            cnt--;
            int cur = front;
            front = (front+1)%n;
            return arr[cur];
        }
        return -1;
    }
    int top() {
        if( cnt!=0 )
            return arr[front];
        return -1;
    }
    
};


int main()
{
    //int n; cin>>n;
    
    
    return 0;
}



