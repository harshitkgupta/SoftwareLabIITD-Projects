set terminal png    
set output  "per_city_analysis.png"
set grid
set boxwidth 0.5
set style fill solid 	
set title "Sentiment Analyis of posts"
set xlabel "Time (hour)"
set ylabel "Normalized value of sentiment "
plot    "city.data" using 1:3:xtic(2)  title "Sentiment Analysis per city" with boxes



