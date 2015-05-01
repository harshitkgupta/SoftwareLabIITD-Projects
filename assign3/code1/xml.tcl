#!/usr/bin/tclsh
## \file xml.tcl
# File documentation.
#\verbatim
# Startup code:\
#\endverbatim

#\code
## This script is required for Weather Processing

package require xml
##package for dom(Document Object Model Processing
package require dom
package require http
package require tdom
##package for Mysql Connection And Query
package require mysqltcl
set m [mysqlconnect -user root  -password 123456]
mysqluse $m weather
#set xmlSrc [http::data [http::geturl http://weather.yahooapis.com/forecastrss?w=2442047&u=c ] ]
set query [lindex $argv 0]
set appid {[_1cH2kXV34FL_bAdDqGfPMn3y5t7uCUwqNSjWUC8x81suAiFT33B7dksj3Wb.ZN66BRdo8V2khicXM0WliWFi2mbk0rHAVE-]}
## finding Woeid of location using yahoo NetGeoLocation API
set url "http://where.yahooapis.com/v1/places.q($query)?appid=$appid"
##saving results to location.xml 
exec wget -O location.xml $url  2>&1 >/dev/null
## parsing location.xml to get woeid of a location
set f [open location.xml r]
set xmlSource [read $f ]
set xmlSource [string trim $xmlSource]
set d [dom parse -html $xmlSource]
set r [$d documentElement ]

set woeid [$r selectNodes {string(/places/place/woeid)}]
##saving weather results to forecast.xml using Yahoo Weather API
exec wget -O forecast.xml "http://weather.yahooapis.com/forecastrss?w=$woeid&u=c" 2>&1 >/dev/null

set fd [open forecast.xml r]
set xmlSrc [read $fd]
set xmlSrc [string trim $xmlSrc]
set dom [dom parse $xmlSrc]
set root [$dom documentElement "rss"]
##parsing forecast.xml to get city ,region and country
set title [$root selectNodes {string(/rss/channel/title)}]
set location(city) [$root selectNodes {string(/rss/channel/yweather:location/@city)}] 
set location(region) [$root selectNodes {string(/rss/channel/yweather:location/@region)}] 
set location(country) [$root selectNodes {string(/rss/channel/yweather:location/@country)}] 

set qw "delete from location where woeid='$woeid'"
set q1 [ mysqlexec $m  $qw  ] 
##inserting woied and location into table location
set quer "insert into location values ('$woeid','$location(city)','$location(region)','$location(country)')" 
set r [mysqlexec $m  $quer ]


## paring forecast.xml to get temperature distance pressure and speed
set units(temperature) [$root selectNodes {string(/rss/channel/yweather:units/@temperature)}] 
set units(distance) [$root selectNodes {string(/rss/channel/yweather:units/@distance)}] 
set units(pressure) [$root selectNodes {string(/rss/channel/yweather:units/@pressure)}] 
set units(speed) [$root selectNodes {string(/rss/channel/yweather:units/@pressure)}] 
## paring forecast.xml to get wind Chill, direction,Speed
set wind(chill) [$root selectNodes {string(/rss/channel/yweather:wind/@chill)}] 
set wind(direction) [$root selectNodes {string(/rss/channel/yweather:wind/@direction)}] 
set wind(speed) [$root selectNodes {string(/rss/channel/yweather:wind/@speed)}] 
## paring forecast.xml to get humidity , visibility, pressure,rising of atmosphere
set atmosphere(humidity) [$root selectNodes {string(/rss/channel/yweather:atmosphere/@humidity)}] 
set atmosphere(visibility) [$root selectNodes {string(/rss/channel/yweather:atmosphere/@visibility)}] 
set atmosphere(pressure) [$root selectNodes {string(/rss/channel/yweather:atmosphere/@pressure)}] 
set atmosphere(rising) [$root selectNodes {string(/rss/channel/yweather:atmosphere/@rising)}]
 ## paring forecast.xml to get sunset and sunrise results 
set astronomy(sunrise) [$root selectNodes {string(/rss/channel/yweather:astronomy/@sunrise)}] 
set astronomy(sunset) [$root selectNodes {string(/rss/channel/yweather:astronomy/@sunset)}]
## paring forecast.xml to get current temperature and weather condition
set condition(text) [$root selectNodes {string(/rss/channel/item/yweather:condition/@text)}] 
set condition(code) [$root selectNodes {string(/rss/channel/item/yweather:condition/@code)}] 
set condition(temp) [$root selectNodes {string(/rss/channel/item/yweather:condition/@temp)}] 
set condition(date) [$root selectNodes {string(/rss/channel/item/yweather:condition/@date)}] 
##saving todays weather result to todays.txt
set ou [open today.txt w]
puts $ou "WIND       \t\t Chill \t:\t $wind(chill)"
puts $ou "Parameters \t\tDirection \t:\t $wind(direction)"
puts $ou "\t\t Speed \t:\t $wind(speed) $units(speed)"

puts $ou " Atmosphere \t \tHumidity \t:\t $atmosphere(humidity)"
puts $ou "Parametres \t\tVisibility \t:\t $atmosphere(visibility)"
puts $ou "\t\t\t Pressure \t:\t $atmosphere(pressure) $units(pressure)"
puts $ou "\t\t\tRising   \t:\t $atmosphere(rising)"

puts $ou "Astronomy \t\tSunrise \t:\t $astronomy(sunrise)"
puts $ou "Parameters \t\tSunset  \t:\t $astronomy(sunset)"
puts $ou "\t\tWeather Conditions\t"
puts $ou "Date       \t:\t $condition(date)"
puts $ou "Temperature \t:\t $condition(temp) $units(temperature)"
puts $ou "Conditions \t:\t $condition(text)"

close $ou
## paring forecast.xml to get Future Weather Predictions of 5 days
foreach forecast [$root selectNodes "/rss/channel/item/yweather:forecast"] {
set day [$forecast getAttribute day]
set date [$forecast  getAttribute date]
set low [$forecast  getAttribute low]
set high [$forecast getAttribute high]
set text [$forecast  getAttribute text]
set code [$forecast  getAttribute code]
set qur "delete  from forecast where woeid='$woeid' and date='$date'"
set q [ mysqlsel $m  $qur -flatlist ] 
## inserting Weather predictions into table forecast
set quer "insert into forecast values ('$woeid','$date','$day','$low','$high','$text','$code')" 
set r [mysqlexec $m  $quer ]
} 
## reading city region,country from mysql database
set o [open loc.txt w]
set out [open todays.txt w]
set qer "select city,region,country from location where woeid='$woeid'"
set q [mysqlsel $m $qer -flatlist ]
puts $o $q
## reading  weather Predictions from mysql database and save into file
set qer "select date,day,low,high,text from forecast where woeid='$woeid'"
foreach {a b c d e} [mysqlsel $m $qer -flatlist ] {
puts $out "$a \t   $b \t\t$c \t\t$d \t$e"
}
close $o
close $out
source abcd.tcl


 


