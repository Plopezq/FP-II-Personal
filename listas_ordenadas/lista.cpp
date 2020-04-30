#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <iomanip>

const int N = 20;
typedef struct {
    int codigo;
    string nombre;
    double sueldo;
} tRegistro;
typedef tRegistro tArray[N];
typedef struct {
    tArray registros;
    int cont;
} tLista;

void mostrarDato(int pos, tRegistro registro);
void mostrar(tLista lista);
bool operator>(tRegistro opIzq, tRegistro opDer);
bool operator<(tRegistro opIzq, tRegistro opDer);
tRegistro nuevo();
void insertar(tLista& lista, tRegistro registro, bool& ok);
void eliminar(tLista& lista, int pos, bool& ok); // pos = 1..N
int buscar(tLista lista, string nombre);
void cargar(tLista& lista, bool& ok);
void guardar(tLista lista);
int menu();

int main() {
    tLista lista;
    bool ok;
    int op, pos;
    string nombre;

    cargar(lista, ok);
    if (!ok) {
        cout << "Error al abrir el archivo!" << endl;
    }
    else {
        do {
            mostrar(lista);
            op = menu();
            if (op == 1) {
                tRegistro registro = nuevo();
                insertar(lista, registro, ok);
                if (!ok) {
                    cout << "Error: Lista llena!" << endl;
                }
            }
            else if (op == 2) {
                cout << "Posición: ";
                cin >> pos;
                eliminar(lista, pos, ok);
                if (!ok) {
                    cout << "Error: Posición inexistente!" << endl;
                }
            }
            else if (op == 3) {
                cin.sync();
                cout << "Nombre: ";
                cin >> nombre;
                pos = buscar(lista, nombre);
                if (pos == -1) {
                    cout << "No se ha encontrado!" << endl;
                }
                else {
                    cout << "Encontrado en la posición " << pos << endl;
                }
            }
        } while (op != 0);
        guardar(lista);
    }

    return 0;
}

int menu() {
    cout << endl;
    cout << "1 - Insertar" << endl;
    cout << "2 - Eliminar" << endl;
    cout << "3 - Buscar" << endl;
    cout << "0 - Salir" << endl;
    int op;
    do {
        cout << "Opción: ";
        cin >> op;
    } while ((op < 0) || (op > 3));
    return op;
}

tRegistro nuevo() {
    tRegistro registro;
    cin.sync();
    cout << "Introduce el código: ";
    cin >> registro.codigo;
    cout << "Introduce el nombre: ";
    cin >> registro.nombre;
    cout << "Introduce el sueldo: ";
    cin >> registro.sueldo;
    return registro;
}

void insertar(tLista& lista, tRegistro registro, bool& ok) {
    ok = true;
    if (lista.cont == N) {
        ok = false; // Lista llena
    }
    else {
        int i = 0;
        while ((i < lista.cont) && (lista.registros[i] < registro)) {
            i++;
        }
        // Insertamos en la posición i (primer mayor o igual)
        for (int j = lista.cont; j > i; j--) { // Desplazamos una posición a la derecha
            lista.registros[j] = lista.registros[j - 1];
        }
        lista.registros[i] = registro;
        lista.cont++;
    }
}

void eliminar(tLista& lista, int pos, bool& ok) { // pos = 1, 2, 3, ...
    ok = true;
    if ((pos < 1) || (pos > lista.cont)) {
        ok = false; // Posición inexistente
    }
    else {
        pos--; // Pasamos a índice del array
        for (int i = pos + 1; i < lista.cont; i++) { // Desplazamos una posición a la izquierda
            lista.registros[i - 1] = lista.registros[i];
        }
        lista.cont--;
    }
}

int buscar(tLista lista, string nombre) { // Devuelve 1, 2, 3, ...
// Devuelve -1 si no se ha encontrado
    int ini = 0, fin = lista.cont - 1, mitad;
    bool encontrado = false;
    while ((ini <= fin) && !encontrado) {
        mitad = (ini + fin) / 2; // División entera
        if (nombre == lista.registros[mitad].nombre) {
            encontrado = true;
        }
        else if (nombre < lista.registros[mitad].nombre) {
            fin = mitad - 1;
        }
        else {
            ini = mitad + 1;
        }
    }
    if (encontrado) {
        mitad++; // Pasamos a posición de usuario
    }
    else {
        mitad = -1;
    }
    return mitad;
}

void mostrarDato(int pos, tRegistro registro) {
    cout << setw(3) << pos << ": "
        << setw(10) << registro.codigo
        << setw(20) << registro.nombre
        << setw(12) << fixed << setprecision(2)
        << registro.sueldo << endl;
}

void mostrar(tLista lista) {
    for (int i = 0; i < lista.cont; i++) {
        mostrarDato(i + 1, lista.registros[i]);
    }
}

bool operator>(tRegistro opIzq, tRegistro opDer) {
    return opIzq.nombre > opDer.nombre;
}

bool operator<(tRegistro opIzq, tRegistro opDer) {
    return opIzq.nombre < opDer.nombre;
}

void cargar(tLista& lista, bool& ok) {
    ok = true;
    ifstream archivo;
    lista.cont = 0;
    archivo.open("bd.txt");
    if (!archivo.is_open()) {
        ok = false;
    }
    else {
        tRegistro reg;
        archivo >> reg.codigo;
        while ((lista.cont < N) && (reg.codigo != -1)) {
            archivo >> reg.nombre;
            archivo >> reg.sueldo;
            lista.registros[lista.cont] = reg;
            lista.cont++;
            archivo >> reg.codigo;
        }
        archivo.close();
    }
}

void guardar(tLista lista) {
    ofstream salida;
    salida.open("bd.txt");
    for (int i = 0; i < lista.cont; i++) {
        salida << lista.registros[i].codigo << " "
            << lista.registros[i].nombre << " "
            << lista.registros[i].sueldo << endl;
    }
    salida << -1 << endl;
    salida.close();
}
