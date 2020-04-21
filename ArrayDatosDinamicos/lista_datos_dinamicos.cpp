#include <iostream>
using namespace std;
#include "registro.h"
#include "lista.h"

int main() {
   tLista lista;
   bool ok;
   cargar(lista, ok);
   if (ok) {
      mostrar(lista);
      destruir(lista);
   }
  
   return 0; 
}

