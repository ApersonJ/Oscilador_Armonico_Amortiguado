#include "../include/animacion.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Función para generar la animación de posición vs tiempo
void generarAnimacionPosicion() {
    cout << "\n===========================================" << endl;
    cout << "   GENERANDO ANIMACION GIF" << endl;
    cout << "===========================================" << endl;
    
    // Crear script de Gnuplot para la animación
    ofstream script("temp_animacion.gnu");
    
    script << "# Script para animación GIF de posición vs tiempo\n";
    script << "set terminal gif animate delay 10 optimize size 800,600\n";
    script << "set output '../resultados/gif/posicion_animacion.gif'\n\n";
    
    script << "set title 'Oscilador Armónico Amortiguado: Evolución Temporal'\n";
    script << "set xlabel 'Tiempo (s)'\n";
    script << "set ylabel 'Posición (m)'\n";
    script << "set grid\n";
    script << "set key top right\n";
    script << "set style line 1 lc rgb '#0060ad' lt 1 lw 2\n\n";
    
    script << "# Leer datos del archivo\n";
    script << "stats '../resultados/listas/posicion_vs_tiempo.txt' nooutput\n";
    script << "N = STATS_records\n\n";
    
    script << "# Configurar rango del eje x\n";
    script << "set xrange [0:STATS_max_x]\n";
    
    script << "# Configurar rango del eje y\n";
    script << "stats '../resultados/listas/posicion_vs_tiempo.txt' using 2 nooutput\n";
    script << "ymax = STATS_max * 1.1\n";
    script << "ymin = STATS_min * 1.1\n";
    script << "set yrange [ymin:ymax]\n\n";
    
    script << "# Crear animación cuadro por cuadro\n";
    script << "do for [i=0:N-1:10] {  # Incremento de 10 para animación más rápida\n";
    script << "    plot '../resultados/listas/posicion_vs_tiempo.txt' \\\n";
    script << "        every ::0::i \\\n";
    script << "        using 1:2 with lines ls 1 title sprintf('t = %.2f s', column(1)), \\\n";
    script << "    '' every ::i::i \\\n";
    script << "        using 1:2 with points pt 7 ps 1.5 lc rgb 'red' title ''\n";
    script << "}\n\n";
    
    script << "# Último cuadro con toda la trayectoria\n";
    script << "plot '../resultados/listas/posicion_vs_tiempo.txt' \\\n";
    script << "    using 1:2 with lines ls 1 title 'Trayectoria completa'\n";
    
    script.close();
    
    cout << "  Generando animación GIF..." << endl;
    cout << "  Esto puede tomar unos segundos..." << endl;
    
    // Ejecutar Gnuplot para generar el GIF
    int resultado = system("gnuplot temp_animacion.gnu");
    
    if (resultado == 0) {
        cout << "  ✓ Animación generada: ../resultados/gif/posicion_animacion.gif" << endl;
    } else {
        cout << "  ✗ Error al generar la animación" << endl;
        cout << "  Asegúrese de tener Gnuplot instalado y con soporte GIF" << endl;
    }
    
    // Eliminar archivo temporal
    remove("temp_animacion.gnu");
    
    cout << "\n===========================================" << endl;
    cout << "   ANIMACION COMPLETADA" << endl;
    cout << "===========================================" << endl;
}

// Función para generar GIF más simple y rápido
void generarGifPosicionTiempo() {
    cout << "\n===========================================" << endl;
    cout << "   GENERANDO GIF SIMPLIFICADO" << endl;
    cout << "===========================================" << endl;
    
    // Crear script más simple para GIF
    ofstream script("temp_gif_simple.gnu");
    
    script << "# Script simplificado para GIF\n";
    script << "set terminal gif animate delay 5 size 800,600\n";
    script << "set output '../resultados/gif/posicion_vs_tiempo.gif'\n\n";
    
    script << "set title 'Posición vs Tiempo - Oscilador Amortiguado'\n";
    script << "set xlabel 'Tiempo (s)'\n";
    script << "set ylabel 'Posición (m)'\n";
    script << "set grid\n";
    script << "set key off\n\n";
    
    script << "# Configurar rango fijo para mejor animación\n";
    script << "stats '../resultados/listas/posicion_vs_tiempo.txt' using 1:2 nooutput\n";
    script << "set xrange [STATS_min_x:STATS_max_x]\n";
    script << "set yrange [STATS_min_y-0.1:STATS_max_y+0.1]\n\n";
    
    script << "# Animación progresiva\n";
    script << "n = 100  # Número de cuadros\n";
    script << "do for [i=0:n] {\n";
    script << "    j = int(i * STATS_records / n)\n";
    script << "    plot '../resultados/listas/posicion_vs_tiempo.txt' \\\n";
    script << "        every ::0::j \\\n";
    script << "        using 1:2 with lines lw 2 lc rgb 'blue' \\\n";
    script << "        title sprintf('Progreso: %.0f%%', 100.0*i/n)\n";
    script << "}\n";
    
    script.close();
    
    cout << "  Generando GIF simplificado..." << endl;
    
    // Ejecutar Gnuplot
    system("gnuplot temp_gif_simple.gnu");
    
    // Eliminar archivo temporal
    remove("temp_gif_simple.gnu");
    
    cout << "  ✓ GIF generado: ../resultados/gif/posicion_vs_tiempo.gif" << endl;
    cout << "\n===========================================" << endl;
    cout << "   GIFS DISPONIBLES EN resultados/gif/" << endl;
    cout << "===========================================" << endl;
    cout << "\nArchivos generados:" << endl;
    cout << "  ✓ posicion_animacion.gif  (animación detallada)" << endl;
    cout << "  ✓ posicion_vs_tiempo.gif  (animación simplificada)" << endl;
    cout << "\nPuede visualizar estos archivos con:" << endl;
    cout << "  • Navegador web" << endl;
    cout << "  • Visor de imágenes" << endl;
    cout << "  • Reproductor multimedia" << endl;
    cout << "\n===========================================" << endl;
}