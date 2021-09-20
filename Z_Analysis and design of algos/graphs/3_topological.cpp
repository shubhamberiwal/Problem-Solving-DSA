

/*
Obtain the topological ordering of vertices in a given digraph using (i) DFSmethod (ii) Edge
elimination method 
Shubham Beriwala 4NI19IS097 ISE A SECTION
Topological Sort method
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, count = 0, a[1000][1000], flag[1000], indeg[1000];
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the Equivalent matrix\n");
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        flag[i] = 0;
        indeg[i] = 0;
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            indeg[i] = indeg[i] + a[j][i];
        }
    }
    printf("Topological order is:");
    while (count < n)
    {
        for (k = 0; k < n; k++)
        {
            if (indeg[k] == 0 && flag[k] == 0)
            {
                printf(" %d", k);
                flag[k] = 1;
                count++;
                for (i = 0; i < n; i++)
                {
                    if (a[k][i] == 1)
                        indeg[i]--;
                }
            }
        }
    }

    return 0;
}




// DeDu

// Topological sorting using source removal method

#include<stdio.h>

int main()
{
    int n, count =0, a[10][10], inDeg[10], flag[10], i,j,k;

    printf("Enter the number of vertex: ");
    scanf("%d",&n);

    printf("Enter the adjacency matrix :\n");

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(i=1; i<=n; i++){
        flag[i] = 0; inDeg[i] = 0;
    }

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            inDeg[i] += a[j][i];
        }
    }

    printf("Topological sort order is: ");

    while(count < n)
    {
        for(k=1;k<=n;k++)
        {
            if(inDeg[k] == 0 && flag[k] == 0)
            {
                printf("%d ",k);
                flag[k] = 1;
                count++;
                for(i=1; i<=n; i++)
                {
                    if(a[k][i] == 1)
                    {
                        inDeg[i]--;
                    }
                }
            }
        }
    }
    return 0;
}






