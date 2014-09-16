#!/usr/bin/gnuplot

set key top left

set ylabel "Zeit in Nanosekunden"
set xlabel "Elemente"


 set logscale x 2
 set logscale y 10

plot \
	"vec.dat"  using 1:2 with points title "std::vector", \
	"list.dat" using 1:2 with points title "std::list"

pause -1
