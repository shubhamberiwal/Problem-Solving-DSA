
/*
Print all the nodes reachable from a given starting node in a digraph using BFS method. 
BFS method in graphs
Shubham Beriwalal  4NI19IS097 ISE A SECTION
*/

#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

void addEdge(list<int> *a, int x, int y)
{
    a[x].push_back(y);
    a[y].push_back(x);
}

void print_graph(list<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << "Adjacency list of vertex " << i << endl;
        cout << "head";
        for (auto it = adj[i].begin(); it != adj[i].end(); it++)
        {
            cout << " -> " << (*(it));
        }
        cout << endl;
    }
}

void bfs(int s, int v, list<int> adj[])
{
    vector<int> visited(v, 0);
    visited[s] = 1;
    queue<int> traverse;
    traverse.push(s);

    while (!traverse.empty())
    {
        s = traverse.front();
        cout << s << " ";
        traverse.pop();

        for (auto it = adj[s].begin(); it != adj[s].end(); it++)
        {
            if (visited[*it] == 0)
            {
                traverse.push(*it);
                visited[*it] = 1;
            }
        }
    }
}

int main()
{
    int v, e;
    cout << "Enter the number of vertices in the graph: ";
    cin >> v;
    cout << "Enter the number of edges in the graph: ";
    cin >> e;
    list<int> adj[v];
    cout << "Enter edges values: \n";
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        addEdge(adj, a, b);
    }
    print_graph(adj, v);
    cout << endl;
    cout << "Bfs order from vertex 0 is: \n";
    bfs(0, v, adj);
    cout << endl;

    return 0;
}















/*

// best bfs understanding 



#include <iostream>
#include <list>
#include <vector>
#include <queue>

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
    void bfs(int s);
};
Graph::Graph(int v)
{
    this->v = v;
    visited.assign(v, 0);
    adj = new list<int>[v];
}
void Graph::addEdge(int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
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

void Graph ::bfs(int s)
{
    queue<int> traversal;
    traversal.push(s);
    visited[s] = 1;

    cout << "The Bfs traversal starting from vertex " << s << " is:\n";
    while (!traversal.empty())
    {
        s = traversal.front();
        cout << s << " ";
        traversal.pop();

        for (auto i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if (visited[*i] == 0)
            {
                traversal.push(*i);
                visited[*i] = 1;
            }
        }
    }
}

int main()
{
    int v, e;
    // cout<<"Enter vertices in the graph: ";
    // cin>>v;
    // cout<< "Enter the edges in the graph: ";
    // cin>>e;
    //v=5;
    v = 6;
    Graph g(v);
    // cout<<"Enter the values of those edges: \n";
    // for (int i = 0; i < e; i++)
    // {
    //     int a, b;
    //     cin>>a>>b;
    //     g.addEdge(a,b);
    // }

    // example with 5 vertex
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(1, 2);
    // g.addEdge(2, 0);
    // g.addEdge(2, 4);
    // g.addEdge(3, 4);

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
    cout << endl;
    g.bfs(4);
    cout << endl;

    return 0;
}

























//sandeep program on bfs

#include<stdio.h>
#include<stdlib.h>

//shubham
void BFS(int a[10][10], int source, int *visited, int n)
{
    visited[source] = 1;
    int *q = new int[n] , front = 0 , rear = -1;
    q[++rear] = source;
    while(front<=rear)
    {
        int i = q[front++];
        printf("%d ",i);
        for ( int j=0 ; j < n ; j++)
        {
            int k = a[i][j];
            if(  k == 1 && visited[j] == 0)
            {
                q[++rear] = j;
                visited[j] = 1;
            }
        }
        
    }
}

//sandeep
void BFS(int a[10][10], int source, int *visited, int n){

    int q[10], u, front =0, rear = -1, i;
    
    q[++rear] = source;

    visited[source] = 1;

    printf("The reachable vertex are : ");
    printf("%d ",source);
    while(front<=rear){
        u = q[front++];
        for(i=0;i<n;i++){
            if((a[u][i] == 1) && (visited[i] == 0)){
                q[++rear] = i;
                visited[i] = 1;
                printf("%d ",i);
            }
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

    printf("BFS order is ");
    printf("\n");

    BFS(a,4,visited,n);

    for(i=0;i<n;i++){
        if(visited[i] == 0){
            printf("\nGraph is disconnected\n");
            return 0;
        }
    }

    printf("\nGraph is connected\n");
    return 0;

}






















/*


// first time try how to implement bfs using stl
// experiment and understand


#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

void addEdge(list<int> *a, int x, int y)
{
    a[x].push_back(y);
    a[y].push_back(x);
}

void print_graph(list<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << "Adjacency list of vertex " << i << endl;
        cout << "head";
        for (auto it = adj[i].begin(); it != adj[i].end(); it++)
        {
            cout << " -> " << (*(it));
            // cout << " -> " << *(adj+i+j) ;
            // cout << " -> " << *(adj[i]) ;
        }
        // for(auto x: adj[i])
        // {
        //     cout << " -> " << x;
        // }
        cout << endl;
    }
}

// void prii(list<int> *adj, int v){
//     for (auto x: adj)
//     {
//         cout<<x<< " ";
//     }

// }

void bfs(int s, int v, list<int> adj[])
{
    vector<int> visited(v, 0);
    visited[s] = 1;
    queue<int> traverse;
    traverse.push(s);
    // list<int> :: iterator it1 = &adj[s]; // invalid statement check why

    // list<int> :: iterator it1 = adj[s].begin();
    // for(auto x: it1); //invalid statement check why

    // auto it2 = adj[s];
    // for(auto x: it2)
    // {
    //     cout<< x <<"  ";
    // }
    // cout<<endl;

    while (!traverse.empty())
    {
        s = traverse.front();
        cout << s << " ";
        traverse.pop();

        for (auto it = adj[s].begin(); it != adj[s].end(); it++)
        {
            if (visited[*it] == 0)
            {
                traverse.push(*it);
                visited[*it] = 1;
            }
        }
    }

    // bool *visited = new bool[V];
    // for(int i = 0; i < V; i++)
    //     visited[i] = false;

    // // Create a queue for BFS
    // list<int> queue;

    // // Mark the current node as visited and enqueue it
    // visited[s] = true;
    // queue.push_back(s);
}

int main()
{
    int v, e;
    cout << "Enter the number of vertices in the graph: ";
    cin >> v;
    cout << "Enter the number of edges in the graph: ";
    cin >> e;
    list<int> adj[v]; // = new list<int> [v];
    cout << "Enter edges values: \n";
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        addEdge(adj, a, b);
    }
    print_graph(adj, v);
    cout << endl;

    // addedge(adj, 3, 2);
    // addEdge(adj, 0, 1);
    // addEdge(adj, 0, 2);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 2, 0);
    // addEdge(adj, 2, 4);
    // addEdge(adj, 3, 4);
    // print_graph(adj, v);
    cout << "Bfs order is: \n";
    bfs(0, v, adj);
    cout << endl;

    return 0;
}
*/