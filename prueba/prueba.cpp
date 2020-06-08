#include <iostream>
using namespace std;

void func(int n);

int main() {
    func(5);

    return 0;
}

void func(int n) {
    if (n > 0) {
        cout << "Entrando (" << n << ")" << endl; // Código anterior
        func(n - 1);                              // Llamada recursiva
        cout << "Saliendo (" << n << ")" << endl; // Código posterior
    }
}
