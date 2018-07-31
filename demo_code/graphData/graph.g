set key top left
set xl "sum number"
set yl "time(ms)"

plot "nomal_1_log.txt" w l
replot "prefix_1_log.txt" w l
replot "nomal_2_log.txt" w l
replot "prefix_2_log.txt" w l
replot "prefix_3_log.txt" w l


set terminal png 
set output "result.png"
replot
