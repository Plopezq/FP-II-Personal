#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>

const int N = 15;
typedef struct {
    int codigo;
    string nombre;
    double sueldo;
} tDato;
typedef tDato tArray[N];
typedef struct {
    tArray datos;
    int cont;
} tLista;

void mostrar(tLista lista);
bool operator>(tDato opIzq, tDato opDer);

int main() {
    tLista lista;
    lista.cont = 0;
    ifstream archivo;
    archivo.open("datos.txt");
    if (!archivo.is_open()) {
        cout << "Error de apertura del archivo" << endl;
    }
    else {
        tDato dato;
        archivo >> dato.codigo;
        while ((lista.cont < N) && (dato.codigo != -1)) {
            archivo >> dato.nombre >> dato.sueldo;
            lista.datos[lista.cont] = dato;
            lista.cont++;
            archivo >> dato.codigo;
        }
        archivo.close();
        cout << "Antes de ordenar:" << endl;
        mostrar(lista);
        for (int i = 1; i < lista.cont; i++) {
            // Desde el segundo elemento hasta el último
            int pos = i;
            while ((pos > 0) && (lista.datos[pos - 1] > lista.datos[pos])) {
                // Mientras no se llegue al principio y el anterior sea mayor
                tDato tmp;
                tmp = lista.datos[pos];
                lista.datos[pos] = lista.datos[pos - 1];
                lista.datos[pos - 1] = tmp;
                pos--;
            }
        }
        cout << "Después de ordenar:" << endl;
        mostrar(lista);
    }

    return 0;
}

void mostrar(tLista lista) {
    for (int i = 0; i < lista.cont; i++) {
        cout << setw(10)
            << lista.datos[i].codigo
            << setw(20)
            << lista.datos[i].nombre
            << setw(12)
            << fixed
            << setprecision(2)
            << lista.datos[i].sueldo
            << endl;
    }
}

bool operator>(tDato opIzq, tDato opDer) {
    return opIzq.nombre > opDer.nombre;
}
