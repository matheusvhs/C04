#include <iostream>

using namespace std;

void calcularCercado(int metrosCerca) {
    int melhorLargura = 0;
    int melhorComprimento = 0;
    int maxArea = 0;

    // Loop para verificar todas as combinações possíveis de largura e comprimento
    for (int largura = 1; largura <= metrosCerca / 2; ++largura) {
        int comprimento = metrosCerca - 2 * largura;
        int area = largura * comprimento;
        if (area > maxArea) {
            maxArea = area;
            melhorLargura = largura;
            melhorComprimento = comprimento;
        }
    }

    cout << melhorLargura << " x " << melhorComprimento << endl;
    cout  << endl;
}

int main() {
    int metrosCerca=0;
    cin >> metrosCerca;

    calcularCercado(metrosCerca);

    return 0;
}
