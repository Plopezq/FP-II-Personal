// Prueba de evaluación del día 12 de junio de 2020
// Alumno/a: 
// email:  @ucm.es
// Grupo:

// Fíjate que hay 3 sitios donde aparece el comentario  "INTRODUCIR CODIGO"
// Debes cambiar los nombres de los ficheros para las distintas pruebas

#include <iostream>
#include <fstream>
using namespace std;

typedef struct{
	int cont;
	int array[100];
}tLista;

// Prototipos

// Traduce (0/1) booleano a (FALSE/TRUE) del tipo string
string bool2string(bool x);

// Prototipo de la función que se debe implementar
bool buscarNOiguales(const tLista& lista, int posi);
// INTRODUCIR CODIGO

int resuelveCaso() {
	tLista l;
	l.cont = 0;
	int num = 0;
	cin >> num;
	while (num != -1)
	{
		l.array[l.cont] = num;
		l.cont++;
		cin >> num;
	}

	// Llamada a la función implementada
	// INTRODUCIR CODIGO
	int sol = buscarNOiguales(l, 0);
	cout << bool2string(sol) << endl;
	
	return 0;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("4.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	std::ofstream out("1.out");
	auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
	system("PAUSE");
#endif
	return 0;
}

// Implementación de la función recursiva

// INTRODUCIR CODIGO
bool buscarNOiguales(const tLista & lista, int posi) {
	bool solucion = true;
	if (lista.cont == 0 || lista.cont == 1 || posi == lista.cont -1) {
		solucion = true;
	}
	else {
		if (lista.array[posi] == lista.array[posi + 1]) {
			solucion = false;
		}
		else {
			solucion = buscarNOiguales(lista, posi + 1);
		}
	}
	return solucion;
}



// Traduce (0/1) booleano a (FALSE/TRUE) del tipo string
string bool2string(bool x) {
	if (x)
		return "TRUE";
	else
		return "FALSE";
}