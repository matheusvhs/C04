#include <iostream>

using namespace std;

// Definindo a estrutura Peixe
struct Peixe {
    int id;
    double toxidade;
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
    } else if (toxidade > root->toxidade) {
        root->right = insert(root->right, id, toxidade); // Se a toxidade for maior, insere na subárvore direita
    }
    return root;
}

// Função para imprimir os peixes em um nível específico e dentro de um intervalo de toxidade
void printLevel(Peixe* root, int level, double Tmin, double Tmax) {
    if (root == NULL) return;
    if (level == 1 && root->toxidade >= Tmin && root->toxidade <= Tmax) {
        cout << root->id << ":" << root->toxidade << endl; // Se o peixe estiver no nível e no intervalo de toxidade, imprime o peixe
    } else if (level > 1) {
        printLevel(root->left, level-1, Tmin, Tmax); // Se o nível for maior que 1, procura na subárvore esquerda
        printLevel(root->right, level-1, Tmin, Tmax); // Se o nível for maior que 1, procura na subárvore direita
    }
}

// Função para calcular a altura da árvore
int height(Peixe* node) {
    if (node == NULL) return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight) return(lheight+1);
        else return(rheight+1);
    }
}

// Função para imprimir os peixes em ordem de nível e dentro de um intervalo de toxidade
void levelOrder(Peixe* root, double Tmin, double Tmax) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printLevel(root, i, Tmin, Tmax); // Imprime os peixes em cada nível
    }
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
        double toxidade = int(V * E * 7 * E * 7 * O); // Calcula a toxidade e converte para int
        root = insert(root, i, toxidade); // Insere o peixe na árvore
    }

    double Tmin, Tmax;
    cin >> Tmin >> Tmax; // Lê o intervalo de toxidade

    levelOrder(root, Tmin, Tmax); // Imprime os peixes em ordem de nível e dentro do intervalo de toxidade

    deleteTree(root); // Deleta a árvore
    root = NULL;
    
    return 0;
}
