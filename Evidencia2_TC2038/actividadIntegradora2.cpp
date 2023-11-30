// Evidencia 2: Actividad Integradora
// Alina Rosas Macedo A01252720 y Fernanda Cantú Ortega A01782232
// 30/11/2023

//Líbrerias a utilizar
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>

using namespace std;

struct coordenadas { int x, y;};

vector<vector<int>> matrizCiudad;

// Leer un archivo de entrada que contiene la información de un grafo representado en forma de una matriz de adyacencia
// con grafos ponderados. El peso de cada arista es la distancia en km entre colonia y colonia, por donde se puede meter cableado
vector<vector<int>> leerArchivo(const string archivo, vector<coordenadas> &centrales)
{
    ifstream inputFile(archivo);

    int N;
    inputFile >> N;
    cout << "N: " << N << endl;

    vector<vector<int>> matrizCiudad(N, vector<int>(N));

    // Leer la matriz de adyacencia
    cout << "Matriz de adyacencia: " << endl;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            inputFile >> matrizCiudad[i][j];
            cout << matrizCiudad[i][j] << " ";
        }
        cout << endl;
    }


    // Leer las coordenadas de las centrales
    cout << "Coordenadas de las centrales: " << endl;
    for (int i = 0; i < N; ++i)
    {
        int x, y;
        inputFile >> x >> y;
        centrales.push_back({x, y});
        cout <<"x: " << x << ", y: " << y << endl;
    }

    return matrizCiudad;
}

// El programa debe desplegar cuál es la forma optima de cablear con fibra optica conectando colonias de tal forma que se
// pueda compartir información entre cuales quiera dos colonias

// Utilizando el algoritmo de kruskal
void cableadoOptimo(vector<vector<int>> matrizCiudad, int n)
{
    return;
}

// Cuál es la ruta más corta posible que visita cada colonia una vez y al finalizar regresa a la colonia origen?
// El programa debe desplegar la ruta a considerar, tomando en cuenta que la primera ciudad es A, la segunda B, y así
// La empresa quiere conocer el flujo máximo de información del nodo inicial al nodo final. Esto tmbn debe desplegarse

// Utilizando branch and bound
vector<pair<int, int>> branchAndBound(vector<vector<int>> &matrizCiudad, int x, int y, int goal_x, int goal_y)
{
    // Definir las posibles direcciones (derecha, izquierda, arriba, abajo)
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    // Encontrar un camino
    int M = matrizCiudad.size();
    int N = matrizCiudad[0].size();

    vector<vector<int>> solucionBranchAndBound(M, vector<int>(N));

    priority_queue<pair<int, pair<int, int>>> pq;

    vector<pair<int, int>> ruta;


    int distanciaFaltante = sqrt((x - goal_x) * (x - goal_x) + (y - goal_y) * (y - goal_y));
    int estimadorInicial = distanciaFaltante;

    pq.push({-estimadorInicial, {x, y}});

    while (!pq.empty()) 
    {
        // Obtener las coordenadas actuales
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        int cost = -pq.top().first;
        pq.pop();

        // Marcar la casilla actual como visitada
        solucionBranchAndBound[i][j] = 1;

        ruta.push_back({i, j});

        if (i == goal_x && j == goal_y)
        {
            return ruta;
        }

        for (int dir = 0; dir < 4; dir++) 
        {
            int ni = i + dx[dir];
            int nj = j + dy[dir];

            // Verificar si la nueva casilla es válida
            if (ni >= 0 && ni < M && nj >= 0 && nj < N && matrizCiudad[ni][nj] == 1 && solucionBranchAndBound[ni][nj] == 0) 
            {
                int nuevoCosto = cost + 1;
                // Agregar la casilla a la cola para explorarla más tarde
                pq.push({-nuevoCosto, {ni, nj}});
            }
        }
    }
    return ruta;
}

// Teniendo en cuenta la ubicación geográfica de varias centrales a las que se pueden conectar nuevas casas, la empresa quiere
// contar con una forma de decidir, dada una nueva contratación del servicio, cuál es la central geográficamente más cercana
// a esa nueva contratación. No necesariamente hay una central por cada colonia. Se pueden tener colonias sin central, y colonias
// con más de una central

// utilizando dijkstra
void centralCercana(vector<coordenadas> &centrales, const coordenadas &nuevaContratacion, int n)
{
    vector<int> distancia(n, INT_MAX);
    vector<bool> visitado(n, false);

    distancia[nuevaContratacion.x] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visitado[j] && (u == -1 || distancia[j] < distancia[u]))
            {
                u = j;
            }
        }

        visitado[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (matrizCiudad[u][v] != -1 && distancia[u] != INT_MAX && distancia[u] + matrizCiudad[u][v] < distancia[v])
            {
                distancia[v] = distancia[u] + matrizCiudad[u][v];
            }
        }
    }

    int centralMasCercana = min_element(distancia.begin(), distancia.end()) - distancia.begin();

    cout << "La central más cercana a la nueva contratación es: " << centralMasCercana << endl;

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
    vector<coordenadas> centrales; // Declare and initialize the vector "centrales"
    leerArchivo("input.txt", centrales);
    int start_x = 0, start_y = 0, goal_x = 3, goal_y = 3;
    vector<pair<int, int>> ruta = branchAndBound(matrizCiudad, start_x, start_y, goal_x, goal_y);
    coordenadas nuevaContratacion = {2, 2};
    cout << "Nueva contratación: " << nuevaContratacion.x << ", " << nuevaContratacion.y << endl;
    centralCercana(centrales, nuevaContratacion, matrizCiudad.size());
}

