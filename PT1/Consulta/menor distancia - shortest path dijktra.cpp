#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// Estrutura para representar uma aresta
struct Edge {
    int to;
    int weight;
};

// Função para encontrar o caminho mais curto usando Dijkstra
void dijkstra(vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const Edge& e : graph[u]) {
            int v = e.to;
            int w = e.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Imprime as distâncias mínimas a partir do vértice inicial
    cout << "Distâncias mínimas a partir do vértice " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Vértice " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    int n = 7; // Número de vértices
    vector<vector<Edge>> graph(n);

    // Exemplo de grafo (adapte conforme necessário)
    graph[0].push_back({-1, -1});
    graph[1].push_back({2, 1});
    graph[2].push_back({4, 2});
    graph[2].push_back({5, 3});
    graph[2].push_back({6, 13});
    graph[2].push_back({3, 5});
    graph[3].push_back({6, 3});
    graph[6].push_back({5, 4});
    graph[5].push_back({3, 1});
    graph[4].push_back({5, 3});
    graph[4].push_back({1, 4});

    int start_vertex = 1; // Vértice inicial
    dijkstra(graph, start_vertex);

    return 0;
}
