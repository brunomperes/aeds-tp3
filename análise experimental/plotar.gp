set terminal postscript eps 28 enhanced color
set style fill solid 1.00 border
set encoding utf8
set output "tempo.eps"
set style fill solid 1.00 border
set title "Tempo de execução"
set xrange[0:]
set yrange[0:]
set xlabel "Tamanho t da entrada"
set ylabel "Tempo de execução (segs.)"
plot 'Analise.txt' using 1:4 notitle with linespoints pointsize 0.4 pt 7
