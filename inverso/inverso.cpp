#include <iostream>
using namespace std;
#include <fstream>

const int N = 100;
typedef int tArray[N];
typedef struct {
    tArray elementos;
    int cont;
} tLista;

void mostrar(tLista lista, int pos);

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
        mostrar(lista, 0);
    }
    return 0;
}

void mostrar(tLista lista, int pos) {
    if (pos < lista.cont) {
        mostrar(lista, pos + 1);
        cout << lista.elementos[pos] << endl;
    }
}
