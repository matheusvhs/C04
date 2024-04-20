#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int valor;
    int peso;
};

double mochilaForcaBruta(int M, vector<Item>& itens, vector<Item>& selecionados) {
    int n = itens.size();
    double valorMaximo = 0.0;

    for (int i = 0; i < (1 << n); i++) {
        double valorTotal = 0.0;
        int pesoTotal = 0;
        vector<Item> temp;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                valorTotal += itens[j].valor;
                pesoTotal += itens[j].peso;
                temp.push_back(itens[j]);
            }
        }
        if (pesoTotal <= M && valorTotal > valorMaximo) {
            valorMaximo = valorTotal;
            selecionados = temp;
        }
    }

    return valorMaximo;
}

int main(void) {
    vector<Item> itens = {{60, 4}, {70, 7}, {30, 3}, {20, 3}};
    vector<Item> selecionados;
    int M = 10;
    cout << "Valor máximo que pode ser carregado na mochila: " << mochilaForcaBruta(M, itens, selecionados) << endl;
    cout << "Itens selecionados: " << endl;
    for (Item& i : selecionados) {
        cout << "Valor: " << i.valor << ", Peso: " << i.peso << endl;
    }
    return 0;
}
