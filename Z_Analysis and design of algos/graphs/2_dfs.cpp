

/*Check whether a given graph is connected or not using DFS method
Shubham Beriwala 4NI19IS097 ISE A SECTION
DFS METHOD
*/

#include <iostream>
#include <list>
#include <bits/stdc++.h>

using namespace std;

int v;
list<int> *adj;

void addEdge(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

// void print_graph(int v)
// {
//     for (int i = 0; i < v; i++)
//     {
//         cout << "Adjacency list of vertex " << i << endl;
//         cout << "head";
//         for (auto it = adj[i].begin(); it != adj[i].end(); it++)
//         {
//             cout << " -> " << (*(it));
//         }
//         cout << endl;
//     }
// }

void dfs(int s, vector<int> &visited)
{
    visited[s] = 1;
    cout << s << " ";

    for (auto it = adj[s].begin(); it != adj[s].end(); it++)
    {
        if (visited[*it] == 0)
        {
            dfs(*it, visited);
        }
    }
}

int main()
{
    int e;
    cout << "Enter the number of vertices in the graph: ";
    cin >> v;
    cout << "Enter the number of edges in the graph: ";
    cin >> e;
    // list <int> adj[v]; // = new list<int> [v];
    adj = new list<int>[v];
    vector<int> visited(v, 0);
    cout << "Enter edges values: \n";
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        addEdge(a, b);
    }
    // print_graph(v);
    cout << endl;

    cout << "Dfs order starting from vertex 0 is: \n";
    dfs(0, visited);
    cout << endl;
    vector<int> :: iterator it = visited.begin();
    for (; it != visited.end(); it++)
    {
        if (*it == 0)
        {
            cout << "Graph is not connected";
            return 0;
        }
    }
    cout << "Graph is Connected";
    return 0;
}













// sandeep program

/*

#include<stdio.h>
#include<stdlib.h>

void DFS(int n, int a[10][10], int u, int visited[]){
    int v;

    visited[u] = 1;
    printf("%d ",u);

    for(v=0;v<n;v++){
        if((a[u][v] == 1) && (visited[v]==0)){
            DFS(n,a,v,visited);
        }
    }
}

int main(){
    int n, a[10][10], visited[10],i,j;
    printf("Enter the size of the matrix: ");
    scanf("%d",&n);

    printf("Enter the adjecency matrix:\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0;i<n;i++){
        visited[i] = 0;
    }

    printf("DFS order is ");
    DFS(n,a,0,visited);
    printf("\n");

    for(i=0;i<n;i++){
        if(visited[i] == 0){
            printf("Graph is disconnected\n");
            return 0;
        }
    }

    printf("Graph is connected\n");
    return 0;

}


*/















/*


#include<iostream>
#include<vector>
#include<list>
#include<stack>

using namespace std;

class Graph
{
    public:
        int v;
        vector<int> visited;
        list<int> *adj;
        Graph(int v);
        void addEdge(int x, int y);
        void print_graph();
        void dfs(int s);
};

Graph::Graph(int v)
{
    this->v = v;
    visited.assign(v,0);
    adj = new list<int> [v];
}
void Graph :: addEdge(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
void Graph::print_graph()
{
    for (int i = 0; i < v; i++)
    {
        cout << "Printing adjacencies for vertex number " << i << ":\n";
        list<int>::iterator it = adj[i].begin();
        cout << "  " << i << " ( ";
        while (it != adj[i].end())
        {
            cout << *it << " ";
            it++;
        }
        cout << ")" << endl;
    }
}
void Graph :: dfs(int s)
{
    visited[s] = 1;
    stack<int> traversal;
    traversal.push(s);
    cout << s << " ";
    list<int> :: iterator it = adj[s].begin();
    while(it!=adj[s].end())
    {
        if(visited[*it]==0)
        {
            dfs(*it);
        }
        it++;
    }
}
int main()
{
    int v,e;
    // cout<< "Enter the number of vertices in the graph: ";
    // cin>>v;
    // cout<< "Enter the number of edges in the graph: ";
    // cin>>e;
    v=6;
    Graph g(v);
    // for (int i = 0; i < e; i++)
    // {
    //     int x, y; cin>>x>>y; g.addEdge(x,y);
    // }

    // example with 6 vertex
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);


    g.print_graph();
    cout<<endl;
    cout<< "Dfs traversal is: \n";
    g.dfs(4);
    cout<<endl;
    // for ( vector<int> :: iterator it = g.visited.begin(); it != g.visited.end(); it++)
    // {
    //     if (*it == 0)
    //     {
    //         cout << "Graph is not connected";
    //         return 0;
    //     }
    // }
    for(auto x: g.visited)
    {
        if(x == 0)
        {
            cout<< "Graph is disconnected\n";
            return 0;
        }
    }
    cout << "Graph is connected\n";    
    return 0;
}
*/