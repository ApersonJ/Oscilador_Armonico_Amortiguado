#ifndef RK4SOLVER_H
#define RK4SOLVER_H

#include <string>

void pedirDatos(double &x, double &t, double &dt);
double funcion(double x, double t);
void rungeKutta4(double &x, double &t, double dt);
void guardarDatos(const std::string &archivo, double t0, double x0, double dt, double tmax);

#endif