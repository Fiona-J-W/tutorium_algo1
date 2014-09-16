#!/usr/bin/gnuplot

set key top left

set ylabel "Zeit in Nanosekunden"
set xlabel "Elemente"


# set logscale x 10
# set logscale y 10

plot "linear.dat" using 1:2 with points title "Lineare Suche", \
	"iterative.dat" using 1:2 with points title "Iterative binäre Suche",\
	"recursive.dat" using 1:2 with points title "Rekursive binäre Suche"

pause -1
