//Matheus Vieira Honorio de Souza
//GES - 525

// Pedras Preciosas - Programação Dinâmica

#include <iostream>

using namespace std;

int knapSack(int W, int wt[], int val[], int n) {
  // `dp[i][w]` armazena o valor máximo que pode ser carregado na mochila
  // usando os primeiros `i` itens e com capacidade máxima de `w`.
  int dp[n + 1][W + 1];

  // Inicialização da matriz `dp`.
  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      if (i == 0 || w == 0) {
        // Se não há itens ou capacidade, o valor é 0.
        dp[i][w] = 0;
      } else if (wt[i - 1] <= w) {
        // Se o item cabe na mochila, escolher entre incluir ou não.
        dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
      } else {
        // Se o item não cabe na mochila, manter o valor anterior.
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  // Retorna o valor máximo que pode ser carregado na mochila.
  return dp[n][W];
}

int main() {

  int n = 5; // Número de itens
  int W = 400; // Capacidade máxima da mochila
  int val[] =  {500, 410, 320, 315}; // Valores dos itens
  int wt[] = {455, 521, 87, 65}; // Pesos dos itens

  // Encontrar o valor máximo que pode ser carregado na mochila.
  int maxValue = knapSack(W, wt, val, n);

  // Exibir o valor máximo.
  cout << "Valor maximo: " << maxValue << endl;

  return 0;
}
