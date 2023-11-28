// Evidencia 2: Actividad Integradora
// Alina Rosas Macedo A01252720 y Fernanda Cantú Ortega A01782232
// 30/11/2023

//Líbrerias a utilizar
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Leer un archivo de entrada que contiene la información de un grafo representado en forma de una matriz de adyacencia
// con grafos ponderados. El peso de cada arista es la distancia en km entre colonia y colonia, por donde se puede meter cableado
vector<vector<int>> leerArchivo(const string archivo)
{
    ifstream inputFile(archivo);

    int N; // donde N es el número de colonias en la ciudad
    inputFile >> N; // se extrae el dato de entrada del archivo

    vector<vector<int>> matrizCiudad(N, vector<int>(N)); // se crea una matriz de N x N

    // Inicializar la matriz de adyacencia con -1 en todas las entradas
    for (int i = 0; i < N; i++)
    {
        matrizCiudad[i][i] = 0; // Inicializar la diagonal con ceros
    }

    // Llenar la matriz de adyacencia con los datos del archivo
    for (int i = 0; i < N; ++i) {
        int nodoInicial, nodoFinal, peso; 
        inputFile >> nodoInicial >> nodoFinal >> peso; // se extraen los datos del archivo
        matrizCiudad[nodoInicial][nodoFinal]; // se asignan los valores a la matriz de adyacencia
    }

    // Imprimir la matriz de adyacencia
    cout << "Matriz de adyacencia: " << endl;
    for (const auto &fila : matrizCiudad) {
        for (int peso : fila) {
            if (peso == -1) {
                cout << "-1 ";
            } else {
                cout << peso << " ";
            }
        }
        cout << endl;
    }

    return matrizCiudad;
}

// El programa debe desplegar cuál es la forma optima de cablear con fibra optica conectando colonias de tal forma que se
// pueda compartir información entre cuales quiera dos colonias

// Utilizando el algoritmo de Floyd-Warshall
void cableadoOptimo(vector<vector<int>> matrizCiudad, int n)
{
    // Chance este es con floyd-warshall??
    vector<vector<int>> distance = matrizCiudad;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distance[i][k] != -1 && distance[k][j] != -1 && (distance[i][k] + distance[k][j] < distance[i][j] || distance[i][j] == -1)) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (distance[i][j] == -1)
            {
                cout << "-1 ";
            }
            else
            {
                cout << distance[i][j] << " ";
            }
        }
        cout << endl;
    }
    return;
}

// Cuál es la ruta más corta posible que visita cada colonia una vez y al finalizar regresa a la colonia origen?
// El programa debe desplegar la ruta a considerar, tomando en cuenta que la primera ciudad es A, la segunda B, y así
// La empresa quiere conocer el flujo máximo de información del nodo inicial al nodo final. Esto tmbn debe desplegarse

// Utilizando el algoritmo de A*
void shortestRoute()
{
    return;
}

// Teniendo en cuenta la ubicación geográfica de varias centrales a las que se pueden conectar nuevas casas, la empresa quiere
// contar con una forma de decidir, dada una nueva contratación del servicio, cuál es la central geográficamente más cercana
// a esa nueva contratación. No necesariamente hay una central por cada colonia. Se pueden tener colonias sin central, y colonias
// con más de una central
void centralCercana()
{
    return;
}

// Imprimir todo
void imprimir()
{
    return;
}

// Función principal
int main()
{
    leerArchivo("input.txt");
    imprimir();
}

