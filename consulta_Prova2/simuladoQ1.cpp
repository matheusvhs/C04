#include <iostream>

using namespace std;

struct Torta {
    int id;
    int preco; // Alterado para int
    Torta* left;
    Torta* right;
};

Torta* newTorta(int id, int preco) { // Alterado para int
    Torta* torta = new Torta;
    torta->id = id;
    torta->preco = preco;
    torta->left = torta->right = NULL;
    return torta;
}

Torta* insert(Torta* root, int id, int preco) { // Alterado para int
    if (root == NULL) {
        return newTorta(id, preco);
    }
    if (preco < root->preco) {
        root->left = insert(root->left, id, preco);
    } else if (preco > root->preco) {
        root->right = insert(root->right, id, preco);
    }
    return root;
}

void inOrder(Torta* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->id << ":" << root->preco << endl; // Agora imprime como int
        inOrder(root->right);
    }
}

void deleteTree(Torta* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int T;
    cin >> T;
    Torta* root = NULL;

    for(int i = 0; i < T; i++) {
        double EM, P, D, A;
        cin >> EM >> P >> A >> D;
        int preco = static_cast<int>(EM*P*A+D+A); // Convertido para int
        root = insert(root, i, preco);
    }

    inOrder(root);

    deleteTree(root);
    root = NULL;
    
return 0;
}