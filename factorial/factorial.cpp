#include <iostream>
using namespace std;

long long int factorial(int n);

int main() {
    for (int i = 0; i < 20; i++) {
        cout << factorial(i) << endl;
    }

    return 0;
}

long long int factorial(int n) {
    long long int resultado;

    if (n == 0) {
        resultado = 1;
    }
    else {
        resultado = n * factorial(n - 1);
    }

    return resultado;
}
