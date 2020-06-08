/*
  Sonia Estévez Martín
  Códigos correspondientes a las explicaciones de ejercicios recursivos
*/

#include <iostream>
#include <string>
using namespace std;

typedef struct {
    int cont = 0;
    int array[100];
}tLista;

////////////////////////////////////////
// Ejercicios recursivos con números.
////////////////////////////////////////

// Calcula en número de dígitos que tiene un número
int numDigitos(unsigned long long int n);

// Suma los dígitos de un número
int suma(int n);

// Suma de todos los número que van desde 1 hasta n
int sumatorio(int n);

// Invierte un número a
int invertir(int n);

////////////////////////////////////////
// Ejercicios recursivos con listas.
// Recorridos lineales
////////////////////////////////////////

// Mostrar la lista según su orden
void mostrarDirecto(tLista lista, int pos);

// Mostrar la lista en orden inverso
void mostrarInverso(tLista lista, int pos);

// Mostrar los elementos que están en índices pares
void mostrarIndexpares(tLista lista, int pos);

// Sumar los elementos de una lista
int sumar(tLista lista, int pos);

// Mostrar los números pares de una lista
void mostrarPares(tLista lista, int pos);

////////////////////////////////////////
// Ejercicios recursivos con listas.
// Búsquedas lineales
////////////////////////////////////////

// Dice si todos los elementos de la lista son iguales
bool iguales(const tLista& l, int pos);

// Cuantos hay iguales al primero empezando desde el inicio
int cuantosIguales(const tLista& l);
int cuantosIguales2(const tLista& l, int pos, int num);

int main() {

    cout << endl << "    Ejercicios recursivos con números. \n\n";

    int n = 253;
    cout << "N. de dígitos de " << n << " es: " << numDigitos(n) << endl;
    cout << "La suma de los dígitos de " << n << " es: " << suma(n) << endl;
    cout << "El sumatorio desde 1 hasta 10 es: " << sumatorio(10) << endl;
    cout << n << " invertido es: " << invertir(n) << endl;

    cout << endl << "   Ejercicios recursivos con listas.\n";
    cout << "   Recorridos lineales \n\n";

    tLista l;

    for (int i = 0; i < 10; i++) {
        l.array[i] = i + 1;
        l.cont++;
    }

    cout << "Mostrar la lista l en su orden: ";
    mostrarDirecto(l, 0);

    cout << "\nMostrar la lista l en orden inverso: ";
    mostrarInverso(l, 0);

    cout << "\nMostrar los elementos de índice par de la lista l: ";
    mostrarIndexpares(l, 0);

    cout << "\nSumar los elementos de la lista l: " << sumar(l, 0);

    cout << "\nMostrar los números pares de la lista l: ";
    mostrarPares(l, 0);

    cout << endl << endl << "    Ejercicios recursivos con listas. \n";
    cout << "    Búsquedas lineales \n";


    cout << endl;

    tLista lempty, l_1, l_10_distintos, l_10_iguales;

    // l_1 tiene un único elemento
    l_1.array[0] = 1;
    l_1.cont++;


    cout << endl << "¿Todos los elementos de las siguientes listas son iguales? \n";

    cout << "Lista vacía (l_empty): " << iguales(lempty, 0) << endl;
    cout << "Lista unitaria (l_1): " << iguales(l_1, 0) << endl;

    // prueba distintos
    cout << "Lista con 10 elementos (l_10_distintos). ";

    // l_10_distintos tiene 10 elementos
    for (int i = 0; i < 10; i++) {
        if (i < 4)
            l_10_distintos.array[i] = 2;
        else
            l_10_distintos.array[i] = 5;
        l_10_distintos.cont++;
    }

    for (int i = 0; i < 10; i++) {
        cout << l_10_distintos.array[i] << " ";
    }
    cout << "--- " << iguales(l_10_distintos, 0) << endl;

    // prueba iguales
    cout << "Lista con 10 elementos (l_10_iguales). ";

    l_10_iguales.cont = 0;
    for (int i = 0; i < 10; i++) {
        l_10_iguales.array[i] = 2;
        l_10_iguales.cont++;
    }

    for (int i = 0; i < 10; i++) {
        cout << l_10_iguales.array[i] << " ";
    }
    cout << "--- " << iguales(l_10_iguales, 0) << endl;

    cout << "\n ¿Cuantos elementos hay iguales al primero? ";


    cout << "\nLista vacía: " << cuantosIguales(lempty);
    cout << "\nLista unitaria: " << cuantosIguales(l_1);
    cout << "\nLista con 10 elementos distintos: " << cuantosIguales(l_10_distintos);
    cout << "\nLista con 10 elementos iguales: " << cuantosIguales(l_10_iguales);



    return 0;
}

