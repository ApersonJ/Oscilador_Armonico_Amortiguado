set terminal pngcairo size 800,600
set output '../results/graficas/momentum_grafica.png'
set xlabel 'Posicion'
set ylabel 'Momentum'
set key outside
plot '../results/listas/datos_derivadas.dat' using 2:4 with lines title 'momentum'
