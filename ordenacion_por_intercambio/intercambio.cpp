#include <iostream>
using namespace std;
#include <fstream>

const int N = 15;
typedef int tLista[N];

int main() {
    tLista lista;
    ifstream archivo;
    archivo.open("intercambio.txt");
    if (!archivo.is_open()) {
        cout << "Error de apertura de archivo" << endl;
    }
    else {
        int dato;
        int ind = 0;
        archivo >> dato;
        while ((ind < N) && (dato != -1)) { // -1 al final
            lista[ind] = dato;
            ind++;
            archivo >> dato;
        }
        archivo.close();
        if (ind < N) {
            cout << "Pocos datos en el archivo" << endl;
        }
        else {
            cout << "Antes de ordenar:" << endl;
            for (int i = 0; i < N; i++) {
                cout << lista[i] << "  ";
            }
            cout << endl;
            //-------------- M�todo de ordenaci�n ------------------
            for (int i = 0; i < N - 1; i++) {
                // Desde el primer elemento hasta el pen�ltimo
                for (int j = i + 1; j < N; j++) {
                    // Desde i+1 hasta el final
                    if (lista[j] < lista[i]) {
                        int tmp;
                        tmp = lista[i];
                        lista[i] = lista[j];
                        lista[j] = tmp;
                    }
                }
            }
            //------------------------------------------------------
            cout << "Despu�s de ordenar:" << endl;
            for (int i = 0; i < N; i++) {
                cout << lista[i] << "  ";
            }
            cout << endl;
        }
    }

    return 0;
}
