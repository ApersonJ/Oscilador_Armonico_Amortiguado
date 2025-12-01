#include "../include/funciones.h"
#include "../include/grafica.h"  // Incluir el nuevo encabezado
#include "../include/animacion.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;


void funcion(double x, double t, double v, double m, double c, double k, 
             double &dxdt, double &dvdt) {
    dxdt = v; 
    dvdt = (-k/m) * x - (c/m) * v;  // Amortiguamiento LINEAL
}


void rungeKuttaStep(double &x, double &v, double &t, double dt,
                    double m, double c, double k) {
    double dx1, dv1, dx2, dv2, dx3, dv3, dx4, dv4;

    funcion(x, t, v, m, c, k, dx1, dv1);
    
    funcion(x + 0.5 * dt * dx1,  t + 0.5 * dt, v + 0.5 * dt * dv1, m, c, k, dx2, dv2);
    funcion(x + 0.5 * dt * dx2, t + 0.5 * dt, v + 0.5 * dt * dv2, m, c, k, dx3, dv3);
    funcion(x + dt * dx3,t + dt, v + dt * dv3, m, c, k, dx4, dv4);

    x += dt * (dx1 + 2.0 * dx2 + 2.0 * dx3 + dx4) / 6.0;
    v += dt * (dv1 + 2.0 * dv2 + 2.0 * dv3 + dv4) / 6.0;
    t += dt;
}

void solicitarParametros(double &m, double &k, double &c,  double &x0, double &v0, double &t0, double &tf, double &dt) {
    
    cout << "INGRESE LOS PARAMETROS FISICOS:" << endl;
    cout << "--------------------------------" << endl;
    
    cout << "Masa (m) [kg]: ";
    cin >> m;
    while (m <= 0) {
        cout << "Error: La masa debe ser positiva. Ingrese nuevamente: ";
        cin >> m;
    }
    
    cout << "Constante del resorte (k) [N/m]: ";
    cin >> k;
    while (k <= 0) {
        cout << "Error: La constante del resorte debe ser positiva. Ingrese nuevamente: ";
        cin >> k;
    }
    
    cout << "Coeficiente de amortiguamiento (c) [Ns/m]: ";
    cin >> c;
    while (c < 0) {
        cout << "Error: El coeficiente no puede ser negativo. Ingrese nuevamente: ";
        cin >> c;
    }
    
    cout << "Posicion inicial (x0) [m]: ";
    cin >> x0;
    
    cout << "Velocidad inicial (v0) [m/s]: ";
    cin >> v0;
    
    cout << "Tiempo inicial (t0) [s]: ";
    cin >> t0;
    
    cout << "Tiempo final (tf) [s]: ";
    cin >> tf;
    while (tf <= t0) {
        cout << "Error: El tiempo final debe ser mayor al inicial. Ingrese nuevamente: ";
        cin >> tf;
    }
    
    cout << "Paso de tiempo (dt) [s]: ";
    cin >> dt;
    while (dt <= 0 || dt > (tf - t0)) {
        cout << "Error: El paso debe ser positivo y menor que el intervalo total. Ingrese nuevamente: ";
        cin >> dt;
    }
    
}

void ejecutarSimulacionCompleta() {
    double m, k, c;           
    double x0, v0, t0, tf, dt; 
    
    solicitarParametros(m, k, c, x0, v0, t0, tf, dt);
    
    if (m <= 0 || k <= 0 || c < 0 || dt <= 0) {
        cout << "Error: Parametros invalidos. La simulacion no puede continuar." << endl;
        return;
    }
    
    vector<double> tiempos;
    vector<double> posiciones;
    vector<double> velocidades;
    vector<double> momentums;
    
    double t = t0;
    double x = x0;
    double v = v0;
    double p = m * v; 
    

    int contador = 0;
    while (t <= tf + dt/2.0) {  
        tiempos.push_back(t);
        posiciones.push_back(x);
        velocidades.push_back(v);
        momentums.push_back(p);
        
    
        rungeKuttaStep(x, v, t, dt, m, c, k);
        p = m * v;  
        

        contador++;
        if (contador % 1000 == 0) {
            cout << "Progreso: paso " << contador << ", t = " << t << " s" << endl;
        }
    }
    
   
       // Listas de datos
    // 1. Posición vs Tiempo
    ofstream archivo1("../resultados/listas/posicion_vs_tiempo.txt");
    archivo1 << "# Tiempo\tPosicion" << endl;
    archivo1 << "# m = " << m << " kg, k = " << k << " N/m, c = " << c << " Ns/m" << endl;
    archivo1 << "# x0 = " << x0 << " m, v0 = " << v0 << " m/s" << endl;
    archivo1 << "# t0 = " << t0 << " s, tf = " << tf << " s, dt = " << dt << " s" << endl;
    archivo1 << "# Sistema: Oscilador armonico amortiguado LINEAL" << endl;
    
    for (size_t i = 0; i < tiempos.size(); i++) {
        archivo1 << tiempos[i] << "\t" << posiciones[i] << endl;
    }
    archivo1.close();
    
    // 2. Velocidad vs Tiempo
    ofstream archivo2("../resultados/listas/velocidad_vs_tiempo.txt");
    archivo2 << "# Tiempo\tVelocidad" << endl;
    archivo2 << "# m = " << m << " kg, k = " << k << " N/m, c = " << c << " Ns/m" << endl;
    archivo2 << "# x0 = " << x0 << " m, v0 = " << v0 << " m/s" << endl;
    archivo2 << "# t0 = " << t0 << " s, tf = " << tf << " s, dt = " << dt << " s" << endl;
    archivo2 << "# Sistema: Oscilador armonico amortiguado LINEAL" << endl;
    
    for (size_t i = 0; i < tiempos.size(); i++) {
        archivo2 << tiempos[i] << "\t" << velocidades[i] << endl;
    }
    archivo2.close();
    
    // 3. Momentum vs Posición
    ofstream archivo3("../resultados/listas/momentum_vs_posicion.txt");
    archivo3 << "# Posicion\tMomentum" << endl;
    archivo3 << "# m = " << m << " kg, k = " << k << " N/m, c = " << c << " Ns/m" << endl;
    archivo3 << "# x0 = " << x0 << " m, v0 = " << v0 << " m/s" << endl;
    archivo3 << "# t0 = " << t0 << " s, tf = " << tf << " s, dt = " << dt << " s" << endl;
    archivo3 << "# Sistema: Oscilador armonico amortiguado LINEAL" << endl;
    
    for (size_t i = 0; i < posiciones.size(); i++) {
        archivo3 << posiciones[i] << "\t" << momentums[i] << endl;
    }
    archivo3.close();
    
    cout << endl << "===========================================" << endl;
    cout << "          SIMULACION COMPLETADA" << endl;
    cout << "===========================================" << endl << endl;
    
   
    cout << "  Numero de puntos calculados: " << tiempos.size() << endl;
    
    cout << endl << "Archivos de datos generados en '../resultados/listas/':" << endl;
    cout << "  • posicion_vs_tiempo.txt" << endl;
    cout << "  • velocidad_vs_tiempo.txt" << endl;
    cout << "  • momentum_vs_posicion.txt" << endl;
 
    
    // Generar gráficas después de la simulación
    generarGraficas();
    
    // Generar animaciones GIF
    cout << "\n===========================================" << endl;
    cout << "   ¿DESEA GENERAR ANIMACIONES GIF? (s/n): ";
    char respuesta;
    cin >> respuesta;
    
    if (respuesta == 's' || respuesta == 'S') {
        generarAnimacionPosicion();
        generarGifPosicionTiempo();
    }
}