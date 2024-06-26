#include <iostream>

using namespace std;

struct Ponto {
    int x, y;
};

bool ccw(Ponto A, Ponto B, Ponto C) {
    return (C.y-A.y) * (B.x-A.x) > (B.y-A.y) * (C.x-A.x);
}

bool cruzam(Ponto A, Ponto B, Ponto C, Ponto D) {
    return (ccw(A,C,D) != ccw(B,C,D)) && (ccw(A,B,C) != ccw(A,B,D));
}

int main() {
    Ponto A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    if(cruzam(A, B, C, D)) {
        cout << "SIM";
    } else {
        cout << "NAO";
    }
    return 0;
}
