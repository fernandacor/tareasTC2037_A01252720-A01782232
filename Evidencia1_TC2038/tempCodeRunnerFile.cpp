// Función para comparar dos archivos de transmisión y encontrar el substring más largo en común
// void compararTextos(string archT1, string archT2)
// {
//     // Abrir y leer los archivos
//     ifstream archivoTransmision1(archT1);
//     ifstream archivoTransmision2(archT2);
//     string lineaT1, lineaT2;

//     // Se recorre cada línea de los archivos de transmisión y se guarda en un string
//     string contenidoArchivoT1;
//     while (getline(archivoTransmision1, lineaT1))
//     {
//         contenidoArchivoT1 += lineaT1;
//     }

//     string contenidoArchivoT2;
//     while (getline(archivoTransmision2, lineaT2))
//     {
//         contenidoArchivoT2 += lineaT2;
//     }

//     // Iteradores para encontrar el substring más largo en común
//     int maxLongitud = 0;
//     int posicionInicio = -1;
//     int posicionFinal = -1;

//     // Ciclos for anidados para recorrer cada uno de los archivos de transmisión
//     for (int i = 0; i < contenidoArchivoT1.length(); i++)
//     {
//         for (int j = 0; j < contenidoArchivoT2.length(); j++)
//         {
//             // La longitud comienza en 0
//             int longitud = 0;

//             // Se compara cada caracter de los archivos de transmisión
//             while (i + longitud < contenidoArchivoT1.length() &&
//                    j + longitud < contenidoArchivoT2.length() &&
//                    contenidoArchivoT1[i + longitud] == contenidoArchivoT2[j + longitud])
//             {
//                 longitud++;
//             }

//             // Si la longitud es mayor a la longitud máxima, se actualiza la longitud máxima y las posiciones
//             if (longitud > maxLongitud)
//             {
//                 maxLongitud = longitud;
//                 posicionInicio = i;
//                 posicionFinal = i + longitud - 1;
//             }
//         }
//     }

//     // Condicional para imprimir el resultado
//     if (maxLongitud > 0)
//     {
//         cout << posicionInicio + 1 << " " << posicionFinal + 1 << endl;
//     }
//     else
//     {
//         cout << "No se encontró un substring común entre los archivos" << endl;
//     }
// }