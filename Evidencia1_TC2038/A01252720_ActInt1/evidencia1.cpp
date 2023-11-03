// Evidencia 1: Actividad Integradora
// Alina Rosas Macedo A01252720 y Fernanda Cantú Ortega A01782232
// 02/11/2023

//Librerías a utilizar
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Función para encontrar código malicioso dentro de archivos de transmisión
void encontrarMCode(const vector<string> archivosTransmision, const vector<string> archivosMCode)
{
    // Ciclos for para recorrer los archivos de transmisión y los archivos de código malicioso
    for (size_t i = 0; i < archivosTransmision.size(); i++)
    {
        for (size_t j = 0; j < archivosMCode.size(); j++)
        {
            // Abrir y leer los archivos
            ifstream archivoTransmision(archivosTransmision[i]);
            ifstream archivoMCode(archivosMCode[j]);
            string lineaT, lineaM;

            // Se recorre cada línea de los archivos de transmisión y se guarda en un string
            string contenidoTransmision;
            while (getline(archivoTransmision, lineaT))
            {
                contenidoTransmision += lineaT;
            }

            // Se recorre cada línea de los archivos de código malicioso y se guarda en un string
            string contenidoMCode;
            while (getline(archivoMCode, lineaM))
            {
                contenidoMCode += lineaM;
            }

            // Se busca el contenido de los archivos de código malicioso dentro de los archivos de transmisión
            size_t posicion = contenidoTransmision.find(contenidoMCode);
            string resultado = (posicion != string::npos ? "true " + to_string(posicion) : "false");
            cout << resultado << endl;
        }
    }
    cout << endl;
}

// Función para encontrar palíndromos dentro de archivos de transmisión
void encontrarPalindromo(string arch)
{
    // Abrir y leer el archivo
    ifstream archivoTransmision(arch);
    string lineaT;

    // Se recorre cada línea del archivo de transmisión y se guarda en un string
    string contenidoArchivoT;
    while (getline(archivoTransmision, lineaT))
    {
        contenidoArchivoT += lineaT;
    }

    // Iteradores para encontrar el substring más largo que sea palíndromo
    int inicio = 0;
    int longitud = 1;

    // Ciclo for para iterar por el contenido del archivo de transmisión
    for (int i = 1; i < contenidoArchivoT.length(); i++)
    {
        int j = 1;

        // Para substrings de longitud impar
        while (i - j >= 0 && i + j < contenidoArchivoT.length() && contenidoArchivoT[i - j] == contenidoArchivoT[i + j])
        {
            j++;
        }

        if (2 * j - 1 > longitud)
        {
            longitud = 2 * j - 1;
            inicio = i - j + 1;
        }

        j = 0;

        // Para substring de longitud par
        while (i - j - 1 >= 0 && i + j < contenidoArchivoT.length() && contenidoArchivoT[i - j - 1] == contenidoArchivoT[i + j])
        {
            j++;
        }

        if (2 * j > longitud)
        {
            longitud = 2 * j;
            inicio = i - j;
        }
    }

    // Condicional para imprimir el resultado
    if (longitud > 1)
    {
        cout << inicio << " " << inicio + longitud - 1 << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}

// Función para comparar dos archivos de transmisión y encontrar el substring más largo en común
void compararTextos(string archT1, string archT2)
{
    // Abrir y leer los archivos
    ifstream archivoTransmision1(archT1);
    ifstream archivoTransmision2(archT2);
    string lineaT1, lineaT2;

    // Se recorre cada línea de los archivos de transmisión y se guarda en un string
    string contenidoArchivoT1;
    while (getline(archivoTransmision1, lineaT1))
    {
        contenidoArchivoT1 += lineaT1;
    }

    string contenidoArchivoT2;
    while (getline(archivoTransmision2, lineaT2))
    {
        contenidoArchivoT2 += lineaT2;
    }

    // Variables para guardar la longitud de los archivos de transmisión
    int n = contenidoArchivoT1.length();
    int m = contenidoArchivoT2.length();

    // Generar una matriz de n+1 x m+1 para guardar los valores de la longitud del substring más largo
    vector<vector<int> > LCS(n+1, vector<int>(m+1, 0));

    // Variables para guardar la longitud del substring más largo y su posición de inicio
    int maxLongitud = 0;
    int posicionInicio = 0;

    // Ciclos for anidados para recorrer cada uno de los archivos de transmisión
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(contenidoArchivoT1[i-1] == contenidoArchivoT2[j-1])
            {
                // LCS = Longest Common String
                LCS[i][j] = LCS[i-1][j-1] + 1;
                if (LCS[i][j] > maxLongitud)
                {
                    maxLongitud = LCS[i][j];
                    posicionInicio = i - maxLongitud;
                }
            }
        }
    }

    // Condicional para imprimir el resultado
    if (maxLongitud > 0)
    {
        int posicionFinal = posicionInicio + maxLongitud - 1;
        cout << posicionInicio + 1 << " " << posicionFinal + 1 << endl;
    }
    else
    {
        cout << "No se encontró ningún substring entre los archivos" << endl;
    }
}

int main()
{
    // Vectores con los nombres de los archivos de transmisión y de código malicioso
    vector<string> archivosTransmision;
    archivosTransmision.push_back("transmission1.txt");
    archivosTransmision.push_back("transmission2.txt");

    vector<string> archivosMCode;
    archivosMCode.push_back("mcode1.txt");
    archivosMCode.push_back("mcode2.txt");
    archivosMCode.push_back("mcode3.txt");

    // Se mandan llamar las distintas funciones del programa
    cout << "PARTE 1" << endl;
    encontrarMCode(archivosTransmision, archivosMCode);

    cout << "PARTE 2" << endl;
    encontrarPalindromo("transmission1.txt");
    encontrarPalindromo("transmission2.txt");

    cout << endl << "PARTE 3" << endl;
    compararTextos("transmission1.txt", "transmission2.txt");
    return 0;
}