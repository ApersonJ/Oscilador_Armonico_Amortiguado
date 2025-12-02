/**
 * @file main.cpp
 * @brief Punto de entrada principal para la simulación del oscilador amortiguado.
 * 
 * Este programa simula el comportamiento de un oscilador armónico amortiguado
 * utilizando el método de Runge-Kutta de cuarto orden. Solicita los parámetros
 * iniciales al usuario, ejecuta la simulación y guarda los resultados en un archivo.
 * 
 * @author [Jesus Vitola, Nicolas Lopez, Mariana Velandia, Laura Riaño]
 * @date [01/12/2025]
 */

#include "../include/funciones.h"
using namespace std;

/**
 * @brief Función principal del programa.
 * 
 * Gestiona el flujo principal de la simulación: solicita los datos al usuario,
 * ejecuta la simulación y guarda los resultados.
 * 
 * @return int Código de salida del programa (0 si finaliza correctamente).
 */
int main() {
    double x, t, v, m, k, l, dt;  ///< Variables para posición, tiempo, velocidad, masa, constante elástica, coeficiente de amortiguamiento y paso de tiempo.
    double tmax = 20.0;           ///< Tiempo máximo de simulación (en segundos).

    pedirDatos(x, t, v, m, k, l, dt);                              ///< Solicita los datos iniciales al usuario.
    guardarDatos("../results/oscillator.dat", x, t, v, m, k, l, dt, tmax); ///< Ejecuta la simulación y guarda los resultados.

    return 0; ///< Indica que el programa finalizó correctamente.
}