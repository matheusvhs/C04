#include <iostream>

using namespace std;

struct Ponto {
    int x, y;
};

bool dentro(Ponto p, Ponto poligono[], int N) {
    int cruzamentos = 0;
    for (int i = 0, j = N - 1; i < N; j = i++) {
        if (((poligono[i].y > p.y) != (poligono[j].y > p.y)) &&
            (p.x < (poligono[j].x - poligono[i].x) * (p.y - poligono[i].y) / (poligono[j].y - poligono[i].y) + poligono[i].x)) {
            cruzamentos++;
        }
    }
    return cruzamentos % 2 == 1;
}

int main() {
    int N;
    cin >> N;
    Ponto poligono[N];
    for (int i = 0; i < N; i++) {
        cin >> poligono[i].x >> poligono[i].y;
    }
    Ponto p;
    cin >> p.x >> p.y;
    if (dentro(p, poligono, N)) {
        cout << "DENTRO";
    } else {
        cout << "!(DENTRO)";
    }
    return 0;
}
