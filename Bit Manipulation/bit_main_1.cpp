

// basic program on bit manipulation
// understanding setbit, clearbit, getbit and update bit

#include<bits/stdc++.h>
using namespace std;
int getbit(int n, int pos)
{
    return ((n & (1<<pos))!=0);
}
int setbit(int n, int pos)
{
    return (n | (1<<pos));
}
int clearbit(int n, int pos)
{
    int mask = ~(1<<pos);
    return ( n & mask);
}
int updatebit(int n, int pos, int value)
{
    // n = clearbit(n, pos);
    // n = setbit()
    int mask = ~(1<<pos);
    n = (n & mask);
    mask = value << pos;
    return (n | mask);
}
int main()
{
    // int n; cin>>n;
    // cout<< getbit(5,2)<<endl;   
    // cout<<setbit(5,1)<<endl;
    // cout<<clearbit(5,2)<<endl;
    // now update bit is nothing but first clear bit and then set bit
    cout<<updatebit(5,1,1)<<endl;
    return 0;
}