////////////////////////////////////////
// Ejercicios recursivos con números.
////////////////////////////////////////

// Calcula en número de dígitos que tiene un número
int numDigitos(unsigned long long int n) {
    int sol = 0;
    if (n < 10)
        sol = 1;
    else
        sol = 1 + numDigitos(n / 10);
    return sol;
}

// Suma los dígitos de un número
int suma(int n) {
    int sol = 0;
    if (n < 10)
        sol = n;
    else
        sol = n % 10 + suma(n / 10);
    return sol;
}

// Suma de todos los número que van desde 1 hasta n
int sumatorio(int n) {
    int sol = 0;
    if (n == 1)
        sol = 1;
    else
        sol = n + sumatorio(n - 1);
    return sol;
}

// Invierte un número
int invertir(int n) {
    if (n < 10)
        return n;
    else {
        cout << n % 10;
        n = n / 10;
        return invertir(n);
    }
}



////////////////////////////////////////
// Ejercicios recursivos con listas.
// Recorridos lineales
////////////////////////////////////////

// Mostrar la lista según su orden
void mostrarDirecto(tLista lista, int pos) {
    if (pos < lista.cont) {
        cout << lista.array[pos] << " ";
        mostrarDirecto(lista, pos + 1);
    }
}

// Mostrar la lista en orden inverso
void mostrarInverso(tLista lista, int pos) {
    if (pos < lista.cont) {
        mostrarInverso(lista, pos + 1);
        cout << lista.array[pos] << " ";
    }
}

// Mostrar los elementos que están en índices pares
void mostrarIndexpares(tLista lista, int pos) {
    if (pos < lista.cont) {
        cout << lista.array[pos] << " ";
        mostrarIndexpares(lista, pos + 2);
    }
}

// Sumar los elementos de una lista
int sumar(tLista lista, int pos) {
    int resultado = 0;
    if (pos < lista.cont) {
        resultado = lista.array[pos] + sumar(lista, pos + 1);
    }
    return resultado;
}

// Mostrar los números pares de una lista
void mostrarPares(tLista lista, int pos) {
    if (pos < lista.cont) {
        if (lista.array[pos] % 2 == 0) {
            cout << lista.array[pos] << " ";
        }
        mostrarPares(lista, pos + 1);
    }
}

////////////////////////////////////////
// Ejercicios recursivos con listas.
// Búsquedas lineales
////////////////////////////////////////


// Dice si todos los elementos de la lista son iguales
bool iguales(const tLista& l, int pos) {
    bool sol = true;

    if (pos == l.cont)
        sol = true;
    else {
        if ((pos > 0 && l.array[pos] != l.array[pos - 1])) {
            sol = false;
        }
        else {
            sol = iguales(l, pos + 1);
        }
    }
    return sol;
}

// Cuantos hay iguales al primero empezando desde el inicio
int cuantosIguales2(const tLista& l, int pos, int num) {
    int sol = 0;
    if (pos == l.cont)
        sol = 0;
    else {
        if ((l.array[pos] == num)) {
            sol = 1 + cuantosIguales2(l, pos + 1, num);
        }
    }
    return sol;
}

// Si es la lista vacía o la lista unitaria,
// entonces no hay elementos consecutivos al primero
int cuantosIguales(const tLista& l) {
    int sol = 0;
    if (l.cont == 0 || l.cont == 1)
        sol = 0;
    else
        sol = cuantosIguales2(l, 1, l.array[0]);
    return sol;
}


