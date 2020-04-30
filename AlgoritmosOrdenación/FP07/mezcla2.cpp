#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <cstdlib>

// Mezcla las listas ordenadas en los archivos nombre1 y nombre2,
// creando el achivo nombreM con la mezcla.
// Devuelve false en ok si algún archivo no existe.
void mezcla(string nombre1, string nombre2, string nombreM, bool &ok);

// Muestra el contenido del archivo con ese nombre
// Si no existe el archivo no muestra nada
void muestra(string nombre);

int main() {
   string nombre1 = "archivo1.txt", nombre2 = "archivo2.txt", nombreMezclada = "mezcla.txt";
   bool ok;
   
   cout << "Primer archivo:" << endl;
   muestra(nombre1);
   cout << "Segundo archivo:" << endl;
   muestra(nombre2);
   mezcla(nombre1, nombre2, nombreMezclada, ok);
   cout << "Archivo con la mezcla:" << endl;
   if (ok) {
      muestra(nombreMezclada);
   }
   
   return 0;
}

void mezcla(string nombre1, string nombre2, string nombreM, bool &ok) {
   ifstream archivo1, archivo2;
   ofstream mezcla;
   
   ok = true;
   archivo1.open(nombre1.c_str());
   if (!archivo1.is_open()) {
      ok = false;
   }
   else {
      archivo2.open(nombre2.c_str());
      if (!archivo2.is_open()) {
         ok = false;
      }
      else {
         mezcla.open(nombreM.c_str());
         int dato1, dato2;
         archivo1 >> dato1;
         archivo2 >> dato2;
         while ((dato1 != -1) && (dato2 != -1)) {
         // Mientras quede algo en ambos archivos
            if (dato1 < dato2) {
               mezcla << dato1 << endl;
               archivo1 >> dato1;
            }
            else {
               mezcla << dato2 << endl;
               archivo2 >> dato2;
            }
         }
         // Uno de los dos archivos se ha acabado
         if (dato1 != -1) { // Quedan en el primer archivo
            while (dato1 != -1) {
               mezcla << dato1 << endl;
               archivo1 >> dato1;
            }
         }
         else { // Quedan en el segundo archivo
            while (dato2 != -1) {
               mezcla << dato2 << endl;
               archivo2 >> dato2;
            }
         }
         archivo2.close();
         mezcla << -1 << endl;
         mezcla.close();
      }
      archivo1.close();
   }
}

void muestra(string nombre) {
   ifstream archivo;

   archivo.open(nombre.c_str());
   if (archivo.is_open()) {
      int dato;
      archivo >> dato;
      while (dato != -1) {
         cout << dato << "   ";
         archivo >> dato;
      }
      cout << endl;
      archivo.close();
   }
}

