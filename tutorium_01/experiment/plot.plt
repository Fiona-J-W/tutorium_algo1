#!/usr/bin/gnuplot

set key top left

set ylabel "Zeit in Nanosekunden"
set xlabel "Elemente"


# set logscale x 10
# set logscale y 10

plot \
	"data.dat" using 1:3 with points title "Lineare Suche", \
	"data.dat" using 1:5 with points title "std::find", \
	"data.dat" using 1:2 with points title "Binäre Suche (iterativ)", \
	"data.dat" using 1:4 with points title "Binäre Suche (rekursiv)", \
	"data.dat" using 1:6 with points title "std::lower_bound"

pause -1
