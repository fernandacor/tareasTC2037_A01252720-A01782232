// Evidencia 2: Actividad Integradora
// Alina Rosas Macedo A01252720 y Fernanda Cantú Ortega A01782232
// 30/11/2023

// Librerías a utilizar
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>

using namespace std;

// Definición de estructuras

// Estructura para almacenar coordenadas (x, y)
struct Coordenada {
    int x, y;
};

// Estructura para representar aristas en el grafo
struct Aristas {
    int inicio, final, weight;
};

// Estructura para representar un grafo
struct Grafo {
    int V;
    vector<Aristas> edges;

    Grafo(int V) : V(V) {}

    // Método para agregar aristas al grafo
    void add_aristas(int inicio, int final, int weight) {
        Aristas edge = {inicio, final, weight};
        edges.push_back(edge);
    }
};

// Función de comparación para ordenar aristas por peso
bool compararAristas(const Aristas &a, const Aristas &b) {
    return a.weight < b.weight;
}

// Estructura para representar una ruta en el grafo
struct Ruta {
    vector<int> path;
    int length;
};

// Función para leer el archivo que contiene la matriz de adyacencia y coordenadas de las centrales
vector<vector<int>> leerArchivo(const string archivo, vector<Coordenada> &centrales) {
    ifstream inputFile(archivo);

    int N;
    inputFile >> N;
    cout << "N: " << N << endl;

    vector<vector<int>> matrizCiudad(N, vector<int>(N));

    // Leer la matriz de adyacencia
    cout << "Matriz de adyacencia: " << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inputFile >> matrizCiudad[i][j];
            cout << matrizCiudad[i][j] << " ";
        }
        cout << endl;
    }

    // Leer las coordenadas de las centrales
    cout << "Coordenadas de las centrales: " << endl;
    for (int i = 0; i < N; ++i) {
        int x, y;
        inputFile >> x >> y;
        centrales.push_back(Coordenada());
        centrales.back().x = x;
        centrales.back().y = y;
        cout << "x: " << x << ", y: " << y << endl;
    }

    return matrizCiudad;
}

// Algoritmo de Kruskal para encontrar el árbol de expansión mínima (MST)
struct minExpTree {
    vector<int> padre, rango;

    minExpTree(int n) {
        padre.resize(n);
        rango.resize(n);

        for (int i = 0; i < n; i++) {
            padre[i] = i;
            rango[i] = 0;
        }
    }

    // Función para encontrar la raíz de un conjunto
    int find(int v) {
        if (v != padre[v])
            padre[v] = find(padre[v]);
        return padre[v];
    }

    // Función para fusionar dos conjuntos
    void merge(int x, int y) {
        int x_raiz = find(x);
        int y_raiz = find(y);

        if (rango[x_raiz] > rango[y_raiz])
            padre[y_raiz] = x_raiz;
        else {
            padre[x_raiz] = y_raiz;
            if (rango[x_raiz] == rango[y_raiz])
                rango[y_raiz]++;
        }
    }
};

// Función para ejecutar el algoritmo de Kruskal y obtener el MST
vector<Aristas> kruskalMST(Grafo grafo) {
    cout << "Parte 1: Kruskal" << endl;
    vector<Aristas> result;
    sort(grafo.edges.begin(), grafo.edges.end(), compararAristas);

    minExpTree ds(grafo.V);

    for (Aristas edge : grafo.edges) {
        int padreInicio = ds.find(edge.inicio);
        int padreFinal = ds.find(edge.final);

        if (padreInicio != padreFinal) {
            result.push_back(edge);
            ds.merge(padreInicio, padreFinal);
        }
    }

    return result;
}

