#include<iostream>
#include<stdio.h>
using namespace std;

int main() {

	/*
	int i = 3;
	cout << &i << endl;

	int* punt1; //Creo un puntero
	punt1 = &i; // Que apunte a donde apunta i

	int* punt2;
	punt2 = NULL;
	punt2 = punt1;

	cout << *punt1 << endl;
	cout << *punt2 << endl;
	*/

	// --------------------------------------

	/*
	typedef struct {
		int codigo;
		string nombre;
		double sueldo;
	} tRegistro;

	tRegistro registro;
	registro.codigo = 123;
	registro.nombre = "Pablo";

	tRegistro* puntero = &registro;
	cout << puntero->codigo << endl;
	*/

	// -------------------------------------

	//USO DE MEMORIA DINÁMICA

	int* p; //Creo puntero
	p = new int; //Le doy una dirección VALIDA a ese puntero
	*p = 10;


	int* p2 = new int(21); //Lo mismo de antes, pero con una instruccion

	cout << *p<< endl; 
	cout << *p2 << endl;




	return 0;
}