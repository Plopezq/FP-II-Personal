#include<iostream>
#include<stdio.h>
using namespace std;

int main() {

	
	int i = 3;
	cout << &i << endl;
	
	int* punt1; //Creo un puntero
	punt1 = &i; // Que apunte a donde este i en memoria

	int* punt2;
	punt2 = NULL;
	punt2 = punt1;

	cout << i << endl;
	cout << *punt1 << endl;
	cout << *punt2 << endl;
	

	// --------------------------------------

	
	typedef struct {
		int codigo;
		string nombre;
		double sueldo;
	}tRegistro;

	tRegistro registro;
	registro.codigo = 123;
	registro.nombre = "Pablo";

	tRegistro* puntero = &registro;
	cout << puntero->codigo << endl;
	
	

	// -------------------------------------

	//USO DE MEMORIA DINÁMICA
	
	int* p; //Creo puntero
	p = new int[10]; //Le doy una dirección VALIDA a ese puntero

	p[0] = 0;
	p[1] = 1;

	int* p2;
	p2 = new int;
	*p2 = 15;
	//*p = 10;


	cout << p[0] << endl; 
	cout << p[3] << endl;



	return 0;
}