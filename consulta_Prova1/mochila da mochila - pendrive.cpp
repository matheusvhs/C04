#include <iostream>
#include <climits>
#include <list>

struct Arquivo {
    int id;
    double tamanho;
};

void ordenar(std::list<Arquivo>& arquivos) {
    for(auto it1 = arquivos.begin(); it1 != arquivos.end(); ++it1) {
        for(auto it2 = std::next(it1); it2 != arquivos.end(); ++it2) {
            if(it1->tamanho > it2->tamanho) {
                std::swap(*it1, *it2);
            }
        }
    }
}

int main() {
    double capacidade = 15.0;
    std::list<Arquivo> arquivos = {{1, 3.0}, {2, 4.3}, {3, 2.1}, {4, 2.5}, {5, 4.7}, {6, 5.9}, {7, 2.2}};

    ordenar(arquivos);

    std::list<int> selecionados;
    double tamanhoAtual = 0.0;

    for (Arquivo arquivo : arquivos) {
        if (tamanhoAtual + arquivo.tamanho <= capacidade) {
            tamanhoAtual += arquivo.tamanho;
            selecionados.push_back(arquivo.id);
        }
    }

    std::cout << "Arquivos selecionados: ";
    for (int id : selecionados) {
        std::cout << id << " ";
    }

    return 0;
}
