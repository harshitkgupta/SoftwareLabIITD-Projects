set terminal png    
set output  "per_hour_analysis.png"
set grid
set title "Sentiment Analyis of posts"
set xlabel "Time (hour)"
set ylabel "Normalized value of sentiment "
plot    "hour.data" using 1:2  title "Sentiment Analysis per hour" with linespoints 



