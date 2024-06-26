#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1000; // Defina o tamanho máximo conforme necessário

struct Ponto {
    int x, y;
};

Ponto pontos[MAX];
Ponto hull[MAX];

int distQuadrado(Ponto p1, Ponto p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int orientacao(Ponto a, Ponto b, Ponto c) {
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (val == 0) return 0; // colinear
    return (val > 0) ? 1 : 2; // horário ou anti-horário
}

void troca(Ponto &p1, Ponto &p2) {
    Ponto temp = p1;
    p1 = p2;
    p2 = temp;
}

int comparar(const void *vp1, const void *vp2) {
   Ponto *p1 = (Ponto *)vp1;
   Ponto *p2 = (Ponto *)vp2;
   int o = orientacao(pontos[0], *p1, *p2);
   if (o == 0)
     return (distQuadrado(pontos[0], *p2) >= distQuadrado(pontos[0], *p1))? -1 : 1;
   return (o == 2)? -1: 1;
}

void fechoConvexo(Ponto pontos[], int n) {
    int ymin = pontos[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = pontos[i].y;
        if ((y < ymin) || (ymin == y && pontos[i].x < pontos[min].x))
            ymin = pontos[i].y, min = i;
    }

    troca(pontos[0], pontos[min]);
    qsort(&pontos[1], n-1, sizeof(Ponto), comparar);

    int m = 1;
    for (int i=1; i<n; i++) {
        while (i < n-1 && orientacao(pontos[0], pontos[i], pontos[i+1]) == 0)
            i++;
        pontos[m] = pontos[i];
        m++;
    }

    if (m < 3) return;

    int k = 0;
    for (int i = 0; i < m; i++) {
        while (k >= 2 && orientacao(hull[k-2], hull[k-1], pontos[i]) != 2)
            k--;
        hull[k] = pontos[i];
        k++;
    }

    double perimetro = 0;
    for (int i = 0; i < k; i++) {
        Ponto p1 = hull[i];
        Ponto p2 = hull[(i + 1) % k];
        perimetro += sqrt(distQuadrado(p1, p2));
    }

    cout << ceil(perimetro) << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pontos[i].x >> pontos[i].y;
    }

    fechoConvexo(pontos, n);

    return 0;
}