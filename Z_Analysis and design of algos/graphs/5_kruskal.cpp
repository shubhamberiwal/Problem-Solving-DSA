/* Find Minimum Cost Spanning Tree of a given undirected graph using the following algorithm: Kruskal’s algorithm 
Analyze the time efficiency of each of these methods and compare their performances by referring to the graphs plotted 
(time taken Vs n) for different values n (the no. of vertices).
Shubham Beriwala - 4NI19IS097 */

#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int parent[10];

void delay(int numberOfSeconds)
{
    int milliSeconds = 200 * numberOfSeconds;
    clock_t startTime = clock();
    while (clock() < startTime + milliSeconds)
        ;
}

int findparent(int a)
{
    delay(1);
    if (parent[a] == a)
        return a;
    return parent[a] = findparent(parent[a]);
}

void combine(int a, int b, int rank[])
{
    if (rank[a] > rank[b])
        parent[b] = a;
    else if (rank[b] > rank[a])
        parent[a] = b;
    else
    {
        parent[a] = b;
        rank[b]++;
    }
}

int mstkrusk(int n, vector<pair<int, pair<int, int>>> adj)
{
    int rank[n];
    int mincost = 0;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    int costmst = 0;
    sort(adj.begin(), adj.end());

    auto iter = adj.begin();
    for (; iter != adj.end(); iter++)
    {
        delay(1);
        int a = iter->second.first;
        int b = iter->second.second;

        int a1 = findparent(a);
        int b1 = findparent(b);

        if (a1 != b1)
        {
            //connect the 2 components here okay
            cout << "Edge: " << a << " - " << b << " Cost: " << iter->first << endl;
            mincost += iter->first;
            combine(a1, b1, rank);
        }
    }
    return mincost;
}

int main()
{
    int v, e;
    cout << "Enter vertices and edges in graph: ";
    cin >> v >> e;
    vector<pair<int, pair<int, int>>> edges;
    cout << "Enter the edges and their weights: \n";

    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }

    clock_t start, end;
    start = clock();
    cout << "Mst using Kruskal Algorithm, edges are:\n";
    int mincost = mstkrusk(v, edges);
    end = clock();
    cout << "\nTotal Cost of MST is " << mincost;
    printf("\nTime taken = %ld seconds\n", (end - start) / CLOCKS_PER_SEC);

    return 0;
}








// v=9,e=14;
// edges.push_back({4, {0, 1}});
// edges.push_back({8, {0, 7}});
// edges.push_back({8, {1, 2}});
// edges.push_back({11, {1, 7}});
// edges.push_back({7, {2, 3}});
// edges.push_back({2, {2, 8}});
// edges.push_back({4, {2, 5}});
// edges.push_back({9, {3, 4}});
// edges.push_back({14, {3, 5}});
// edges.push_back({10, {4, 5}});
// edges.push_back({2, {5, 6}});
// edges.push_back({1, {6, 7}});
// edges.push_back({6, {6, 8}});
// edges.push_back({7, {7, 8}});

// kruskal
// v=9, e=14
// 0 1 4
// 0 7 8
// 1 2 8
// 1 7 11
// 2 3 7
// 2 8 2
// 2 5 4
// 3 4 9
// 3 5 14
// 4 5 10
// 5 6 2
// 6 7 1
// 6 8 6
// 7 8 7
