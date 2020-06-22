
// ************************1***************************

// Prueba de evaluación del día 22 de junio de 2020
// Alumno/a: Pablo López MArtín
// email:  pablop14@ucm.es
// Grupo: F

// ****************************************************


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int NF = 6;
const int NC = 12;
typedef int tMatriz[NF][NC];

const int M = 30; //Constante que me dice si un maletin es poco atractivo o no, en funcion de sus usos

// Funcion que lee los datos de entrada y crea la matriz
void cargarMatriz(tMatriz m);

// Funcion que muestra los datos de una matriz
// Esta función se proporciona para ayudar a depurar el código
// No se debe mostrar la matriz en la solución enviada al juez
void mostrarMatriz(tMatriz m);

//AÑADE AQUÍ LOS PROTOTIPOS DE TUS FUNCIONES


//Esta funcion nos dice si un maletin es poco atractivo o no
bool atractivo(const tMatriz matriz, int codMalet);

//Esta función nos devuelve un entero que indica el numero de maletines poco atractivos que hay en esa matriz
int maletinesPocoAtractivos(const tMatriz matriz);


void resuelveCaso() {
    int nf, nc;
    std::cin >> nf >> nc;
    tMatriz m;
    cargarMatriz(m);
            // Muestra la matriz para ver si se ha cargardo bien
            // Después comenta mostrarMatriz para enviar al juez
            //mostrarMatriz(m);
    cout << maletinesPocoAtractivos(m) << endl;


}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    std::ofstream out("sample.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    int numCasos; cin >> numCasos; cin.ignore();
    for (int i = 0; i < numCasos; ++i) { resuelveCaso(); }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    system("PAUSE");
#endif

    return 0;
}


void cargarMatriz(tMatriz m) {
    for (int f = 0; f < NF; f++) {
        for (int c = 0; c < NC; c++) {
            cin >> m[f][c];
        }
    }
}

// Esta función se proporciona para ayudar a depurar el código
// No se debe mostrar la matriz en la solución enviada al juez
void mostrarMatriz(tMatriz m) {
    cout << "MATRIZ" << endl;
    for (int f = 0; f < NF; f++) {
        for (int c = 0; c < NC; c++) {
            cout << m[f][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


//AÑADE AQUÍ LA IMPLEMENTACIÓN DE TUS FUNCIONES

//Esta funcion recibe la matriz y el codigo de un maletin, 
// del que se quiere saber si es atractivo o no 
bool atractivo(const tMatriz matriz, int codMalet) {
    bool atractivo = false;
    int col = 0; //Iterador que usaré para recorrer las columnas (empleados que usan ese maletin)
    int vecesUsado = 0;

    //Mientras no sea atractivo y no hayamos llegado al final de las columnas, 
    // hay que seguir aumentando el numero de veces usado ese maletin
    //Solo lo recorro mientras no me sea atractivo, para ser mas eficientes
    // Por ejemplo, si tras ver dos empleados, el maletin ya es atractivo, no sigo
    while (!atractivo && col < NC ) { 
        vecesUsado +=matriz[codMalet][col]; //Le voy sumando las veces que ha usado cada empleado el maletin
        if (vecesUsado >= M) { //Si se ha usado mas o 30 veces, es atractivo el maletin
            atractivo = true;
        }
        else { 
            col++;
        }
    }
    return atractivo;
}

int maletinesPocoAtractivos(const tMatriz matriz) {
    int numMalAtract = 0; //Numero de maletines atractivos

    //He de recorrer todos los maletines (las filas)
    // Y para cada fila (maletin), llamar a la funcion que me dice si ese maletin es atractivo o no
    // Si es atractivo el maletin, incremento el contador
    for (int mal = 0; mal < NF; mal++) {
        bool isAtract = atractivo(matriz, mal);
        if (isAtract) {
            numMalAtract++;
        }
    }
    return numMalAtract;
}



