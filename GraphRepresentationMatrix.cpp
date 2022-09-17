#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);

    int vertices, edges;
    scanf("%d%d", &vertices, &edges);

    int Graph[vertices][vertices];
    memset(Graph, 0, sizeof(Graph));

    for(int i=0; i<edges; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        Graph[u][v] = 1;
    }

    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            printf("%d ", Graph[i][j]);
        }
        printf("\n");
    }


    for(int i=0; i<vertices; i++)
    {
        printf("%d --> ", i);
        for(int j=0; j<vertices; j++)
        {
            if(Graph[i][j]==1)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}