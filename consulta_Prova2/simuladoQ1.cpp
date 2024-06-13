#include <iostream>

using namespace std;

// Definindo a estrutura Torta
struct Torta {
    int id;
    int preco; // Alterado para int
    Torta* left;
    Torta* right;
};

// Função para criar uma nova torta
Torta* newTorta(int id, int preco) { // Alterado para int
    Torta* torta = new Torta;
    torta->id = id;
    torta->preco = preco;
    torta->left = torta->right = NULL; // Inicializando os ponteiros left e right como NULL
    return torta;
}

// Função para inserir uma nova torta na árvore
Torta* insert(Torta* root, int id, int preco) { // Alterado para int
    if (root == NULL) {
        return newTorta(id, preco); // Se a árvore estiver vazia, cria uma nova torta
    }
    if (preco < root->preco) {
        root->left = insert(root->left, id, preco); // Se o preço for menor, insere na subárvore esquerda
    } else if (preco > root->preco) {
        root->right = insert(root->right, id, preco); // Se o preço for maior, insere na subárvore direita
    }
    return root;
}

// Função para imprimir a árvore em ordem
void inOrder(Torta* root) {
    if (root != NULL) {
        inOrder(root->left); // Primeiro imprime a subárvore esquerda
        cout << root->id << ":" << root->preco << endl; // Agora imprime como int
        inOrder(root->right); // Depois imprime a subárvore direita
    }
}

// Função para deletar a árvore
void deleteTree(Torta* root) {
    if (root == NULL) return;
    deleteTree(root->left); // Deleta a subárvore esquerda
    deleteTree(root->right); // Deleta a subárvore direita
    delete root; // Deleta a raiz
}

int main() {
    int T;
    cin >> T;
    Torta* root = NULL;

    for(int i = 0; i < T; i++) {
        double EM, P, D, A;
        cin >> EM >> P >> A >> D;
        int preco = static_cast<int>(EM*P*A+D+A); // Convertido para int
        root = insert(root, i, preco); // Insere a torta na árvore
    }

    inOrder(root); // Imprime a árvore em ordem

    deleteTree(root); // Deleta a árvore
    root = NULL;
    
    return 0;
}
