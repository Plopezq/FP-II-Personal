#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <cstdlib>

const int N = 100;

typedef struct {
    int elementos[N];
    int cont;
} tLista;

void mezcla(tLista lista1, tLista lista2, tLista& listaM);
// Mezcla las listas ordenadas lista1 y lista2,
// devolviendo listaM como resultado.

// Carga del archivo con ese nombre la lista
void carga(string nombre, tLista& lista, bool& ok);
// Error si el archivo no existe.

void muestra(tLista lista);
// Muestra la lista

int main() {
    tLista lista1, lista2, listaMezclada;
    bool ok;
    string nombreArchivo = "archivo1.txt";

    carga(nombreArchivo, lista1, ok);
    if (!ok) {
        cout << "Error: El archivo " << nombreArchivo << " no existe!" << endl;
    }
    else {
        nombreArchivo = "archivo2.txt";
        carga(nombreArchivo, lista2, ok);
        if (!ok) {
            cout << "Error: El archivo " << nombreArchivo << " no existe!" << endl;
        }
        else {
            cout << "Primera lista:" << endl;
            muestra(lista1);
            cout << "Segunda lista:" << endl;
            muestra(lista2);
            mezcla(lista1, lista2, listaMezclada);
            cout << "Lista con la mezcla:" << endl;
            muestra(listaMezclada);
        }
    }

    return 0;
}

void mezcla(tLista lista1, tLista lista2, tLista& listaM) {
    int pos1 = 0, pos2 = 0;
    listaM.cont = 0;
    while ((pos1 < lista1.cont) && (pos2 < lista2.cont) && (listaM.cont < N)) {
        if (lista1.elementos[pos1] < lista2.elementos[pos2]) {
            listaM.elementos[listaM.cont] = lista1.elementos[pos1];
            pos1++;
        }
        else {
            listaM.elementos[listaM.cont] = lista2.elementos[pos2];
            pos2++;
        }
        listaM.cont++;
    }
    // Pueden quedar datos en alguna de las listas
    if (pos1 < lista1.cont) {
        while ((pos1 < lista1.cont) && (listaM.cont < N)) {
            listaM.elementos[listaM.cont] = lista1.elementos[pos1];
            pos1++;
            listaM.cont++;
        }
    }
    else { // pos2 < lista2.cont
        while ((pos2 < lista2.cont) && (listaM.cont < N)) {
            listaM.elementos[listaM.cont] = lista2.elementos[pos2];
            pos2++;
            listaM.cont++;
        }
    }
}

void carga(string nombre, tLista& lista, bool& ok) {
    ifstream archivo;
    int dato;

    ok = true;
    archivo.open(nombre.c_str());
    if (!archivo.is_open()) {
        ok = false;
    }
    else {
        lista.cont = 0;
        archivo >> dato;
        while ((lista.cont < N) && (dato != -1)) {
            lista.elementos[lista.cont] = dato;
            lista.cont++;
            archivo >> dato;
        }
        archivo.close();
    }
}

void muestra(tLista lista) {
    for (int i = 0; i < lista.cont; i++) {
        cout << lista.elementos[i] << "   ";
    }
    cout << endl;
}

