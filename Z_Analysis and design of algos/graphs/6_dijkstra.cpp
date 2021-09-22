/*
5. From a given vertex in a weighted connected graph, find shortest paths to other vertices using Dijkstra's algorithm.
SHUBHAM BERIWALA - 4NI19IS097
*/
#include <bits/stdc++.h>
using namespace std;
int v;
int source;
vector<int> included;
vector<int> cost;
vector<int> parent;
int **graph;

int nextlowest()
{
    int min = 999, index;
    for (int i = 0; i < v; i++)
        if (min > cost[i] && included[i] == 0)
            min = cost[i], index = i;
    return index;
}
void dijkstra(int source)
{
    included.assign(v, 0);
    parent.assign(v, -1);
    cost.assign(v, 999);
    cost[source] = 0;
    parent[source] = source;
    for (int count = 0; count < v - 1; count++)
    {
        int i = nextlowest();
        included[i] = 1;
        for (int j = 0; j < v; j++)
            if (cost[j] > cost[i] + graph[i][j] && included[j] == 0 && graph[i][j] != 0 && cost[i] != 999)
                cost[j] = cost[i] + graph[i][j], parent[j] = i;
    }
}
void findandprintparents(int i)
{
    if (parent[i] == source)
    {
        cout << source << " - ";
        return;
    }
    findandprintparents(parent[i]);
    cout << parent[i] << " - ";
}
void printdijkstra()
{
    for (int i = 0; i < v; i++)
    {
        if (parent[i] != source)
            findandprintparents(parent[i]);
        cout << parent[i] << " - " << i << "  Cost: " << cost[i] << endl;
    }
}
int main()
{
    cout << "Enter Vertices: ";
    cin >> v;
    graph = new int *[v];
    for (int i = 0; i < v; i++)
    {
        graph[i] = new int[v];
        for (int j = 0; j < v; j++)
            cin >> graph[i][j];
    }
    cout << "Enter the single source vertex: ";
    cin >> source;
    dijkstra(source);
    printdijkstra();
    return 0;
}






/*



#include<bits/stdc++.h>
using namespace std;

int graph[10][10] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

int nextlowest(int v, vector<int> cost, vector<int> included)
{
    int min= 999, index;
    for (int i = 0; i < v; i++)
    {
        if(included[i]==0 && cost[i]<min)
            min = cost[i], index = i;
    }
    return index;
}

void dijkstra(int v, int source, vector<int> &parent, vector<int> &cost)
{
    vector <int> included(v,0);
    parent[source] = 0;
    cost[source] = 0;
    for (int count = 0; count < v-1; count++)
    {
        int i = nextlowest(v, cost,included);
        included[i] = 1;
        for(int j=0 ; j<v ; j++)
        {
            if(!included[j] && graph[i][j] && cost[i]!=999 && cost[j] > cost[i]+graph[i][j])
            {
                cost[j] = cost[i]+graph[i][j];
                parent[j] = i;
            }
        }
    }
}

void findparent(int i ,int source, vector<int> parent)
{
    if(parent[i]==source)
    {
        cout << source << " - ";
        return;
    }
    findparent(parent[i], source, parent);
    cout<< parent[i] << " - ";
}

void printdijkstra(int v, int source, vector<int> parent, vector<int> cost)
{

    for (int i = 0; i < v; i++)
    {
        if(parent[i]!=source)
        {
            findparent(parent[i], source, parent);
        }
        cout<< parent[i] << " - " << i << "   Total Cost: " << cost[i]<<endl;
    }
    
}



void printSolution(vector<int> cost)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < 9; i++)
        printf("%d \t\t %d\n", i, cost[i]);
}

int main()
{
    int v;
    v=9;
    // cin>>v;
    
    // vector<pair<int,pair<int,int>>> adj;
    
    // int *graph[10] ;
    // for(int i = 0; i < 10; i++)
    //     graph[i] = new int[10];

    // for (int i = 0; i < v; i++)
    // {
    //     for (int j = 0; j < v; j++)
    //     {
    //         cin>>graph[i][j];
    //     }
    // }

    vector<int> parent(v,-2);
    vector<int> cost(v,999);
    int source;
    // cin>>source;
    source = 0;
    dijkstra(v, source, parent,cost);
    printdijkstra(v, source, parent, cost);
    // printSolution(cost);

    return 0;    
}


*/