// Función auxiliar para encontrar la ruta más corta utilizando backtracking
void backtracking(vector<vector<int>> &grafo, int start, int current, int visited, Ruta &currentRoute, Ruta &shortestRoute) {
    cout << "Parte 2: Backtracking" << endl;
    if (visited == ((1 << grafo.size()) - 1)) {
        if (grafo[current][start] != 0) {
            currentRoute.length += grafo[current][start];
            currentRoute.path.push_back(start);
            if (currentRoute.length < shortestRoute.length) {
                shortestRoute = currentRoute;
            }
            currentRoute.length -= grafo[current][start];
            currentRoute.path.pop_back();
        }
        return;
    }

    for (int i = 0; i < grafo.size(); ++i) {
        if (!(visited & (1 << i)) && grafo[current][i] != 0) {
            currentRoute.length += grafo[current][i];
            currentRoute.path.push_back(i);
            backtracking(grafo, start, i, visited | (1 << i), currentRoute, shortestRoute);
            currentRoute.length -= grafo[current][i];
            currentRoute.path.pop_back();
        }
    }
}

// Función principal para encontrar la ruta más corta que visita cada colonia exactamente una vez
Ruta findShortestRoute(vector<vector<int>> &grafo) {
    Ruta shortestRoute;
    shortestRoute.length = INT_MAX;

    for (int i = 0; i < grafo.size(); ++i) {
        Ruta currentRoute;
        currentRoute.length = 0;
        currentRoute.path.push_back(i);
        backtracking(grafo, i, i, 1 << i, currentRoute, shortestRoute);
    }

    return shortestRoute;
}

// Función para calcular la distancia euclidiana entre dos puntos
double calcularDistancia(const Coordenada &punto1, const Coordenada &punto2) {
    return sqrt(pow(punto1.x - punto2.x, 2) + pow(punto1.y - punto2.y, 2));
}

// Función para encontrar la central más cercana a una nueva contratación
int encontrarCentralMasCercana(const Coordenada &nuevaContratacion, const vector<Coordenada> &centrales) {
    int indiceCentralMasCercana = -1;
    double distanciaMinima = numeric_limits<double>::max();

    for (int i = 0; i < centrales.size(); ++i) {
        double distancia = calcularDistancia(nuevaContratacion, centrales[i]);
        if (distancia < distanciaMinima) {
            distanciaMinima = distancia;
            indiceCentralMasCercana = i;
        }
    }

    return indiceCentralMasCercana;
}

int main() {
    // Nombre del archivo con la matriz de adyacencias
    string nombreArchivo = "input.txt";
    vector<Coordenada> centrales;
    vector<vector<int>> matrizCiudad = leerArchivo(nombreArchivo, centrales);

    // Verificar si la lectura del archivo fue exitosa
    if (!matrizCiudad.empty()) {
        int numVertices = matrizCiudad.size();
        Grafo G(numVertices);

        // Construir el grafo a partir de la matriz de adyacencias leída
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (matrizCiudad[i][j] != 0) {
                    G.add_aristas(i, j, matrizCiudad[i][j]);
                }
            }
        }

        // Ejecutar el algoritmo de Kruskal
        vector<Aristas> MST = kruskalMST(G);

        // Imprimir el árbol de expansión mínima (MST)
        for (Aristas edge : MST) {
            cout << edge.inicio << " - " << edge.final << " : " << edge.weight << endl;
        }
    }

    // Utilizar la matriz de adyacencia para encontrar la ruta más corta
    vector<vector<int>> matrizAdyacencia = matrizCiudad;
    Ruta shortestRoute = findShortestRoute(matrizAdyacencia);

    // Imprimir la ruta más corta y su longitud
    cout << "Ruta mas corta: ";
    for (int node : shortestRoute.path) {
        cout << node << " ";
    }
    cout << endl;
    cout << "Distancia: " << shortestRoute.length << endl;

    // Encontrar la central más cercana a una nueva contratación
    Coordenada nuevaContratacion = {0, 9};
    int indiceMasCercano = encontrarCentralMasCercana(nuevaContratacion, centrales);

    if (indiceMasCercano != -1) {
        cout << "Central mas cercana a nueva contratacion: " << indiceMasCercano << endl;
        cout << "Coordenadas de central más cercana: (" << centrales[indiceMasCercano].x << ", " << centrales[indiceMasCercano].y << ")" << endl;
    }

    return 0;
}
