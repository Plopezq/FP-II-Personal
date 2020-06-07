#include <iostream>
using namespace std;

int fibonacci(int n);

int main() {
    for (int i = 0; i < 20; i++) {
        cout << fibonacci(i) << endl;
    }

    return 0;
}

int fibonacci(int n) {
    int resultado;

    if (n == 0) {
        resultado = 0;
    }
    else if (n == 1) {
        resultado = 1;
    }
    else {
        resultado = fibonacci(n - 1) + fibonacci(n - 2);
    }

    return resultado;
}
