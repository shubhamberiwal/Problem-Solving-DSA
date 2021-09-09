

// program to check if a number is power of 2
#include<bits/stdc++.h>
using namespace std;
// lskd
// now in binary rep. every number which is a power of 2
// must be having only 1 bit as set. eg: 8 is 1000, 4 is 0100, 2 is 0010 and so on
// also if we see n-1 of any number then:
// the rightmost set bit in n is flipped in n-1 and corespondinly all the bits are flipped from there on in n-1
// (n&n-1) has same bits as n except the rightmost set bit
// so a number to be power of 2, when &ed with n-1 should give all zeroes
// in conclusion n should have only 1 set bit and n-1 will have all set bits after that position

bool ispowerof2(int n)
{
    return  (n && !(n & n-1));
}
int countnumberof1s(int n)
{
    int count=0;
    while(n)
    {
        count++;
        n = n & n-1;
    }
    return count;
}
bool ispowerof4(int n)
{
    // check if only 1 bit is set in n
    if( (n&n-1)==0 )
    {
        int count = 0;
        int j=0;
        // counting the number of 0 following that 1 
        // and if no. of 0 is even it's power of 4 else only a power of 2
        while(1)
        {
            if (((1<<j) & n)==0)
                count ++;
            else break;
            j++;
        }
        return count%2==0?true:false;
    }
}
void subsets(int arr[], int n)
{
    for (int i = 0; i < (1<<n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if( i & (1<<j))
            {
                cout<<arr[j]<< " ";
            }
        } cout<<endl;
        
    }
}
void leftrotate8bitnumber(int n, int d)
{
    int k = ((n << d)|(n >> (8 - d)));
    cout<<k<<endl;
}
void rightrotate8bitnumber(int n, int d)
{
    int k = (( n>>d) | (n << (8-d)));
    cout<<k<<endl;
}
// to multiply a number by seven first left shift 
// the no. by 3 to multiply it by 8 then subtract the number. Simple!
void multiplybyseven(long n)
{
    int k = ((n<<3) - n);
}
void toggle(int num,int pos)
{
    num ^= (1 << (pos -1));
    cout<<num;
}
// anding the number and it's 2's complement
int lowest_set_bit(int num)
{
    int ret = num & (-num);
    return ret;
}
int main()
{
    // int n; cin>>n;
    cout<<ispowerof2(0);
    // cout<<countnumberof1s(7);
    // int arr[4] = {1,2,3,4};
    // subsets(arr,4);
    return 0;
}

