#include<iostream>
#include<string>
#include<list>
using namespace std;

#define INT_MAX 99999
#define MAX_CITIES 100

struct Estrada{
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

int shortest_path_dijkstra(Cidade cidades[], int vertices, int start, int end, float idh){
	bool intree[MAX_CITIES];
	int distance[MAX_CITIES], parent[MAX_CITIES];
	
	for(int u = 0; u < vertices; u++){
		intree[u] = false;
		distance[u] = INT_MAX;
		parent[u] = -1;
	}
	distance[start] = 0;
	int v = start;
	while(!intree[v]){
		intree[v] = true;
		list<Estrada>::iterator it;
		for(it = cidades[v].vizinhos.begin(); it != cidades[v].vizinhos.end(); ++it){
			Estrada estrada = *it;
			if(cidades[estrada.dest].idh >= idh && distance[estrada.dest] > distance[v] + estrada.distancia){
				distance[estrada.dest] = distance[v] + estrada.distancia;
				parent[estrada.dest] = v;
			}
		}
		v = 0;
		int dist = INT_MAX;
		for(int u = 0; u < vertices; u++){
			if(!intree[u] && dist > distance[u]){
				dist = distance[u];
				v = u;
			}
		}
	}
	return distance[end] == INT_MAX ? -1 : distance[end];
}

int main(){
	int num_cidades;
	cin >> num_cidades;
	cin >> num_cidades; // Adicionado conforme sua solicitação
	
	Cidade cidades[MAX_CITIES];
	
	for(int i=0; i< num_cidades; i++){
		cidades[i].codigo = i;
		cin >> cidades[i].nome;
		cin >> cidades[i].idh;
	}
	
	int num_estradas, origem, destino, distancia;
	cin >> num_estradas;
	
	for(int j=0; j < num_estradas; j++){
		cin >> origem;
		cin >> destino;
		cin >> distancia;
		cidades[origem].vizinhos.push_back({origem, destino, distancia});
		cidades[destino].vizinhos.push_back({destino, origem, distancia}); // Adiciona a estrada no sentido inverso também
	}
	
	float idh;
	cin>>origem>>destino>>idh;
	
	int result = shortest_path_dijkstra(cidades, num_cidades, origem, destino, idh);
	
	if(result == -1)
		cout << "Não é possível chegar ao destino passando apenas por cidades com IDH maior que " << idh << endl;
	else
		cout << result << endl;
	
	return 0;
}