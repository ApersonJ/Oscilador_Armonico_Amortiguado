set terminal pngcairo size 800,600
set output '../results/x(t).png'
set title 'Posicion x vs Tiempo'
set xlabel 'Tiempo (s)'
set ylabel 'x (m)'
set grid
plot '../results/oscillator.dat' index 0 every ::1 using 1:2 with lines lw 2 lc rgb 'blue' title 'x(t)'

#grafico de v(t)

set terminal pngcairo size 800,600
set output '../results/v(t).png'
set title 'Velocidad vs Tiempo'
set xlabel 'Tiempo (s)'
set ylabel 'v (m/s)'
set grid
plot '../results/oscillator.dat' index 0 every ::1 using 1:3 with lines lw 2 lc rgb 'blue' title 'x(t)'

#grafico de v(x,t)

set terminal pngcairo size 800,600
set output '../results/v(x,t).png'
set title 'v(x, t)'
set xlabel 'Tiempo (s)'
set ylabel 'x (m)'
set zlabel 'v (m/s)'
set grid
splot '../results/oscillator.dat' index 0 every ::1 using 1:2:3 with lines lw 2 lc rgb 'blue' title 'x(t)'

#grafico de momento contra x

set terminal pngcairo size 800,600
set output '../results/p(x).png'
set title 'p(x)'
set xlabel 'x (m)'
set ylabel 'p (kg(m/s))'
set grid
plot '../results/oscillator.dat' index 0 every ::1 using 2:4 with lines lw 2 lc rgb 'blue' title 'x(t)'