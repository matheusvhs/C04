#include <iostream>

using namespace std;

struct Torta {
    int id;
    int preco;
    Torta* left;
    Torta* right;
};

Torta* newTorta(int id, int preco) {
    Torta* torta = new Torta;
    torta->id = id;
    torta->preco = preco;
    torta->left = torta->right = NULL;
    return torta;
}

Torta* insert(Torta* root, int id, int preco) {
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

void show_in_range(Torta* root, int min, int max) {
    if (root != NULL) {
        if (min < root->preco) {
            show_in_range(root->left, min, max);
        }
        if (min <= root->preco && max >= root->preco) {
            cout << root->id << ":" << root->preco << endl;
        }
        if (max > root->preco) {
            show_in_range(root->right, min, max);
        }
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
        int preco = static_cast<int>(EM*P*A+D+A);
        root = insert(root, i, preco);
    }

    int PFmin, PFmax;
    cin >> PFmin >> PFmax;

    show_in_range(root, PFmin, PFmax);

    deleteTree(root);
    root = NULL;
    
    return 0;
}
