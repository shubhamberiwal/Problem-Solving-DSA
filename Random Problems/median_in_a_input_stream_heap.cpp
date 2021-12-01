
#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>, greater<int>>min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int maxs = max_heap.size();
        int minx = min_heap.size();
        int max_top, min_top;
        if(maxs == 0) max_top = INT_MAX;
        else max_top = max_heap.top(); // sab isse chota
        if(minx == 0) min_top = INT_MIN;
        else min_top = min_heap.top(); // sab isse bada
        int diff = maxs-minx;
        if(num<max_top) {
            if(diff==0 || diff==-1){
                max_heap.push(num);
            }
            else {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
            max_top = max_heap.top();
        }
        else // nums > max_top. Ab jayega yeh min_heap mai
        {
            if(diff==0 || diff==1) {
                // max_top
                min_heap.push(num);
            }
            else {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
            min_top = min_heap.top();
        }
        if(min_top<max_top && min_top!=INT_MIN && max_top!=INT_MAX) {
            // int temp1 = min_top;
            max_heap.pop(); min_heap.pop();
            max_heap.push(min_top); min_heap.push(max_top);
        }
    }
    
    double findMedian() {
        int maxs = max_heap.size();
        int mins = min_heap.size();
        int tot = maxs+mins;
        if(tot%2==0){
            return ((max_heap.top()+min_heap.top())/2.0);
        }
        if(maxs>mins){
            return max_heap.top();
        }
        else if(mins>maxs)
            return min_heap.top();
        // else return NULL;
        return 00.00;
    }
};


int main()
{
    //int n; cin>>n;
    MedianFinder obj;
    obj.addNum(12);
    cout<<obj.findMedian()<<endl;
    obj.addNum(10);
    cout<<obj.findMedian()<<endl;
    obj.addNum(13);
    cout<<obj.findMedian()<<endl;
    obj.addNum(11);
    cout<<obj.findMedian()<<endl;
    obj.addNum(5);
    cout<<obj.findMedian()<<endl;
    obj.addNum(15);
    cout<<obj.findMedian()<<endl;
    obj.addNum(1);
    cout<<obj.findMedian()<<endl;
    obj.addNum(11);
    cout<<obj.findMedian()<<endl;
    
    return 0;
}


