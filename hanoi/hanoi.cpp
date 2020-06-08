#include <iostream>
using namespace std;

void hanoi(int n, char origen, char destino, char auxiliar);

int main() {
    int n;

    cout << "Número de torres: ";
    cin >> n;
    hanoi(n, 'A', 'B', 'C');

    return 0;
}

void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n > 0) {
        hanoi(n - 1, origen, auxiliar, destino);
        cout << origen << " --> " << destino << endl;
        hanoi(n - 1, auxiliar, destino, origen);
    }
}

