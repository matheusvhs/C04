#include <iostream>
#include <iomanip>

using namespace std;

struct Pessoa {
    float notas[4];
    float media;
};

int main() {
    int numPessoas;
    cout << "Digite o número de pessoas: ";
    cin >> numPessoas;

    Pessoa* pessoas = new Pessoa[numPessoas];

    for (int i = 0; i < numPessoas; i++) {
        cout << "Digite as 4 notas da pessoa " << i + 1 << ": ";
        for (int j = 0; j < 4; j++) {
            cin >> pessoas[i].notas[j];
        }
    }

    float mediaTurma = 0.0;
    for (int i = 0; i < numPessoas; i++) {
        float somaNotas = 0.0;
        for (int j = 0; j < 4; j++) {
            somaNotas += pessoas[i].notas[j];
        }
        pessoas[i].media = somaNotas / 4;
        mediaTurma += pessoas[i].media;
    }

    mediaTurma /= numPessoas;

    cout << "Média da turma: " << fixed << setprecision(2) << mediaTurma << endl;

    delete[] pessoas;

    return 0;
}