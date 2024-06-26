#include <iostream>

using namespace std;

// Definindo a estrutura Peixe
struct Peixe {
    int id;
    int toxidade;
    Peixe* left;
    Peixe* right;
};

// Função para criar um novo peixe
Peixe* newPeixe(int id, double toxidade) {
    Peixe* peixe = new Peixe;
    peixe->id = id;
    peixe->toxidade = toxidade;
    peixe->left = peixe->right = NULL; // Inicializando os ponteiros left e right como NULL
    return peixe;
}

// Função para inserir um novo peixe na árvore
Peixe* insert(Peixe* root, int id, double toxidade) {
    if (root == NULL) {
        return newPeixe(id, toxidade); // Se a árvore estiver vazia, cria um novo peixe
    }
    if (toxidade < root->toxidade) {
        root->left = insert(root->left, id, toxidade); // Se a toxidade for menor, insere na subárvore esquerda
    } else {
        root->right = insert(root->right, id, toxidade); // Se a toxidade for maior, insere na subárvore direita
    }
    return root;
}

// Função para imprimir os peixes em ordem crescente de toxidade dentro de um intervalo
void inOrder(Peixe* root, double Tmin, double Tmax) {
    if (root == NULL) return;
    inOrder(root->left, Tmin, Tmax);
    if (root->toxidade >= Tmin && root->toxidade <= Tmax) {
        cout << root->id << ":" << root->toxidade << endl; // Se o peixe estiver no intervalo de toxidade, imprime o peixe
    }
    inOrder(root->right, Tmin, Tmax);
}

// Função para deletar a árvore
void deleteTree(Peixe* root) {
    if (root == NULL) return;
    deleteTree(root->left); // Deleta a subárvore esquerda
    deleteTree(root->right); // Deleta a subárvore direita
    delete root; // Deleta a raiz
}

int main() {
    int P;
    cin >> P;
    Peixe* root = NULL;

    for(int i = 0; i < P; i++) {
        double V, E, O;
        cin >> V >> E >> O;
        double toxidade = V * E * 7 * E * 7 * O; // Calcula a toxidade como double
        root = insert(root, i, toxidade); // Insere o peixe na árvore
    }

    double Tmin, Tmax;
    cin >> Tmin >> Tmax; // Lê o intervalo de toxidade

    inOrder(root, Tmin, Tmax); // Imprime os peixes em ordem crescente de toxidade e dentro do intervalo

    deleteTree(root); // Deleta a árvore
    root = NULL;
    
    return 0;
}
