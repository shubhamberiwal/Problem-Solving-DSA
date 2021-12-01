

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

int rott_oranges( vector<vector<int>>&matrix ) {

    if(matrix.empty()) return 0;

    int n = matrix.size();
    int m = matrix[0].size();

    queue<pair<int,int>> q;
    int tot = 0, cnt = 0, time = 0;
    for(int i=0; i<n; i++ ) {
        for(int j=0; j<m; j++) {
            if( matrix[i][j] == 2 ) q.push({i,j});
            if( matrix[i][j]!=0 ) tot++;
        }
    }
    // u,r,d,l
    vector<int> ai = {-1,0,1,0};
    vector<int> aj = {0,1,0,-1};
    while(!q.empty()) {
        int k = q.size();
        cnt += k;
        while(k--) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int k=0; k<4; k++) {
                int ti = x + ai[k];
                int tj = y + aj[k];
                if( ti>=0 && tj>=0 && ti<n && tj<m && matrix[ti][tj]==1) {
                    matrix[ti][tj] = 2;
                    q.push({ti,tj});
                }
            }
        }
        if(!q.empty()) time++;
    }
    if(cnt==tot)
        return time;
    else return -1;
}

int main()
{
    //int n; cin>>n;
    
    
    return 0;
}



