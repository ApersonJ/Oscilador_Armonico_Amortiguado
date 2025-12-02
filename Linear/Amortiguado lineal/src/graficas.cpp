#include "../include/grafica.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Función auxiliar para ejecutar comandos Gnuplot
void ejecutarGnuplot(const string& comando) {
    string comandoCompleto = "gnuplot -e \"" + comando + "\"";
    system(comandoCompleto.c_str());
}

// Generar gráfica de posición vs tiempo
void generarGraficaPosicionTiempo() {
    string comando = 
        "set terminal pngcairo size 1200,800 enhanced font 'Arial,12'; "
        "set output '../resultados/graficas/posicion_vs_tiempo.png'; "
        "set title 'Oscilador Armónico Amortiguado: Posición vs Tiempo'; "
        "set xlabel 'Tiempo (s)'; "
        "set ylabel 'Posición (m)'; "
        "set grid; "
        "set key top right; "
        "set style line 1 lc rgb '#0060ad' lt 1 lw 2; "
        "plot '../resultados/listas/posicion_vs_tiempo.txt' using 1:2 with lines ls 1 title 'x(t)'";
    
    cout << "  Generando: ../resultados/graficas/posicion_vs_tiempo.png" << endl;
    ejecutarGnuplot(comando);
}

// Generar gráfica de velocidad vs tiempo
void generarGraficaVelocidadTiempo() {
    string comando = 
        "set terminal pngcairo size 1200,800 enhanced font 'Arial,12'; "
        "set output '../resultados/graficas/velocidad_vs_tiempo.png'; "
        "set title 'Oscilador Armónico Amortiguado: Velocidad vs Tiempo'; "
        "set xlabel 'Tiempo (s)'; "
        "set ylabel 'Velocidad (m/s)'; "
        "set grid; "
        "set key top right; "
        "set style line 1 lc rgb '#d62728' lt 1 lw 2; "
        "plot '../resultados/listas/velocidad_vs_tiempo.txt' using 1:2 with lines ls 1 title 'v(t)'";
    
    cout << "  Generando: ../resultados/graficas/velocidad_vs_tiempo.png" << endl;
    ejecutarGnuplot(comando);
}

// Generar gráfica de momentum vs posición
void generarGraficaMomentumPosicion() {
    string comando = 
        "set terminal pngcairo size 1200,800 enhanced font 'Arial,12'; "
        "set output '../resultados/graficas/momentum_vs_posicion.png'; "
        "set title 'Oscilador Armónico Amortiguado: Momentum vs Posición'; "
        "set xlabel 'Posición (m)'; "
        "set ylabel 'Momentum (kg·m/s)'; "
        "set grid; "
        "set key top right; "
        "set style line 1 lc rgb '#2ca02c' lt 1 lw 2; "
        "plot '../resultados/listas/momentum_vs_posicion.txt' using 1:2 with lines ls 1 title 'p(x)'";
    
    cout << "  Generando: ../resultados/graficas/momentum_vs_posicion.png" << endl;
    ejecutarGnuplot(comando);
}

// Generar gráfica de espacio de fase (posición vs velocidad)
void generarGraficaEspacioFase() {
    string comando = 
        "set terminal pngcairo size 1200,800 enhanced font 'Arial,12'; "
        "set output '../resultados/graficas/espacio_fase.png'; "
        "set title 'Oscilador Armónico Amortiguado: Espacio de Fase'; "
        "set xlabel 'Posición (m)'; "
        "set ylabel 'Velocidad (m/s)'; "
        "set grid; "
        "set key top right; "
        "set style line 1 lc rgb '#ff7f0e' lt 1 lw 2; "
        "plot '../resultados/listas/velocidad_vs_tiempo.txt' using 2:1 with lines ls 1 title 'Espacio de Fase'";
    
    cout << "  Generando: ../resultados/graficas/espacio_fase.png" << endl;
    ejecutarGnuplot(comando);
}

