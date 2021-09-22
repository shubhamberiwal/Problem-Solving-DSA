


//kosaraju algorithm 

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v,e;
    cin>>v>>e;
    vector <int> adj[v];
    

    return 0;
}











/*

// naive approach time complexity is O(V(E+V));
// next step study kosaraju algorithm
#include<bits/stdc++.h>
using namespace std;


void dfs(int i, vector<int> &visited, vector<int> *adj)
{
    visited[i] = 1;
    for(auto it = adj[i].begin(); it!= adj[i].end(); it++)
    {
        if(!visited[*it])
            dfs(*it, visited, adj);
    }
}

void addEdge(int x, int y, vector<int> *adj)
{
    //this for the directed graph from x to y;
    adj[x].push_back(y);
}

int main()
{
    //input a graph in either matrix aur adj list

    int v,e;
    cout<< "Enter vertices and edges in the graph: ";
    cin>> v>>e;

    vector<int> *adj = new vector<int> [v];
    cout<<"Enter the values of edges: \n";
    for(int i = 0 ; i<e; i++)
    {
        int a, b;
        cin>>a>>b;
        addEdge(a,b,adj);
    }
    vector <int> mother_vertices;

    //run a for loop for each vertex and then run dfs for each
    // after which check if each have visited complete or not.

    for(int i = 0; i<v; i++)
    {
        vector<int> visited(v,0);
        visited[i] = 1;
        auto iter = adj[i].begin();
        for(; iter != adj[i].end(); iter++)
        {
            if(!visited[*iter])
            {
                dfs(*iter, visited, adj);
            }
        }
        int k=0;
        for(int j = 0; j<v; j++)
        {
            if(visited[j]==0)
                k=1;
        }
        if(k==0)
            mother_vertices.push_back(i);
        // cout<< i << " is a mother vertex"endl;
    }
    cout<<"Mother vertices are: ";
    for(auto x : mother_vertices)
        cout<< x <<" ";  
}


*/