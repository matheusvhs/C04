#include <iostream>
#include <math.h>
using namespace std;

typedef struct {
	int x;
	int y;	
} Ponto;

struct Node {
    double length;
    int index;
    Node* left;
    Node* right;
};

Node* newNode(int index, double length) {
    Node* node = new Node();
    node->index = index;
    node->length = length;
    node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* node, int index, double length) {
    if (node == nullptr) return newNode(index, length);
    if (length < node->length)
        node->left  = insert(node->left, index, length);
    else
        node->right = insert(node->right, index, length);
    return node;
}

void printInOrder(Node* node) {
    if (node != nullptr) {
        printInOrder(node->right);
        cout << node->index << ":" << node->length << endl;
        printInOrder(node->left);
    }
}

double distancia(Ponto p1, Ponto p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y));
}

int main() {
    int P;
    cin >> P;
    Node* root = nullptr;
    for (int i = 0; i < P; i++) {
        Ponto p1, p2, p3;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        double d1 = distancia(p1, p2);
        double d2 = distancia(p1, p3);
        double length = max(d1, d2);
        root = insert(root, i, length);
    }
    printInOrder(root);
    return 0;
}
