#include "funciones.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void pedirDatos(double &x, double &t, double &dt) {
    cout << "Ingrese el valor inicial de x: ";
    cin >> x;
    cout << "Ingrese el valor inicial de t: ";
    cin >> t;
    cout << "Ingrese el paso de integracion dt: ";
    cin >> dt;
}

double funcion(double x, double t) {
    return (t * t - 1.0) / (x * x);
}

void rungeKutta4(double &x, double &t, double dt) {
    double k1 = dt * funcion(x, t);
    double k2 = dt * funcion(x + 0.5 * k1, t + 0.5 * dt);
    double k3 = dt * funcion(x + 0.5 * k2, t + 0.5 * dt);
    double k4 = dt * funcion(x + k3, t + dt);

    x += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
    t += dt;
}

void guardarDatos(const string &archivo, double t0, double x0, double dt, double tmax) {
    system("mkdir -p results");

    ofstream file(archivo);
    file << fixed << setprecision(6);
    file << setw(10) << "t" << setw(15) << "x" << endl;

    double x = x0;

    for (double t = t0; t <= tmax; t += dt) {
        file << setw(10) << t << setw(15) << x << endl;
        rungeKutta4(x, t, dt);
    }

    file.close();
    cout << "Datos guardados en: " << archivo << endl;
}