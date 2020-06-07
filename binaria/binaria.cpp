#include <iostream>
using namespace std;
#include <fstream>

const int N = 100;
typedef int tArray[N];
typedef struct {
    tArray elementos;
    int cont;
} tLista;

// Devuelve el índice del elemento (0, 1, ...) o -1 si no se encuentra
int buscar(tLista lista, int buscado, int ini, int fin);

int main() {
    tLista lista;
    ifstream archivo;
    int dato;

    lista.cont = 0;
    archivo.open("enteros.txt");
    if (!archivo.is_open()) {
        cout << "No se ha podido abrir el archivo!" << endl;
    }
    else {
        archivo >> dato;
        while ((dato != -1) && (lista.cont < N)) {
            lista.elementos[lista.cont] = dato;
            lista.cont++;
            archivo >> dato;
        }
        archivo.close();
        for (int i = 0; i < lista.cont; i++) {
            cout << lista.elementos[i] << "   ";
        }
        cout << endl;
        int buscado, pos;
        cout << "Valor a buscar: ";
        cin >> buscado;
        pos = buscar(lista, buscado, 0, lista.cont - 1);
        if (pos == -1) {
            cout << "No encontrado!" << endl;
        }
        else {
            cout << "Encontrado en la posición " << pos + 1 << endl;
        }
    }

    return 0;
}

int buscar(tLista lista, int buscado, int ini, int fin) {
    int pos = -1;

    if (ini <= fin) {
        int mitad = (ini + fin) / 2;
        if (buscado == lista.elementos[mitad]) {
            pos = mitad;
        }
        else if (buscado < lista.elementos[mitad]) {
            pos = buscar(lista, buscado, ini, mitad - 1);
        }
        else {
            pos = buscar(lista, buscado, mitad + 1, fin);
        }
    }

    return pos;
}
