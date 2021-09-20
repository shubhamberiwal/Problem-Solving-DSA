/* Find Minimum Cost Spanning Tree of a given undirected graph using the following algorithm: Prim’s algorithm 
Analyze the time efficiency of each of these methods and compare their performances by referring to the graphs plotted 
(time taken Vs n) for different values n (the no. of vertices).
Shubham Beriwala - 4NI19IS097 */

#include <bits/stdc++.h>
using namespace std;

void delay(int numberOfSeconds)
{
    int milliSeconds = 200 * numberOfSeconds;
    clock_t startTime = clock();
    while (clock() < startTime + milliSeconds)
        ;
}

int minweight(int weight[], int visited[], int n)
{
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0 && weight[i] < min)
        {
            min = weight[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMST(int parent[], int weight[], int n)
{
    int total = 0;
    cout << "\nEdges with weight in minimum spanning tree\n";
    for (int i = 0; i < n; i++)
    {
        printf("Edge: %d - %d  Weight: %d\n", parent[i], i, weight[i]);
        total += weight[i];
    }
    cout << "Total minimum cost of spanning tree is: " << total << endl;
}

int main()
{
    int n;
    cout << "Enter the vertices in the graph: ";
    cin >> n;
    int i, j;
    int graph[n][n], visited[n] = {0}, weight[n], parent[n];
    cout << "Enter the values and cost in the graph: \n";
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 0)
                graph[i][j] = INT_MAX;
        }
    for (i = 0; i < n; i++)
        weight[i] = 999;
    clock_t start, end;
    start = clock();

    parent[0] = -1;
    weight[0] = 0;
    int v;
    for (int edge = 0; edge < n - 1; edge++)
    {
        delay(1);
        int u = minweight(weight, visited, n);
        visited[u] = 1;

        for (v = 0; v < n; v++)
        {
            delay(1);
            if (graph[u][v] < 999 && visited[v] == 0 && graph[u][v] < weight[v])
            {
                parent[v] = u;
                weight[v] = graph[u][v];
            }
        }
    }
    end = clock();
    printMST(parent, weight, n);

    printf("Time taken = %ld seconds\n", (end - start) / CLOCKS_PER_SEC);
    return 0;
}




// For clear and better understanding

/*
#include<bits/stdc++.h>
using namespace std;

int v;
vector <int> weight;
vector <int> visited;
vector <int> parent;
int **graph;
int source;

int nextvertex()
{
    int min = 999 , index ;
    for (int i = 0; i < v; i++)
    {
        if(visited[i] == 0 && weight[i]<min)
            min = weight[i], index = i;
    }
    return index;
}
void primsalgo()
{
    visited.assign(v,0);
    weight.assign(v,999);
    parent.assign(v,-2);
    parent[source] = -1;
    weight[source] = 0;

    for (int count = 0; count < v-1; count++)
    {
        int i = nextvertex();
        visited[i] = 1;
        for (int j = 0; j < v; j++)
            if(graph[i][j] && weight[j]>graph[i][j] && !visited[j])
            {   
                weight[j] = graph[i][j]; 
                parent[j] = i;
            }
    }
}
void printmst()
{
    int total = 0;
    cout << "\nEdges with weight in minimum spanning tree\n";
    for (int i = 0; i < v; i++)
    {
        printf("Edge: %d - %d  Weight: %d\n", parent[i], i, weight[i]);
        total += weight[i];
    }
    cout << "Total minimum cost of spanning tree is: " << total << endl;
}
int main()
{
    cout<<"Enter total vertices: ";
    cin>>v;
    graph = new int*[v];
    
    cout<<"Enter the matrix along with the cost:\n";
    for (int i = 0; i < v; i++)
    {   
        graph[i] = new int[v];
        for (int j = 0; j < v; j++)
            cin >> graph[i][j];
    }
    cout<<endl;
    cout<<"Enter the starting point: ";
    cin>>source;
    primsalgo();
    printmst();
    return 0;    
}
*/














/*
#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h>


int main()
{
   int n, v, u,cost[10][10], visited[10]={0}, i, j; int
   count=1, mincost=0, min, a, b;

   printf("Enter number of vertices:");
   scanf("%d",&n);
   printf("\nEnter cost matrix (For infinity, put 999):\n");

   for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
       {
          scanf("%d",&cost[i][j]);
          if(cost[i][j]==0)
                cost[i][j]=999;
       }
visited[1]=1;
printf("\nThe edges of spanning tree are: \n");

while(count<n)
{
    min=999;
    for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
             if(cost[i][j]<min)
                 if(visited[i]==0)
                           continue;

             else
             {

                 min=cost[i][j];
                 a=u=i; b=v=j;
             }


  if(visited[u]==0 || visited[v]==0)
  {
      count++;
      printf("\nEdge(%d, %d) = %d", a, b, min);
      mincost+=min;
      visited[b]=1;
  }
  cost[a][b]=cost[b][a]=999;
  }

   printf("\nMinimum cost = %d", mincost);
   return 0;
}

*/