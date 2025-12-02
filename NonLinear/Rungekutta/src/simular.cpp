/**
 * @file simular.cpp
 * @brief Implementación de las funciones para la simulación del oscilador amortiguado.
 * 
 * Contiene las funciones necesarias para la simulación numérica de un oscilador
 * armónico con amortiguamiento cuadrático, utilizando el método de Runge-Kutta
 * de cuarto orden. Además, incluye funciones para la entrada de datos y el
 * almacenamiento de resultados.
 * 
 * @author [Jesus Vitola, Nicolas Lopez, Mariana Velandia, Laura Riaño]
 * @date [01/12/2025]
 */

#include "../include/funciones.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

/**
 * @brief Solicita al usuario los parámetros iniciales para la simulación.
 * 
 * Pide al usuario que introduzca los valores iniciales de posición, tiempo, velocidad,
 * masa, constante elástica, coeficiente de amortiguamiento y paso de integración.
 * 
 * @param x Referencia a la posición inicial (m).
 * @param t Referencia al tiempo inicial (s).
 * @param v Referencia a la velocidad inicial (m/s).
 * @param m Referencia a la masa del oscilador (Kg).
 * @param k Referencia a la constante elástica del resorte (N/m).
 * @param l Referencia al coeficiente de amortiguamiento (Kg/m).
 * @param dt Referencia al paso de integración (s).
 */
void pedirDatos(double &x, double &t, double &v, double &m, double &k, double &l, double &dt) {
    cout << "Ingrese el valor inicial de x (m): ";
    cin >> x;
    cout << "Ingrese el valor inicial de t (s): ";
    cin >> t;
    cout << "Ingrese el valor inicial de v  (m/s): ";
    cin >> v;
    cout << "Ingrese el valor de la masa (Kg): ";
    cin >> m;
    cout << "Ingrese el valor de k (N/m): ";
    cin >> k;
    cout << "Ingrese el valor del coeficiente de amortiguamiento (Kg/m): ";
    cin >> l;
    cout << "Ingrese el paso de integracion dt: ";
    cin >> dt;
}

/**
 * @brief Calcula las derivadas del sistema de ecuaciones diferenciales.
 * 
 * Evalúa las ecuaciones del oscilador amortiguado:
 * - dx/dt = v
 * - dv/dt = -(k/m)*x - (l/m)*v*|v|
 * 
 * @param dxdt Referencia para almacenar la derivada de la posición (dx/dt).
 * @param dvdt Referencia para almacenar la derivada de la velocidad (dv/dt).
 */
void funcion(double x, double t, double v, double m, double k, double l, double &dxdt, double &dvdt) {
    dxdt = v; ///< Derivada de la posición: velocidad.
    dvdt = (-k/m) * x - (l/m) * v * fabs(v); ///< Derivada de la velocidad: aceleración (fuerza elástica + amortiguamiento cuadrático).
}

/**
 * @brief Aplica un paso del método de Runge-Kutta de cuarto orden.
 * 
 * Avanza la solución del sistema de ecuaciones diferenciales un paso de tiempo dt,
 * actualizando los valores de posición (x) y velocidad (v).
 * 
 */
void rungeKutta4(double &x, double &t, double &v, double &m, double &k, double &l, double dt) {
    double dx1, dv1, dx2, dv2, dx3, dv3, dx4, dv4; ///< Variables para las evaluaciones intermedias de Runge-Kutta.

    funcion(x, t, v, m , k, l, dx1, dv1); ///< Primera evaluación (k1).
    funcion(x + 0.5 * dt * dx1, t + 0.5 * dt, v + 0.5 * dt * dv1, m , k, l, dx2, dv2); ///< Segunda evaluación (k2).
    funcion(x + 0.5 * dt * dx2, t + 0.5 * dt, v + 0.5 * dt * dv2, m , k, l, dx3, dv3); ///< Tercera evaluación (k3).
    funcion(x + dt * dx3, t + dt, v + dt * dv3, m , k, l, dx4, dv4); ///< Cuarta evaluación (k4).

    /// Actualización de x y v usando la combinación ponderada de las evaluaciones.
    x += dt * (dx1 + 2 * dx2 + 2 * dx3 + dx4) / 6.0;
    v += dt * (dv1 + 2 * dv2 + 2 * dv3 + dv4) / 6.0;
}

/**
 * @brief Ejecuta la simulación y guarda los resultados en un archivo.
 * 
 * Realiza la integración numérica desde t0 hasta tmax con paso dt,
 * guardando en un archivo los valores de tiempo, posición, velocidad y momento lineal.
 * Al finalizar, ejecuta un script de gnuplot para graficar los resultados.
 * 
 * @param archivo Ruta del archivo de salida donde se guardarán los datos.
 * @param x0 Posición inicial (m).
 * @param t0 Tiempo inicial (s).
 * @param v0 Velocidad inicial (m/s).
 * @param tmax Tiempo máximo de simulación (s).
 */
void guardarDatos(const string &archivo, double x0, double t0, double v0, double m, double k, 
                    double l, double dt, double tmax) {
    system("mkdir -p ../results"); ///< Crea el directorio de resultados si no existe.

    ofstream file(archivo);
    file << fixed << setprecision(6); ///< Formato de salida: punto fijo con 6 decimales.
    file << setw(10) << "t" << setw(15) << "x" << setw(15) << "v" << setw(15) << "p" <<endl; ///< Encabezado del archivo.

    double x = x0; ///< Posición inicial.
    double v = v0; ///< Velocidad inicial.
    double p = m * v; ///< Momento lineal inicial (p = m*v).

    /// Bucle de integración temporal.
    for (double t = t0; t <= tmax; t += dt) {
        file << setw(10) << t << setw(15) << x << setw(15) << v << setw(15) << p << endl; ///< Escribe datos en el archivo.
        rungeKutta4(x, t, v, m, k ,l, dt); ///< Avanza un paso de tiempo.
        p = m * v; ///< Actualiza el momento lineal.
    }

    file.close(); ///< Cierra el archivo de salida.
    cout << "Datos guardados en: " << archivo << endl;

    system ("gnuplot ../scripts/graficar.gp"); ///< Ejecuta el script de gnuplot para generar gráficas.
}