#include <iostream>
#include <cmath>

using namespace std;

struct Ponto {
    int x, y;
};

double distancia(Ponto a, Ponto b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int N;
    cin >> N;
    Ponto pontos[N];
    for (int i = 0; i < N; i++) {
        cin >> pontos[i].x >> pontos[i].y;
    }
    Ponto usuario;
    cin >> usuario.x >> usuario.y;

    Ponto maisProximo = pontos[0];
    double menorDistancia = distancia(usuario, maisProximo);

    for (int i = 1; i < N; i++) {
        double dist = distancia(usuario, pontos[i]);
        if (dist < menorDistancia || (dist == menorDistancia && (pontos[i].x < maisProximo.x || (pontos[i].x == maisProximo.x && pontos[i].y < maisProximo.y)))) {
            maisProximo = pontos[i];
            menorDistancia = dist;
        }
    }

    cout << maisProximo.x << " " << maisProximo.y;
    return 0;
}