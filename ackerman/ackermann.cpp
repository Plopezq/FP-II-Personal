#include <iostream>
using namespace std;

int ackermann(int m, int n);

int main() {
    int m, n;
    cout << "M = ";
    cin >> m;
    cout << "N = ";
    cin >> n;
    cout << ackermann(m, n) << endl;

    return 0;
}

int ackermann(int m, int n) {
    int resultado;

    if (m == 0) {
        resultado = n + 1;
    }
    else if (n == 0) {
        resultado = ackermann(m - 1, 1);
    }
    else {
        resultado = ackermann(m - 1, ackermann(m, n - 1));
    }

    return resultado;
}