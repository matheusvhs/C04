#include <iostream> 
#include <cmath> 
#include <limits> 

using namespace std; 

int main() { 
    int n=0;
    cin >> n;
    int dist[n][n];
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

          if(i==j){
            dist[i][j]=0;
          }
          else if (i<j){
            cin >> dist[i][j];
          }
          else{
            dist[i][j]=dist[j][i];
          }
            
        }
    }

    bool visitado[n] = {false};
    int percurso[n];
    int custo_total = 0;
    int atual = 0;

    for (int i = 0; i < n; i++) {
        visitado[atual] = true;
        percurso[i] = atual;

        int proximo = -1;
        int min_dist = numeric_limits<int>::max();
        for (int j = 0; j < n; j++) {
            if (!visitado[j] && dist[atual][j] < min_dist) {
                min_dist = dist[atual][j];
                proximo = j;
            }
        }

        if (proximo != -1) {
            custo_total += min_dist;
            atual = proximo;
        }
    }

    cout << "Percurso: ";
    for (int i = 0; i < n; i++) {

          cout << percurso[i];
        
        if (i!=n-1)
        {
          cout << " -> ";
        }
        
    }
    cout << "\nMenor custo: " << custo_total << endl;

    return 0;
}