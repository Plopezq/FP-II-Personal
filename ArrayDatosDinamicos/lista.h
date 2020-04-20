#ifndef lista_h
#define lista_h

#include "registro.h"

const int N = 1000;

// Array de punteros a registros:
typedef tRegPtr tArray[N];

// Lista: array y contador
typedef struct {
   tArray registros;
   int cont;
} tLista;

// Constante global con el nombre del archivo de base de datos:
const string BD = "bd.txt";

// Muestra la lista completa.
void mostrar(const tLista &lista);

// Inserción del registro proporcionado en la lista.
// Devuelve true si se ha podido y false si la lista está llena.
void insertar(tLista &lista, tRegistro registro, bool &ok);

// Eliminación del registro con el código indicado.
// Devuelve true si se ha podido y false si no está.
void eliminar(tLista &lista, int code, bool &ok);

// Localiza el registro con ese nombre.
// Devuelve el índice, o -1 si no se encuentra.
int buscar(const tLista &lista, int code);

// Carga los datos del archivo de base de datos en la lista.
void cargar(tLista &lista, bool &ok);

// Guarda los datos de la lista en el archivo de base de datos.
void guardar(const tLista &lista);

// Destruye todas las variables dinámicas.
void destruir(tLista &lista);

#endif
