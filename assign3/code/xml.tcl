#!/usr/bin/tclsh
package require xml
package require dom
package require http
package require tdom
package require mysqltcl
set m [mysqlconnect -user root  -password 123456]
mysqluse $m weather
#set xmlSrc [http::data [http::geturl http://weather.yahooapis.com/forecastrss?w=2442047&u=c ] ]
set query [lindex $argv 0]
set appid {[_1cH2kXV34FL_bAdDqGfPMn3y5t7uCUwqNSjWUC8x81suAiFT33B7dksj3Wb.ZN66BRdo8V2khicXM0WliWFi2mbk0rHAVE-]}
set url "http://where.yahooapis.com/v1/places.q($query)?appid=$appid"
 
exec wget -O location.xml $url  2>&1 >/dev/null

set f [open location.xml r]
set xmlSource [read $f ]
set xmlSource [string trim $xmlSource]
set d [dom parse -html $xmlSource]
set r [$d documentElement ]

set woeid [$r selectNodes {string(/places/place/woeid)}]

exec wget -O forecast.xml "http://weather.yahooapis.com/forecastrss?w=$woeid&u=c" 2>&1 >/dev/null

set fd [open forecast.xml r]
set xmlSrc [read $fd]
set xmlSrc [string trim $xmlSrc]
set dom [dom parse $xmlSrc]
set root [$dom documentElement "rss"]
set title [$root selectNodes {string(/rss/channel/title)}]
set location(city) [$root selectNodes {string(/rss/channel/yweather:location/@city)}] 
set location(region) [$root selectNodes {string(/rss/channel/yweather:location/@region)}] 
set location(country) [$root selectNodes {string(/rss/channel/yweather:location/@country)}] 

set qw "delete from location where woeid='$woeid'"
set q1 [ mysqlexec $m  $qw  ] 
set quer "insert into location values ('$woeid','$location(city)','$location(region)','$location(country)')" 
set r [mysqlexec $m  $quer ]



set units(temperature) [$root selectNodes {string(/rss/channel/yweather:units/@temperature)}] 
set units(distance) [$root selectNodes {string(/rss/channel/yweather:units/@distance)}] 
set units(pressure) [$root selectNodes {string(/rss/channel/yweather:units/@pressure)}] 
set units(speed) [$root selectNodes {string(/rss/channel/yweather:units/@pressure)}] 

set wind(chill) [$root selectNodes {string(/rss/channel/yweather:wind/@chill)}] 
set wind(direction) [$root selectNodes {string(/rss/channel/yweather:wind/@direction)}] 
set wind(speed) [$root selectNodes {string(/rss/channel/yweather:wind/@speed)}] 

set atmosphere(humidity) [$root selectNodes {string(/rss/channel/yweather:atmosphere/@humidity)}] 
set atmosphere(visibility) [$root selectNodes {string(/rss/channel/yweather:atmosphere/@visibility)}] 
set atmosphere(pressure) [$root selectNodes {string(/rss/channel/yweather:atmosphere/@pressure)}] 
set atmosphere(rising) [$root selectNodes {string(/rss/channel/yweather:atmosphere/@rising)}]
 
set astronomy(sunrise) [$root selectNodes {string(/rss/channel/yweather:astronomy/@sunrise)}] 
set astronomy(sunset) [$root selectNodes {string(/rss/channel/yweather:astronomy/@sunset)}]
 
set condition(text) [$root selectNodes {string(/rss/channel/yweather:condition/@text)}] 
set condition(code) [$root selectNodes {string(/rss/channel/yweather:condition/@code)}] 
set condition(temp) [$root selectNodes {string(/rss/channel/yweather:condition/@temp)}] 
set condition(date) [$root selectNodes {string(/rss/channel/yweather:condition/@date)}] 






foreach forecast [$root selectNodes "/rss/channel/item/yweather:forecast"] {
set day [$forecast getAttribute day]
set date [$forecast  getAttribute date]
set low [$forecast  getAttribute low]
set high [$forecast getAttribute high]
set text [$forecast  getAttribute text]
set code [$forecast  getAttribute code]
set qur "delete  from forecast where woeid='$woeid' and date='$date'"
set q [ mysqlsel $m  $qur -flatlist ] 

set quer "insert into forecast values ('$woeid','$date','$day','$low','$high','$text','$code')" 
set r [mysqlexec $m  $quer ]
} 
set o [open loc.txt w]
set out [open todays.txt w]
set qer "select city,region,country from location where woeid='$woeid'"
set q [mysqlsel $m $qer -flatlist ]
puts $o $q
set qer "select date,day,low,high,text from forecast where woeid='$woeid'"
foreach {a b c d e} [mysqlsel $m $qer -flatlist ] {
puts $out "$a \t   $b \t\t$c \t\t$d \t$e"
}
close $o
close $out
source abcd.tcl


 


