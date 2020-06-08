/*
  Sonia Est�vez Mart�n
  C�digo correspondiente a la explicaci�n de b�squeda binaria recursiva
  que devuelve si se ha encontrado o no el elemento buscado.
  Si no se ha encontrado devuelve la posici�n d�nde se debe insertar.
  Si se encuentra devuelve su posici�n.
  Para probar la funci�n buscar cargamos un fichero con n�meros enteros
  y centinela -1.
*/

#include <iostream>
using namespace std;
#include <fstream>

const int N = 100;
typedef int tArray[N];
typedef struct {
	tArray elementos;
	int cont;
} tLista;

// Devuelve el �ndice del elemento (0, 1, ...) o -1 si no se encuentra
bool buscar(tLista lista, int buscado, int ini, int fin, int& pos);

int main() {
	tLista lista;
	ifstream archivo;
	int dato;

	lista.cont = 0;
	archivo.open("Enteros.txt");
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
	}

	int buscado = 0, pos;
	while (buscado != -1) {
		cout << "Valor a buscar (-1 salir): ";
		cin >> buscado;

		if (buscar(lista, buscado, 0, lista.cont - 1, pos)) {
			cout << "Encontrado en la posici�n " << pos + 1 << endl;
		}
		else {
			cout << "No encontrado, pero estar�a en la posici�n " << pos + 1 << endl;
		}
	}

	return 0;
}

bool buscar(tLista lista, int buscado, int ini, int fin, int& pos) {
	pos = -1;
	bool enc = false;
	int mitad;
	if (ini <= fin && !enc) {
		mitad = (ini + fin) / 2;
		if (buscado == lista.elementos[mitad]) {
			pos = mitad;
			enc = true;
		}
		else if (buscado < lista.elementos[mitad]) {
			enc = buscar(lista, buscado, ini, mitad - 1, pos);
		}
		else {
			enc = buscar(lista, buscado, mitad + 1, fin, pos);
		}
	}
	else {
		if (!enc) {
			pos = ini;
		}
	}
	return enc;
}