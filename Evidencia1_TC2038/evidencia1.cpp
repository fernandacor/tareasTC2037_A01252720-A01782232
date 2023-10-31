#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void leerArchivos(string archT, string archM)
{
    ifstream archivoTransmision(archT);
    ifstream archivoMCode(archM);
    string lineaT, lineaM;

    string contenidoArchM;
    while (getline(archivoMCode, lineaM)) 
    {
        contenidoArchM += lineaM;
    }

    string contenidoArchivoT;
    size_t found;
    size_t posicion = 1;
    size_t contador = 0;
    while (getline(archivoTransmision, lineaT)) 
    {
        contenidoArchivoT += lineaT;
        found = contenidoArchivoT.find(contenidoArchM);
        if (found != string::npos) 
        {
            cout << "true " << posicion + found << endl;
            return;
        }
        posicion += lineaT.length();
        contador++;
    }
    cout << "false" << endl;
}

int main()
{
    cout << "PARTE 1" << endl;
    leerArchivos("transmission2.txt", "mcode2.txt");
    cout << endl << "PARTE 2" << endl;
    return 0;
}

// que lea 5 archivos de texto de nombre fijo
// los archivos de transmision contienen caracteres de texto que representan el envio de datos de un dispositivo a otro
// los archivos mcode representan codigo malicioso que se puede encontrar dentro de una transmision
// PARTE 1
// el programa debe analizar si el contenido de los archivos mcode estan contenidos en los archivos de transmision
// en caso de ser true, muestra true seguido de un espacio, seguido de la posición del archivo transmission donde inicia el codigo de mcode
// Output: (true | false) <posicion>
// PARTE 2
// PARTE 3
// el programa analiza que tan similares son los archivos de transmision y muestra la posicion inicial y posicion final 
// del primer archivo en donde se encuentra el substring más largo común entre ambos archivos de tranmisión