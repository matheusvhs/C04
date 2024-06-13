#include <iostream>
#include <math.h>
using namespace std;

// Definindo a estrutura Ponto
typedef struct {
	int x;
	int y;	
} Ponto;

// Função para calcular a área de um triângulo
double area_triangulo(
	Ponto a, 
	Ponto b, 
	Ponto c
){
	// Fórmula para calcular a área de um triângulo usando as coordenadas dos pontos
	return 
		((a.x*b.y) - (a.y*b.x) + 
		(a.y*c.x) - (a.x*c.y) + 
		(b.x*c.y) - (b.y*c.x))/2.0;  
}

// Função para calcular a distância entre dois pontos
double distancia(Ponto p1, Ponto p2)
{
    // Fórmula da distância euclidiana
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y));
}

// Função para determinar a orientação de três pontos
int orientacao(Ponto a, Ponto b, Ponto c){
	double area = area_triangulo(a,b,c);
	if(area > 0){
		return 1; // Retorna 1 se a orientação for anti-horária
	} else if(area < 0){
		return -1; // Retorna -1 se a orientação for horária
	} else {
		return 0; // Retorna 0 se os pontos forem colineares
	}
}

int main() {
    Ponto A, B, C, D;
    cin >> A.x >> A.y; // Lê as coordenadas do ponto A
    cin >> B.x >> B.y; // Lê as coordenadas do ponto B
    cin >> C.x >> C.y; // Lê as coordenadas do ponto C
    cin >> D.x >> D.y; // Lê as coordenadas do ponto D

    int espessura = abs(A.x - B.x); // Calcula a espessura
    int diametro = round(distancia(C, D)); // Calcula o diâmetro
    int altura = abs(A.y - C.y); // Calcula a altura

    cout << espessura << endl; // Imprime a espessura
    cout << diametro << endl; // Imprime o diâmetro
    cout << altura << endl; // Imprime a altura

    return 0;
}
