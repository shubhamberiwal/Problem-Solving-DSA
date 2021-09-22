/*
6. Compute the transitive closure of a given directed graph using Warshall's algorithm. Analyze its time efficiency.
SHUBHAM BERIWALA - 4NI19IS097
*/
#include<bits/stdc++.h>
using namespace std;
int v;
int **graph;
int **transitive;
void printtransitiveclosure()
{
    cout<<"Transitive Closure of graph is: \n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if(i == j)
                cout<< "1 " ;
            else
                cout << transitive[i][j]<< " ";
        }
        cout<< endl;
    }
}
void transitiveclosure(int **transitive)
{
    for (int k = 0; k < v; k++)
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
                transitive[i][j] = transitive[i][j] || (transitive[i][k] && transitive[k][j]);   
}
int main()
{
    cout<<"Enter vercies: ";
    cin>>v;
    graph = new int*[v];
    transitive = new int*[v];
    for (int i = 0; i < v; i++)
    {   
        graph[i] = new int[v];
        transitive[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
                cin >> graph[i][j];
                transitive[i][j] = graph[i][j];
        }
    }
    transitiveclosure(transitive);
    printtransitiveclosure();
    return 0;
}