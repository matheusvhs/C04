#include <iostream>
#include <math.h>
using namespace std;

// Definindo a estrutura Ponto
typedef struct {
	int x;
	int y;	
} Ponto;

// Definindo a estrutura Node
struct Node {
    double length;
    int index;
    Node* left;
    Node* right;
};

// Função para criar um novo Node
Node* newNode(int index, double length) {
    Node* node = new Node();
    node->index = index;
    node->length = length;
    node->left = node->right = nullptr; // Inicializando os ponteiros left e right como nullptr
    return node;
}

// Função para inserir um novo Node na árvore
Node* insert(Node* node, int index, double length) {
    if (node == nullptr) return newNode(index, length); // Se a árvore estiver vazia, cria um novo Node
    if (length < node->length)
        node->left  = insert(node->left, index, length); // Se o comprimento for menor, insere na subárvore esquerda
    else
        node->right = insert(node->right, index, length); // Se o comprimento for maior, insere na subárvore direita
    return node;
}

// Função para imprimir os Nodes em ordem
void printInOrder(Node* node) {
    if (node != nullptr) {
        printInOrder(node->right); // Primeiro imprime a subárvore direita
        cout << node->index << ":" << node->length << endl; // Depois imprime o Node
        printInOrder(node->left); // Por fim, imprime a subárvore esquerda
    }
}

// Função para calcular a distância entre dois pontos
double distancia(Ponto p1, Ponto p2)
{
    // Fórmula da distância euclidiana
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y));
}

int main() {
    int P;
    cin >> P;
    Node* root = nullptr;
    for (int i = 0; i < P; i++) {
        Ponto p1, p2, p3;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y; // Lê as coordenadas dos pontos
        double d1 = distancia(p1, p2);
        double d2 = distancia(p1, p3);
        double length = max(d1, d2); // Calcula o comprimento máximo
        root = insert(root, i, length); // Insere o Node na árvore
    }
    printInOrder(root); // Imprime os Nodes em ordem
    return 0;
}
