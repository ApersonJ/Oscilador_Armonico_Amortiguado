#ifndef FUNCIONES_H
#define FUNCIONES_H


void funcion(double x, double t, double v, double m, double c, double k,  double &dxdt, double &dvdt);
void rungeKuttaStep(double &x, double &v, double &t, double dt, double m, double c, double k);
void solicitarParametros(double &m, double &k, double &c, double &x0, double &v0, double &t0, double &tf, double &dt);

void ejecutarSimulacionCompleta();  
#endif