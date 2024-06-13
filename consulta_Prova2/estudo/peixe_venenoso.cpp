#include <iostream>

using namespace std;

struct Peixe {
    int id;
    double toxidade;
    Peixe* left;
    Peixe* right;
};

Peixe* newPeixe(int id, double toxidade) {
    Peixe* peixe = new Peixe;
    peixe->id = id;
    peixe->toxidade = toxidade;
    peixe->left = peixe->right = NULL;
    return peixe;
}

Peixe* insert(Peixe* root, int id, double toxidade) {
    if (root == NULL) {
        return newPeixe(id, toxidade);
    }
    if (toxidade < root->toxidade) {
        root->left = insert(root->left, id, toxidade);
    } else if (toxidade > root->toxidade) {
        root->right = insert(root->right, id, toxidade);
    }
    return root;
}

void printLevel(Peixe* root, int level, double Tmin, double Tmax) {
    if (root == NULL) return;
    if (level == 1 && root->toxidade >= Tmin && root->toxidade <= Tmax) {
        cout << root->id << ":" << root->toxidade << endl;
    } else if (level > 1) {
        printLevel(root->left, level-1, Tmin, Tmax);
        printLevel(root->right, level-1, Tmin, Tmax);
    }
}

int height(Peixe* node) {
    if (node == NULL) return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight) return(lheight+1);
        else return(rheight+1);
    }
}

void levelOrder(Peixe* root, double Tmin, double Tmax) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printLevel(root, i, Tmin, Tmax);
    }
}

void deleteTree(Peixe* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int P;
    cin >> P;
    Peixe* root = NULL;

    for(int i = 0; i < P; i++) {
        double V, E, O;
        cin >> V >> E >> O;
        double toxidade = int(V * E * 7 * E * 7 * O); // Número atômico do Nitrogênio é 7
        root = insert(root, i, toxidade);
    }

    double Tmin, Tmax;
    cin >> Tmin >> Tmax;

    levelOrder(root, Tmin, Tmax);

    deleteTree(root);
    root = NULL;
    
    return 0;
}
