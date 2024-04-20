#include <iostream>
#define MAX 10

using namespace std;

bool visited[MAX];
int adj[MAX][MAX];

void BFS(int v, int start) {
    visited[start] = true;

    for(int i = 0; i < v; i++) {
        if(adj[start][i] == 1 && !visited[i]) {
            BFS(v, i);
        }
    }
}

bool isConnected(int v) {
    for(int i = 0; i < v; i++)
        if(!visited[i])
            return false;
    return true;
}

int main() {
    int v, start, src, dest;

    cin >> v >> start;

    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            adj[i][j] = 0;

    while(true) {
        cin >> src >> dest;
        if(src == -1 && dest == -1)
            break;
        adj[src][dest] = 1;
        adj[dest][src] = 1;
    }

    BFS(v, start);

    if(isConnected(v))
        cout << "Conexo" << endl;
    else
        cout << "Nao conexo" << endl;

    return 0;
}