#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <vector>
using namespace std;

#define MAX_CITIES 100

struct Estrada {
    int orig;
    int dest;
    int distancia;
};

struct Cidade {
    string nome;
    int codigo;
    float idh;
    list<Estrada> vizinhos;
};

struct CompareDist {
    bool operator()(const Estrada &a, const Estrada &b) {
        return a.distancia > b.distancia;
    }
};

int minimum_spanning_tree_prim(Cidade cidades[], int num_cidades, float idh) {
    vector<bool> visited(num_cidades, false);
    priority_queue<Estrada, vector<Estrada>, CompareDist> pq;

    visited[0] = true;
    for (auto &estrada : cidades[0].vizinhos) {
        if (cidades[estrada.dest].idh >= idh) {
            pq.push(estrada);
        }
    }

    int min_dist = 0;
    while (!pq.empty()) {
        Estrada e = pq.top();
        pq.pop();
        int u = e.dest;

        if (visited[u]) continue;

        visited[u] = true;
        min_dist += e.distancia;

        for (auto &estrada : cidades[u].vizinhos) {
            if (!visited[estrada.dest] && cidades[estrada.dest].idh >= idh) {
                pq.push(estrada);
            }
        }
    }

    return min_dist;
}

int main() {
    int num_cidades;
    cin >> num_cidades;
    
    Cidade cidades[MAX_CITIES];

    for (int i = 0; i < num_cidades; i++) {
        cidades[i].codigo = i;
        cin >> cidades[i].nome;
        cin >> cidades[i].idh;
    }

    int num_estradas, origem, destino, distancia;
    cin >> num_estradas;

    for (int j = 0; j < num_estradas; j++) {
        cin >> origem;
        cin >> destino;
        cin >> distancia;
        cidades[origem].vizinhos.push_back({origem, destino, distancia});
        cidades[destino].vizinhos.push_back({destino, origem, distancia});
    }

    float idh;
    cin >> idh;

    int result = minimum_spanning_tree_prim(cidades, num_cidades, idh);

    cout << result << endl;

    return 0;
}
