#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);

    int vertices, edges;
    cin >> vertices >>  edges;

    int Graph[vertices][vertices];
    memset(Graph, 0, sizeof(Graph));

    //Set value in the matrix
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        Graph[u][v] = 1;
    }

    //Print the matrix
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    cout << endl;
    //Printing the graph
    for (int i = 0; i < vertices; i++)
    {
        cout << i << " --> ";
        for (int j = 0; j < vertices; j++)
        {
            if(Graph[i][j] == 1)
                cout << j << " ";
        }
        cout << endl;
    }
    
    

    return 0;
}