#include <iostream>
using namespace std;
#include <fstream>

const int N = 100;
typedef int tArray[N];
typedef struct {
    tArray elementos;
    int cont;
} tLista;

int buscar(tLista lista, int buscado);

int main() {
    tLista lista;
    lista.cont = 0;
    ifstream archivo;
    archivo.open("ordenados.txt"); // Existe y es correcto
    int dato;
    archivo >> dato;
    while ((lista.cont < N) && (dato != -1)) {
        lista.elementos[lista.cont] = dato;
        lista.cont++;
        archivo >> dato;
    }
    archivo.close();
    for (int i = 0; i < lista.cont; i++) {
        cout << lista.elementos[i] << "  ";
    }
    cout << endl;
    int buscado, pos;
    cout << "Valor a buscar: ";
    cin >> buscado;
    pos = buscar(lista, buscado);
    if (pos != -1) {
        cout << "Encontrado en la posición " << pos + 1 << endl;
    }
    else {
        cout << "No encontrado!" << endl;
    }

    return 0;
}

int buscar(tLista lista, int buscado) {
    int pos = -1, ini = 0, fin = lista.cont - 1, mitad;
    bool encontrado = false;

    while ((ini <= fin) && !encontrado) {
        mitad = (ini + fin) / 2; // División entera
        if (buscado == lista.elementos[mitad]) {
            encontrado = true;
        }
        else if (buscado < lista.elementos[mitad]) {
            fin = mitad - 1;
        }
        else {
            ini = mitad + 1;
        }
    }
    if (encontrado) {
        pos = mitad;
    }

    return pos;
}
