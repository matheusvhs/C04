#include <iostream>

using namespace std;

int main(){

int x, y;
int *p, *q;
x = 2;
y = 3;
p = &x;
*p = *p + 1;
cout << *p+y;

return 0;

}