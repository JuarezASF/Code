set terminal epslatex size 14cm,10cm color colortext 'phv,9'	header '\definecolor{t}{rgb}{0.5,0.5,0.5}'

  

set title "Posição(m) estimada por filtragem de Kalman"
 set xlabel 'tempo(s)' 
 set ylabel 'Posição(m)' 

set output "../images/graphSxT.tex"
plot 'X.dat' using 1:2 w points lt 1 lc 0 t 'posição estimada'



set title "Velocidade Medida e Filtrada vs Tempo(s)"
 set xlabel 'tempo(s)' 
 set ylabel 'V($\frac{m}{s}$)' 

set output "../images/graphVxT.tex"

plot 'X.dat' using 1:3 w linespoints lt 6 lw 4 lc 0 t 'velocidade de Kalman', \
 'Z.dat' using 1:2 w points lt 6 lw 4 lc rgb 'red' t 'velocidade medida'