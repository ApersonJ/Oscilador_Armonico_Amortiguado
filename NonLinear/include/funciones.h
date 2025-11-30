#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>

void pedirDatos(double &x, double &t, double &v, double &m, double &k, double &l, double &dt);
double funcion(double x, double t, double v, double m, double k, double l, double &dxdt, double &dvdt);
void rungeKutta4(double &x, double &t, double &v, double &m, double &k, double &l, double dt);
void guardarDatos(const std::string, double x0, double t0, double v0, double m, double k, 
                    double l, double dt, double tmax);

#endif