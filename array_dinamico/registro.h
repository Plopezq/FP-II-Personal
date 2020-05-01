#ifndef registro_h
#define registro_h

#include <string>
using namespace std;

// Estructura para los datos de cada registro:
typedef struct {
    int codigo;
    string nombre;
    double valor;
} tRegistro;

typedef tRegistro* tRegPtr;

// Lectura de los datos de un nuevo registro.
tRegistro nuevo();

// Muestra en una línea la información del registro proporcionado.
void mostrar(tRegistro registro);

#endif
