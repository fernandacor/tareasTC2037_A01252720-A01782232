// Evidencia 2: Actividad Integradora
// Alina Rosas Macedo A01252720 y Fernanda Cantú Ortega A01782232
// 30/11/2023

//Líbrerias a utilizar
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Coordenada {
    int x, y;
};

vector<vector<int> > leerArchivo(const string archivo, vector<Coordenada> &centrales) {
    ifstream inputFile(archivo);

    int N;
    inputFile >> N;
    cout << "N: " << N << endl;

    vector<vector<int> > matrizCiudad(N, vector<int>(N));

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

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V;
    vector<Edge> edges;

    Graph(int V) : V(V) {}

    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }
};

// Algoritmo de Kruskal para encontrar el árbol de expansión mínima (MST)
struct DisjointSets {
    vector<int> parent, rank;

    DisjointSets(int n) {
        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int v) {
        if (v != parent[v])
            parent[v] = find(parent[v]);
        return parent[v];
    }

    void merge(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);

        if (rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else {
            parent[xRoot] = yRoot;
            if (rank[xRoot] == rank[yRoot])
                rank[yRoot]++;
        }
    }
};

bool compararAristas(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

vector<Edge> kruskalMST(Graph graph) {
    cout << "Parte 1: Kruskal" << endl;
     vector<Edge> result;
    sort(graph.edges.begin(), graph.edges.end(), compararAristas);

    DisjointSets ds(graph.V);

    for (Edge edge : graph.edges) {
        int srcParent = ds.find(edge.src);
        int destParent = ds.find(edge.dest);

        if (srcParent != destParent) {
            result.push_back(edge);
            ds.merge(srcParent, destParent);
        }
    }

    return result;
}

struct Route {
    vector<int> path;
    int length;
};

// Función auxiliar para encontrar la ruta más corta utilizando backtracking
void backtracking(vector<vector<int> >& graph, int start, int current, int visited, Route& currentRoute, Route& shortestRoute) {
    if (visited == ((1 << graph.size()) - 1)) {
        if (graph[current][start] != 0) {
            currentRoute.length += graph[current][start];
            currentRoute.path.push_back(start);
            if (currentRoute.length < shortestRoute.length) {
                shortestRoute = currentRoute;
            }
            currentRoute.length -= graph[current][start];
            currentRoute.path.pop_back();
        }
        return;
    }

    for (int i = 0; i < graph.size(); ++i) {
        if (!(visited & (1 << i)) && graph[current][i] != 0) {
            currentRoute.length += graph[current][i];
            currentRoute.path.push_back(i);
            backtracking(graph, start, i, visited | (1 << i), currentRoute, shortestRoute);
            currentRoute.length -= graph[current][i];
            currentRoute.path.pop_back();
        }
    }
}

// Función principal para encontrar la ruta más corta que visita cada colonia exactamente una vez
Route findShortestRoute(vector<vector<int> >& graph) {
    Route shortestRoute;
    shortestRoute.length = INT_MAX;

    for (int i = 0; i < graph.size(); ++i) {
        Route currentRoute;
        currentRoute.length = 0;
        currentRoute.path.push_back(i);
        backtracking(graph, i, i, 1 << i, currentRoute, shortestRoute);
    }

    return shortestRoute;
}

// Función para calcular la distancia euclidiana entre dos puntos
double calcularDistancia(const Coordenada& punto1, const Coordenada& punto2) {
    return sqrt(pow(punto1.x - punto2.x, 2) + pow(punto1.y - punto2.y, 2));
}

// Función para encontrar la central más cercana a una nueva contratación
int encontrarCentralMasCercana(const Coordenada& nuevaContratacion, const vector<Coordenada>& centrales) {
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
    string nombreArchivo = "input.txt"; // Nombre del archivo con la matriz de adyacencias
    vector<Coordenada> centrales;
    vector<vector<int> > matrizCiudad = leerArchivo(nombreArchivo, centrales);

    // Verificar si la lectura del archivo fue exitosa
    if (!matrizCiudad.empty()) {
        int numVertices = matrizCiudad.size();
        Graph graph(numVertices);

        // Construir el grafo a partir de la matriz de adyacencias leída
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (matrizCiudad[i][j] != 0) { // Si hay una arista
                    graph.addEdge(i, j, matrizCiudad[i][j]); // Agregar la arista al grafo
                }
            }
        }

        // Ejecutar el algoritmo de Kruskal
        vector<Edge> MST = kruskalMST(graph);

        // Imprimir el árbol de expansión mínima (MST)
        for (Edge edge : MST) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
        }

    }

    vector<vector<int> > adjacencyMatrix = matrizCiudad; // Usa tu matriz de adyacencia aquí

    Route shortestRoute = findShortestRoute(adjacencyMatrix);

    cout << "Ruta más corta: ";
    for (int node : shortestRoute.path) {
        cout << node << " " << endl;
    }
    cout << "Distancia: " << shortestRoute.length << endl;

    // Encontrar la central más cercana
    Coordenada nuevaContratacion = {0, 9};

    int indiceMasCercano = encontrarCentralMasCercana(nuevaContratacion, centrales);

    if (indiceMasCercano != -1) {
        cout << "La central más cercana a la nueva contratación está en el índice: " << indiceMasCercano << endl;
        cout << "Coordenadas de la central más cercana: (" << centrales[indiceMasCercano].x << ", " << centrales[indiceMasCercano].y << ")" << endl;
    } else {
        cout << "No se encontró una central cercana." << endl;
    }


    return 0;
}
