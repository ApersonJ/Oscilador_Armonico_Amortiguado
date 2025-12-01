set terminal pngcairo size 800,600
set output '../results/VelvsTiempo.png'
set title 'Velocidad vs Tiempo'
set xlabel 'Tiempo (s)'
set ylabel 'v (m/s)'
set grid
plot '../results/oscillator.dat' index 0 every ::1 using 1:3 with lines lw 2 lc rgb 'blue' title 'x(t)'