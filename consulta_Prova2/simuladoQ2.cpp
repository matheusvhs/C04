#include <iostream>

using namespace std;

// Definindo a estrutura Torta
struct Torta {
    int id;
    int preco;
    Torta* left;
    Torta* right;
};

// Função para criar uma nova torta
Torta* newTorta(int id, int preco) {
    Torta* torta = new Torta;
    torta->id = id;
    torta->preco = preco;
    torta->left = torta->right = NULL; // Inicializando os ponteiros left e right como NULL
    return torta;
}

// Função para inserir uma nova torta na árvore
Torta* insert(Torta* root, int id, int preco) {
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

// Função para imprimir as tortas em um intervalo de preços
void show_in_range(Torta* root, int min, int max) {
    if (root != NULL) {
        if (min < root->preco) {
            show_in_range(root->left, min, max); // Se o preço mínimo for menor que o preço da raiz, procura na subárvore esquerda
        }
        if (min <= root->preco && max >= root->preco) {
            cout << root->id << ":" << root->preco << endl; // Se o preço da raiz estiver no intervalo, imprime a torta
        }
        if (max > root->preco) {
            show_in_range(root->right, min, max); // Se o preço máximo for maior que o preço da raiz, procura na subárvore direita
        }
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
        int preco = static_cast<int>(EM*P*A+D+A); // Calcula o preço e converte para int
        root = insert(root, i, preco); // Insere a torta na árvore
    }

    int PFmin, PFmax;
    cin >> PFmin >> PFmax; // Lê o intervalo de preços

    show_in_range(root, PFmin, PFmax); // Imprime as tortas no intervalo de preços

    deleteTree(root); // Deleta a árvore
    root = NULL;
    
    return 0;
}
