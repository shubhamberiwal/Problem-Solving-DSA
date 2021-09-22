


#include<bits/stdc++.h>
using namespace std;

int v;
int **graph;
int **answer;

void printfloyd()
{
    cout << "All pair shortest path:\n";    
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if(answer[i][j] == 999)
                cout<< "INF  " ;
            else
                cout << answer[i][j]<< "  ";
        }
        cout<< endl;
    }
}
void floydwarshall()
{

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            if(answer[j][i]!=999 && answer[j][i])
                for (int k = 0; k < v; k++)
                    if(answer[i][k]!=999 && (answer[j][i] + answer[i][k]) < answer[j][k])
                        answer[j][k] = answer[j][i] + answer[i][k];
    }
}

int main()
{
    cout<<"Enter vertices: "; 
    cin>>v;
    cout<<"Enter the matrix: "<<endl;
    graph = new int*[v];
    answer = new int*[v];
    for(int i = 0; i<v; i++)
    {
        graph[i] = new int[v];
        answer[i] = new int[v];
        for(int j = 0; j<v ; j++)
        {
            cin>>graph[i][j];
            answer[i][j] = graph[i][j];
        }
    }
    floydwarshall();
    printfloyd();
    return 0;
}








/*
#include<bits/stdc++.h>
using namespace std;

int v;
vector <int> visited;
vector <int> weight;
vector <int> parent;
int **graph;

int main()
{
    cout<<"Enter vertices: "; 
    cin>>v;
    cout<<"Enter the matrix: "<<endl;
    graph = new int*[v];
    for(int i = 0; i<v; i++)
    {
        graph[i] = new int[v];
        for(int j = 0; j<v ; j++)
        {
            cin>>graph[i][j];
        }
    }
}
*/

