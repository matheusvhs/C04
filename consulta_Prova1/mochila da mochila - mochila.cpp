#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int valor;
    int peso;
};

bool comparar(Item a, Item b) {
    double r1 = (double)a.valor / a.peso;
    double r2 = (double)b.valor / b.peso;
    return r1 > r2;
}

double mochilaGulosa(int M, vector<Item>& itens) {
    sort(itens.begin(), itens.end(), comparar);

    int pesoAtual = 0;
    double valorFinal = 0.0;

    for (Item& i : itens) {
        if (pesoAtual + i.peso <= M) {
            pesoAtual += i.peso;
            valorFinal += i.valor;
        } else {
            int pesoRestante = M - pesoAtual;
            valorFinal += i.valor * ((double) pesoRestante / i.peso);
            break;
        }
    }

    return valorFinal;
}

int main(void) {
    vector<Item> itens = {{60, 4}, {70, 7}, {30, 3}, {20, 3}};
    int M = 10;
    cout << "Valor máximo que pode ser carregado na mochila: " << mochilaGulosa(M, itens) << endl;
    return 0;
}