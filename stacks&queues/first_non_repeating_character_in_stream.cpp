#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

string nonrepeat(string s) {
    
    // vector<int> repeated(26,0);
    
    vector<int> visited(26,0);
    int n = s.size();
    string ans = "";
    vector<char> v;
    for(int i=0; i<n; i++) {
        
        int pos = s[i] - 'a';
        
        if( !visited[pos] ) {
            v.push_back(s[i]);
        }
        visited[pos]++;
        int f=0;
        int m=v.size();
        for(int j=0; j<m; j++) {
            int pos2 = v[j] - 'a';
            if( visited[pos2] == 1 ) {
                ans.push_back(v[j]);
                f=1;
                break;
            }
            // else {
            //     v.erase(v.begin()+)
            // }
        }
        if(f==0) ans.push_back('#');
    }
    return ans;
}

int main()
{
    //int n; cin>>n;
    
    
    return 0;
}



