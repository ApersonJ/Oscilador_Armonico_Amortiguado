/**
 * @file funciones.cpp
 * @brief Implementación de funciones relacionadas con la generación de gráficas mediante Gnuplot.
 *
 * Este archivo contiene la función encargada de crear scripts de Gnuplot
 * y ejecutar dichos scripts para generar gráficas de posición, velocidad y momentum.
 */

#include "../include/funciones.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

/**
 * @brief Genera gráficas a partir de un archivo de datos usando Gnuplot.
 *
 * Esta función crea dos scripts de Gnuplot:
 * - Uno para graficar posición y velocidad vs tiempo.
 * - Otro para graficar momentum vs posición.
 *
 * Luego ejecuta cada script mediante una llamada al sistema.
 *
 * @param archivoSalida Ruta del archivo de datos que contiene columnas:
 *  - Columna 1: Tiempo  
 *  - Columna 2: Posición  
 *  - Columna 3: Velocidad  
 *  - Columna 4: Momentum  
 *
 * Los gráficos generados se guardan en:
 *  - `../results/graficas/velocidad_posicion_grafica.png`
 *  - `../results/graficas/momentum_grafica.png`
 *
 * @note No modifica el archivo de entrada.
 * @warning Requiere que Gnuplot esté instalado en el sistema.
 */
void graficarDatos(const string &archivoSalida) {
    string script1 = 
        "set terminal pngcairo size 800,600\n"
        "set output '../results/graficas/velocidad_posicion_grafica.png'\n"
        "set xlabel 'Tiempo'\n"
        "set ylabel 'Valores'\n"
        "set key outside\n"
        "plot '" + archivoSalida + "' using 1:2 with lines title 'Posicion', \\\n"
        "     '' using 1:3 with lines title 'velocidad'\n";
    
    ofstream scriptFile("../scripts/velocidad_posicion_grafica.gnuplot");
    if (scriptFile.is_open()) {
        scriptFile << script1;
        scriptFile.close();
        system("gnuplot ../scripts/velocidad_posicion_grafica.gnuplot");
        cout << "Gráfico generado: velocidad_posicion_grafica.png" << endl;
    } else {
        cerr << "Error: No se pudo crear el archivo de script gnuplot" << endl;
    }
    
    
    
    string script2 = 
        "set terminal pngcairo size 800,600\n"
        "set output '../results/graficas/momentum_grafica.png'\n"
        "set xlabel 'Posicion'\n"
        "set ylabel 'Momentum'\n"
        "set key outside\n"
        "plot '" + archivoSalida + "' using 2:4 with lines title 'momentum'\n";
    
    ofstream scriptFile2("../scripts/momentum_grafica.gnuplot");
    if (scriptFile2.is_open()) {
        scriptFile2 << script2;
        scriptFile2.close();
        system("gnuplot ../scripts/momentum_grafica.gnuplot");
        cout << "Gráfico generado: momentum_grafica.png" << endl;
    } else {
        cerr << "Error: No se pudo crear el archivo de script gnuplot" << endl;
    }
}

