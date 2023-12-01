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

int start_x = 0; // Coordenada x de inicio
int start_y = 0; // Coordenada y de inicio
int goal_x = 3;  // Coordenada x de destino
int goal_y = 3;  // Coordenada y de destino

// Utilizando branch and bound
vector<pair<int, int> > branchAndBound(vector<vector<int> > &matrizCiudad, int x, int y, int goal_x, int goal_y)
{
    // Definir las posibles direcciones (derecha, izquierda, arriba, abajo)
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    // Encontrar un camino
    int M = matrizCiudad.size();
    int N = matrizCiudad[0].size();

    vector<vector<int> > solucionBranchAndBound(M, vector<int>(N));

    priority_queue<pair<int, pair<int, int> > > pq;

    vector<pair<int, int> > ruta;


    int distanciaFaltante = sqrt((x - goal_x) * (x - goal_x) + (y - goal_y) * (y - goal_y));
    int estimadorInicial = distanciaFaltante;

    pq.push(make_pair(-estimadorInicial, make_pair(x, y)));

    while (!pq.empty()) 
    {
        // Obtener las coordenadas actuales
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        int cost = -pq.top().first;
        pq.pop();

        // Marcar la casilla actual como visitada
        solucionBranchAndBound[i][j] = 1;

        ruta.push_back(make_pair(i, j));

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
                pq.push(make_pair(-nuevoCosto, make_pair(ni, nj)));
            }
        }
    }
    return ruta;
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

        vector<pair<int, int> > ruta = branchAndBound(matrizCiudad, start_x, start_y, goal_x, goal_y);
        Coordenada nuevaContratacion = {2, 2};
        cout << "Nueva contratación: " << nuevaContratacion.x << ", " << nuevaContratacion.y << endl;

    }

    return 0;
}
