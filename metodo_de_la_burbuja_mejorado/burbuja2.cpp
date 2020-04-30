#include <iostream>
using namespace std;
#include <fstream>

const int N = 15;
typedef int tLista[N];

int main() {
    tLista lista;
    ifstream archivo;
    archivo.open("burbuja.txt");
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
            //-------------- Método de ordenación -----------------------------
            bool inter = true;
            int i = 0;
            while ((i < N - 1) && inter) {
                // Desde el primer elemento hasta el penúltimo si hay intercambios...
                inter = false;
                for (int j = N - 1; j > i; j--) {
                    // Desde el último hasta el siguiente a i
                    if (lista[j] < lista[j - 1]) {
                        int tmp;
                        tmp = lista[j];
                        lista[j] = lista[j - 1];
                        lista[j - 1] = tmp;
                        inter = true;
                    }
                }
                if (inter) {
                    i++;
                }
            }
            //-----------------------------------------------------------------
            cout << "Despues de ordenar:" << endl;
            for (int i = 0; i < N; i++) {
                cout << lista[i] << "  ";
            }
            cout << endl;
        }
    }

    return 0;
}
