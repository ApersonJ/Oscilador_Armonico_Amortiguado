#include "../include/funciones.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

/// Tamaño máximo permitido para los arreglos de datos.
const int MAX_SIZE = 240;

/// Masa usada en el experimento (kg).
const double m = 0.145;

/**
 * @brief Lee un archivo con datos de tiempo y posición.
 *
 * Esta función abre un archivo de texto que contiene pares de valores
 * correspondientes a tiempo y posición, almacenándolos en los arreglos
 * proporcionados. Verifica que el archivo se abra correctamente y que
 * no exceda el número máximo permitido de elementos.
 *
 * @param nombreArchivo Nombre del archivo de entrada a leer.
 * @param tiempo Arreglo donde se almacenarán los valores de tiempo.
 * @param posicion Arreglo donde se almacenarán los valores de posición.
 * @return int Número de datos leídos desde el archivo.
 */
int leerArchivo(const string &nombreArchivo, double tiempo[], double posicion[]) {
    ifstream archivo(nombreArchivo.c_str());
    
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo de entrada." << endl;
        exit(1);
    }
    
    double t, x;
    int i = 0;
    
    while (archivo >> t >> x) {
        if (i >= MAX_SIZE) {
            cerr << "Error: El archivo contiene más datos de los permitidos por el tamaño máximo." << endl;
            exit(1);
        }
        
        tiempo[i] = t;
        posicion[i] = x;
        i++;
    }
    archivo.close();
    
    return i; // Devuelve el número de datos leídos
}

/**
 * @brief Calcula la velocidad y el momentum usando diferencias centradas.
 *
 * Para los puntos internos se aplica la fórmula de derivación centrada,
 * mientras que en los extremos la velocidad se asigna como cero, ya que
 * no es posible calcularla sin datos anteriores y posteriores.
 * Luego se calcula el momentum multiplicando la velocidad por la masa.
 *
 * @param tiempo Arreglo con los valores de tiempo.
 * @param posicion Arreglo con los valores de posición.
 * @param velocidad Arreglo donde se almacenarán las velocidades calculadas.
 * @param momentum Arreglo donde se almacenará el momentum calculado.
 * @param n Número total de datos.
 */
void calcularDerivadas(const double tiempo[], const double posicion[], double velocidad[], double momentum[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i > 0 && i < n - 1) { // Derivada centrada
            velocidad[i] = (posicion[i + 1] - posicion[i - 1]) / (tiempo[i + 1] - tiempo[i - 1]);
        } else {
            velocidad[i] = 0.0; // No se puede calcular para los extremos
        }
    }
    for (int i = 0; i < n; ++i){
        momentum[i] = velocidad[i] * m;
    }
}

/**
 * @brief Genera un archivo de salida con tiempo, posición, velocidad y momentum.
 *
 * Escribe un archivo de texto con encabezados y cuatro columnas correspondientes
 * a los datos procesados. El archivo se genera en formato tabulado.
 *
 * @param archivoSalida Nombre del archivo de salida a generar.
 * @param tiempo Arreglo con los valores de tiempo.
 * @param posicion Arreglo con los valores de posición.
 * @param velocidad Arreglo con las velocidades calculadas.
 * @param momentum Arreglo con los valores de momentum.
 * @param n Cantidad total de datos a escribir.
 */
void generarArchivoSalida(const string &archivoSalida, const double tiempo[], 
                          const double posicion[], const double velocidad[], const double momentum[], int n) {
    ofstream archivo(archivoSalida.c_str());
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo de salida." << endl;
        exit(1);
    }
    
    archivo << "# Tiempo\tPosicion\tVelocidad\tMomentum" << endl;
    for (int i = 0; i < n; ++i) {
        archivo << fixed << setprecision(6) << tiempo[i] << "\t" << posicion[i] << "\t" << velocidad[i] << "\t" << momentum[i] << endl;
    }
    archivo.close();
    cout << "Archivo generado: " << archivoSalida << endl;
}