// Generar todas las gráficas en una imagen compuesta
void generarGraficaCompleta() {
    // Crear archivo temporal para el script
    ofstream script("temp_grafica_completa.gnu");
    
    script << "# Script temporal para gráfica completa\n";
    script << "set terminal pngcairo size 1600,1200 enhanced font 'Arial,12'\n";
    script << "set output '../resultados/graficas/todas_graficas.png'\n\n";
    script << "set multiplot layout 2,2 title 'Oscilador Armónico Amortiguado - Análisis Completo'\n\n";
    
    script << "# Gráfica 1: Posición vs Tiempo\n";
    script << "set title 'Posición vs Tiempo'\n";
    script << "set xlabel 'Tiempo (s)'\n";
    script << "set ylabel 'Posición (m)'\n";
    script << "set grid\n";
    script << "set style line 1 lc rgb '#0060ad' lt 1 lw 2\n";
    script << "plot '../resultados/listas/posicion_vs_tiempo.txt' using 1:2 with lines ls 1 title 'x(t)'\n\n";
    
    script << "# Gráfica 2: Velocidad vs Tiempo\n";
    script << "set title 'Velocidad vs Tiempo'\n";
    script << "set xlabel 'Tiempo (s)'\n";
    script << "set ylabel 'Velocidad (m/s)'\n";
    script << "set grid\n";
    script << "set style line 2 lc rgb '#d62728' lt 1 lw 2\n";
    script << "plot '../resultados/listas/velocidad_vs_tiempo.txt' using 1:2 with lines ls 2 title 'v(t)'\n\n";
    
    script << "# Gráfica 3: Momentum vs Posición\n";
    script << "set title 'Momentum vs Posición'\n";
    script << "set xlabel 'Posición (m)'\n";
    script << "set ylabel 'Momentum (kg·m/s)'\n";
    script << "set grid\n";
    script << "set style line 3 lc rgb '#2ca02c' lt 1 lw 2\n";
    script << "plot '../resultados/listas/momentum_vs_posicion.txt' using 1:2 with lines ls 3 title 'p(x)'\n\n";
    
    script << "# Gráfica 4: Espacio de Fase\n";
    script << "set title 'Espacio de Fase: Posición vs Velocidad'\n";
    script << "set xlabel 'Posición (m)'\n";
    script << "set ylabel 'Velocidad (m/s)'\n";
    script << "set grid\n";
    script << "set style line 4 lc rgb '#ff7f0e' lt 1 lw 2\n";
    script << "plot '../resultados/listas/velocidad_vs_tiempo.txt' using 2:1 with lines ls 4 title 'Espacio de Fase'\n\n";
    
    script << "unset multiplot\n";
    
    script.close();
    
    // Ejecutar el script
    cout << "  Generando: ../resultados/graficas/todas_graficas.png" << endl;
    system("gnuplot temp_grafica_completa.gnu");
    
    // Eliminar el script temporal
    remove("temp_grafica_completa.gnu");
}

// Función principal para generar todas las gráficas
void generarGraficas() {
    cout << "\n===========================================" << endl;
    cout << "   GENERANDO GRAFICAS CON GNUPLOT" << endl;
    cout << "===========================================" << endl;
    
    cout << "\nGenerando gráficas individuales..." << endl;
    
    // Generar gráficas individuales
    generarGraficaPosicionTiempo();
    generarGraficaVelocidadTiempo();
    generarGraficaMomentumPosicion();
    generarGraficaEspacioFase();
    
    cout << "\nGenerando gráfica compuesta..." << endl;
    generarGraficaCompleta();
    
    cout << "\n===========================================" << endl;
    cout << "   GRAFICAS GENERADAS EXITOSAMENTE" << endl;
    cout << "===========================================" << endl;
    cout << "\nArchivos generados:" << endl;
    
    cout << "\nEn '../resultados/listas/':" << endl;
    cout << "  ✓ posicion_vs_tiempo.txt" << endl;
    cout << "  ✓ velocidad_vs_tiempo.txt" << endl;
    cout << "  ✓ momentum_vs_posicion.txt" << endl;
    
    cout << "\nEn '../resultados/graficas/':" << endl;
    cout << "  ✓ posicion_vs_tiempo.png" << endl;
    cout << "  ✓ velocidad_vs_tiempo.png" << endl;
    cout << "  ✓ momentum_vs_posicion.png" << endl;
    cout << "  ✓ espacio_fase.png" << endl;
    cout << "  ✓ todas_graficas.png" << endl;
    

}