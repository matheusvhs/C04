#include <iostream>

using namespace std;

int main(){

int a,b,c;
int *p;
p = &a;
*p = 2;
p=&b;
*p = 3;
c = 0;
c = c+*p;
p = &a;
c = c+*p;

cout << c;

return 0;

}