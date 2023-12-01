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


int main() {
    string nombreArchivo = "grafo.txt"; // Nombre del archivo con la matriz de adyacencias
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

    return 0;
}
