#include "../include/funciones.h"

#include <iostream>
#include <string>

using namespace std;

// Definir un tamaño máximo para los arreglos
// Masa usada en el experimento (kg)

/**
 * @file main.cpp
 * @brief Programa principal para leer datos experimentales, calcular derivadas y generar resultados.
 *
 * Este programa se encarga de:
 * - Leer un archivo con datos de tiempo y posición.
 * - Calcular velocidad y momentum usando funciones definidas en funciones.h.
 * - Guardar los resultados de las derivadas en un archivo de salida.
 * - Graficar los datos obtenidos.
 */

const int MAX_SIZE = 240; ///< Tamaño máximo permitido para los arreglos de datos.
const double m = 0.145;    ///< Masa utilizada en el experimento (kg).

/**
 * @brief Funcón principal del programa.
 *
 * Carga datos desde un archivo, calcula derivadas (velocidad y momentum),
 * genera un archivo de salida con estos resultados y finalmente invoca una
 * función para graficarlos.
 *
 * @return int 0 si el programa finaliza correctamente.
 */
int main() {
    // Nombre del archivo de entrada y salida
    string archivoEntrada = "../results/listas/datos_posicion_tiempo.dat"; ///< Ruta del archivo de entrada.
    string archivoSalida = "../results/listas/datos_derivadas.dat"; ///< Ruta del archivo de salida.

    // Arreglos para almacenar datos
    double tiempo[MAX_SIZE], posicion[MAX_SIZE];
    double velocidad[MAX_SIZE], momentum[MAX_SIZE];

    // Leer archivo de entrada
    int n = leerArchivo(archivoEntrada, tiempo, posicion); ///< Cantidad de datos leídos.

    // Calcular derivadas
    calcularDerivadas(tiempo, posicion, velocidad, momentum, n);

    // Generar archivo con las derivadas 
    generarArchivoSalida(archivoSalida, tiempo, posicion, velocidad, momentum, n);

    // Graficar datos
    graficarDatos(archivoSalida);

    return 0;
}

