#include <iostream>
using namespace std;
#include <fstream>

const int N = 15;
typedef int tLista[N];

int main() {
   tLista lista;
   ifstream archivo;
   archivo.open("seleccion.txt");
   if (!archivo.is_open()) {
      cout << "Error de apertura de archivo" << endl;
   }
   else {
      int dato;
      int ind = 0;
      archivo >> dato;
      while ((ind < N) && (dato != -1)) { // -1 al final
         lista[ind] = dato;
         ind++;
         archivo >> dato;
      }
      archivo.close();
      if (ind < N) {
         cout << "Pocos datos en el archivo" << endl;
      }
      else {
         cout << "Antes de ordenar:" << endl;
         for (int i = 0; i < N; i++) {
            cout << lista[i] << "  ";
         }
         cout << endl;
         //-------------- Método de ordenación ------------------
         for (int i = 0; i < N - 1; i++) {
         // Desde el primer elemento hasta el penúltimo
            int menor = i;
            for (int j = i + 1; j < N; j++) {
            // Desde i+1 hasta el final
               if (lista[j] < lista[menor]) {
                  menor = j;
               }
            }
            if (menor > i) {
               int tmp;
               tmp = lista[i];
               lista[i] = lista[menor];
               lista[menor] = tmp;
            }
         }
         //------------------------------------------------------
         cout << "Después de ordenar:" << endl;
         for (int i = 0; i < N; i++) {
            cout << lista[i] << "  ";
         }
         cout << endl;
      }
   }
  
   return 0;
}
