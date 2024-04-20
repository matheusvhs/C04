#include <iostream>

using namespace std;

int main(){

int *p;
int x[10];
p = x;
cout << (int)p;
p = &x[2];
cout << (int)p;

// Se a saída do primeiro cout foi 10, qual será o valor mostrado pelo segundo cout?

/*O valor mostrado pelo segundo `cout` será 10 mais o tamanho de dois inteiros. 
Isso ocorre porque `p` é um ponteiro para um inteiro e quando você faz `p = &x[2];`,
você está fazendo `p` apontar para o terceiro elemento do array `x`. 
Como cada inteiro geralmente tem o tamanho de 4 bytes (isso pode variar dependendo do sistema),
o endereço do terceiro elemento será o endereço inicial do array (que é 10 neste caso) mais o tamanho de dois inteiros.
Portanto, se o tamanho de um inteiro for 4 bytes, a saída será 18.
*/

return 0;

}