#include <iostream>
using namespace std;
#include "registro.h"

int main() {
    const int N = 10;
    tRegistro* p = new tRegistro[N];
    p[0] = nuevo();
    p[1] = nuevo();
    mostrar(p[0]);
    delete[] p;

    return 0;
}