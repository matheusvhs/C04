#include <iostream>

using namespace std;

int main() {
    int N;
    cout << "Digite o tamanho do vetor: ";
    cin >> N;

    int* vetor = new int[N]; // Alocação dinâmica de memória para o vetor

    int* ponteiro = vetor; // Ponteiro apontando para a primeira posição do vetor

    cout << "Digite os elementos do vetor:\n";
    for (int i = 0; i < N; i++) {
        cin >> *ponteiro; // Inserindo o elemento no vetor usando o ponteiro
        ponteiro++; // Movendo o ponteiro para a próxima posição do vetor
    }

    cout << "Conteúdo do vetor:\n";
    ponteiro = vetor; // Reiniciando o ponteiro para percorrer o vetor novamente

    for (int i = 0; i < N; i++) {
        cout << *ponteiro << " "; // Mostrando o conteúdo do vetor usando o ponteiro
        ponteiro++; // Movendo o ponteiro para a próxima posição do vetor
    }

    delete[] vetor; // Liberando a memória alocada para o vetor

    return 0;
}