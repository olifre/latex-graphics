set log x
set log y

set grid xtics mxtics ytics mytics \
    lt 0 lw 3 lc rgbcolor "#444444", \
    lt 0 lw 2 lc rgbcolor "#666666"
set grid back
#set xtics out
set mxtics
#set ytics out nomirror
set mytics
#set y2tics out
#set my2tics

set xlabel "$\\sqrt{{s_{{t}}}}$"
set ylabel "$q_{{p}}$"

set key box bottom left

plot 'sample.dat' u 1:2 title "Test data" w l
