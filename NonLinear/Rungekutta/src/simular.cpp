#include "../include/funciones.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

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

void funcion(double x, double t, double v, double m, double k, double l, double &dxdt, double &dvdt) {

    dxdt = v; 
    dvdt = (-k/m) * x - (l/m) * v * fabs(v);
    ;
}

void rungeKutta4(double &x, double &t, double &v, double &m, double &k, double &l, double dt) {

    double dx1, dv1, dx2, dv2, dx3, dv3, dx4, dv4;

    funcion(x, t, v, m , k, l, dx1, dv1);
    funcion(x + 0.5 * dt * dx1, t + 0.5 * dt, v + 0.5 * dt * dv1, m , k, l, dx2, dv2);
    funcion(x + 0.5 * dt * dx2, t + 0.5 * dt, v + 0.5 * dt * dv2, m , k, l, dx3, dv3);
    funcion(x + dt * dx3, t + dt, v + dt * dv3, m , k, l, dx4, dv4);
   

    x += dt * (dx1 + 2 * dx2 + 2 * dx3 + dx4) / 6.0;
    v += dt * (dv1 + 2 * dv2 + 2 * dv3 + dv4) / 6.0;
}

void guardarDatos(const string &archivo, double x0, double t0, double v0, double m, double k, 
                    double l, double dt, double tmax) {
    system("mkdir -p ../results");

    ofstream file(archivo);
    file << fixed << setprecision(6);
    file << setw(10) << "t" << setw(15) << "x" << setw(15) << "v" <<endl;

    double x = x0;
    double v = v0;

    for (double t = t0; t <= tmax; t += dt) {
        file << setw(10) << t << setw(15) << x << setw(15) << v << endl;
        rungeKutta4(x, t, v, m, k ,l, dt);
    }

    file.close();
    cout << "Datos guardados en: " << archivo << endl;

    system ("gnuplot ../scripts/graficar.gp");
}