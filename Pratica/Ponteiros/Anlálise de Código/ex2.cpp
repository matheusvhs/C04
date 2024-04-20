#include <iostream>

using namespace std;

int main(){

float x[3];
float y;
float *p;
y = 4;
p = &y;
for(int i=0;i<3;i++){
    x[i] = *p*i;
    cout << x[i];

return 0;
}