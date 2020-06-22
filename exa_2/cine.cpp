
// ****************************************************

// Prueba de evaluación del día 12 de junio de 2020
// Alumno/a: Pablo Lopez
// email:  pablop14@ucm.es
// Grupo: F

// ****************************************************


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "cine.h"

void inicializarListaEntradas(tListaPeticiones& listaEntradas) {
	listaEntradas.numEntradasPendientes = 0;
	listaEntradas.capacidad = 20;
	listaEntradas.arrayEntradas = new tEntradas[listaEntradas.capacidad];
}

void inicializarListaPelis(tListaPelis& listaPelis) {
	listaPelis.numPelis = 0;
}

bool cargar(tListaPelis& listaPelis, tListaPeticiones& listaEntradas) {

	string titulo;
	cin >> titulo;

	if (!cin)
		return false;

	while (titulo != "----") {
		listaPelis.arrayPelis[listaPelis.numPelis] = new tPeli;
		listaPelis.arrayPelis[listaPelis.numPelis]->titulo = titulo;
		cin >> listaPelis.arrayPelis[listaPelis.numPelis]->precio;
		cin >> listaPelis.arrayPelis[listaPelis.numPelis]->annyo;
		cin >> listaPelis.arrayPelis[listaPelis.numPelis]->num_disponibles;
		listaPelis.numPelis++;
		cin >> titulo;
	}

	cin >> titulo;

	while (titulo != "0000") {
		if (listaEntradas.numEntradasPendientes == listaEntradas.capacidad)
			ampliar(listaEntradas);
		listaEntradas.arrayEntradas[listaEntradas.numEntradasPendientes].titulo = titulo;
		cin >> listaEntradas.arrayEntradas[listaEntradas.numEntradasPendientes].num_solicitadas;
		listaEntradas.numEntradasPendientes++;
		cin >> titulo;
	}
	return true;
}



void visualizarPelis(const tListaPelis& listaPelis) {
	cout << endl ;
	cout << "   *****   Lista de pelis   *****   " << endl << endl;

	for (int i = 0; i < listaPelis.numPelis; i++) {
		cout << listaPelis.arrayPelis[i]->titulo << " - "
			<< listaPelis.arrayPelis[i]->precio << " euros - "
			<< listaPelis.arrayPelis[i]->annyo << " - "
			<< listaPelis.arrayPelis[i]->num_disponibles << " localidades disponibles." << endl;
	}
	cout << endl;
}


void visualizarPeticiones(const tListaPeticiones& listaEntradas) {

	cout << "   *****   Lista de entradas pendientes por procesar   *****" << endl << endl;

	for (int i = 0; i < listaEntradas.numEntradasPendientes; i++) {
		cout << listaEntradas.arrayEntradas[i].titulo << " - "
			<< listaEntradas.arrayEntradas[i].num_solicitadas << " entradas solicitadas." << endl;
	}
	cout << endl;
}



void ampliar(tListaPeticiones& lista) {

	tEntradas* aux = new tEntradas[2 * lista.capacidad];

	for (int i = 0; i < lista.numEntradasPendientes; i++)
	{
		aux[i] = lista.arrayEntradas[i];
	}

	delete[] lista.arrayEntradas; //OJO! usar [] para vectores din�micos
	lista.arrayEntradas = aux;
	lista.capacidad *= 2;
	aux = nullptr;
}


void procesarEntradas(tListaPelis& peliculas, tListaPeticiones& peticiones, int& coste) {
	int posicion = 0;
	//Las peticiones, son la lista de entradas a procesar
	
	//Recorro la lsta de peticiones para procesarlas
	for (int p = 0; p < peticiones.numEntradasPendientes; p++) {
		posicion = buscarPelicula(peliculas, peticiones.arrayEntradas[p].titulo);

		if(posicion != -1){ //Solo hago los caclulos si la pelicula existe, sino no
			//Solicitan mas entradas de las disponibles, vendo el maximo y ademas elimino la peli del array dinamico
			if (peticiones.arrayEntradas[p].num_solicitadas > peliculas.arrayPelis[posicion]->num_disponibles) {
				//Le sumo su coste al total recaudado
				coste += (peliculas.arrayPelis[posicion]->precio * peliculas.arrayPelis[posicion]->num_disponibles);
				//Proceso la venta de entradas
				peliculas.arrayPelis[posicion]->num_disponibles = 0;
				eliminarPeli(peliculas, posicion);
			}
			else {//Solicitan menos entradas de las disponibles, se las resto
				//Le sumo su coste al total recaudado
				coste += (peliculas.arrayPelis[posicion]->precio * peticiones.arrayEntradas[p].num_solicitadas);
				//Proceso la venta de entradas
				peliculas.arrayPelis[posicion]->num_disponibles -= peticiones.arrayEntradas[p].num_solicitadas;
			}
		}
	}

}
int buscarPelicula(const tListaPelis peliculas, string tituloPelicula) {
	int i = 0;
	bool encontrada = false;
	while (!encontrada && i < peliculas.numPelis) {
		if (peliculas.arrayPelis[i]->titulo == tituloPelicula) {
			encontrada = true;
		}
		else {
			i++;
		}
	}
	if (!encontrada) {
		i = -1;
	}
	return i;
}

void liberarMemoria(tListaPelis& peliculas, tListaPeticiones& peticiones) {
	//Primero libero el array de punteros
	for (int i = 0; i < peliculas.numPelis; i++) {

		// libera la memoria del objeto apuntado por l.arrayPunteros[i]
		delete(peliculas.arrayPelis[i]);

		// Ya no apunta a nada, pues entonces = nullptr
		peliculas.arrayPelis[i] = nullptr;
	}

	// Ya no hay elementos en la lista
	peliculas.numPelis = 0;

	//--------------------------
	
	//Ahora libero el array dinamico
	delete[] peticiones.arrayEntradas;
	peticiones.arrayEntradas = nullptr;

}

//Esta función me sirve para eliminar del array dinamico la pelicula que ya no tenga ninguna entrada disponible
void eliminarPeli(tListaPelis& peliculas, int posicion) {

	//Recorro desde la posicion de la pelicula con 0 entradas a eliminar hasta el final, 
	// y desplazo toda la lista necesaria para no dejar huecos vacios
	for (int z = posicion; z < peliculas.numPelis; z++) {
		swap(peliculas.arrayPelis[z] , peliculas.arrayPelis[z+1]);
	}
	//Disminuyo el numero de peliculas
	peliculas.numPelis--;
}


