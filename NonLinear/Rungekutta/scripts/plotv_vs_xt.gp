set terminal pngcairo size 800,600
set output '../results/v(x,t).png'
set title 'v(x, t)'
set xlabel 'Tiempo (s)'
set ylabel 'x (m)'
set zlabel 'v (m/s)'
set grid
splot '../results/oscillator.dat' index 0 every ::1 using 1:2:3 with lines lw 2 lc rgb 'blue' title 'x(t)'