#include <iostream>
#include <iomanip>

using namespace std;

struct Aluno {
        float nota1;
        float nota2;
        float nota3;
        float nota4;
        float media;
    };

int main() {
    
    Aluno *aluno = new Aluno;
    cin >> aluno->nota1 >> aluno->nota2 >> aluno->nota3 >> aluno->nota4;
    aluno->media = (aluno->nota1 + aluno->nota2 + aluno->nota3 + aluno->nota4) / 4;
    cout << fixed << setprecision(2) << aluno->media << endl;

    delete aluno;

    return 0;
}