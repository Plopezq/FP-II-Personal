#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include "lista.h"

void insertar(tLista &lista, tRegistro registro, bool &ok) {
   ok = true;
   if (lista.cont == N) {
      ok = false; // Lista llena
   }
   else {
      lista.registros[lista.cont] = new tRegistro(registro);
      lista.cont++;
   }
}

void eliminar(tLista &lista, int code, bool &ok) {
   ok = true;
   int ind = buscar(lista, code);
   if (ind == -1) {
      ok = false;
   }
   else {
      delete lista.registros[ind];
      for (int i = ind + 1; i < lista.cont; i++) { // Desplazamos a la izquierda
         lista.registros[i-1] = lista.registros[i];
      }
      lista.cont--;
   }
}

int buscar(const tLista &lista, int code) {
// Devuelve el índice o -1 si no se ha encontrado
   int ind = 0;
   bool encontrado = false;
   while ((ind < lista.cont) && !encontrado) {
      if (lista.registros[ind]->codigo == code) {
         encontrado = true;
      }
      else {
         ind++;
      }
   }
   if (!encontrado) {
      ind = -1;
   }
   return ind;
}

void mostrar(const tLista &lista) {
   cout << endl
        << "Elementos de la lista:" << endl
        << "--------------------" << endl;
   for (int i = 0; i < lista.cont; i++) {
      mostrar(*lista.registros[i]);
   }
}

void cargar(tLista &lista, bool &ok) {
   ifstream archivo;
   char aux;
   ok = true;
   archivo.open(BD.c_str());
   if (!archivo.is_open()) {
      ok = false;
   }
   else {
      tRegistro registro;
      lista.cont = 0;
      archivo >> registro.codigo;
      while ((registro.codigo != -1) && (lista.cont < N)) {
         archivo >> registro.valor;
         archivo.get(aux); // Salta el espacio
         getline(archivo, registro.nombre);
         lista.registros[lista.cont] = new tRegistro(registro);
         lista.cont++;
         archivo >> registro.codigo;
      }
      archivo.close();
   }
} 

void guardar(const tLista &lista) {
   ofstream archivo;
   archivo.open(BD.c_str());
   for (int i = 0; i < lista.cont; i++) {
      archivo << lista.registros[i]->codigo << " ";
      archivo << lista.registros[i]->valor << " ";
      archivo << lista.registros[i]->nombre << endl;
   }
   archivo << -1 << endl;
   archivo.close();
}

void destruir(tLista &lista) {
   for (int i = 0; i < lista.cont; i++) {
      delete lista.registros[i];
   }
   lista.cont = 0;
}
