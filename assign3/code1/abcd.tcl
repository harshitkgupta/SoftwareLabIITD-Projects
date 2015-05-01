## \file abcd.tcl
# File documentation.
#\verbatim
# Startup code:\
#\endverbatim

# This script is used for showing Weather Results into a window
#\code
package require Tk
set font(Button)      {Helvetica -22 bold}
 set font(Checkbutton) {Helvetica -22 bold}
 set font(Radiobutton) {Helvetica -22 bold}
 set font(Label)       {Helvetica -22 bold}
 set font(Entry)       {Helvetica -22}
 set font(Listbox)     {Helvetica -22 bold}
 set font(Menuentry)   {Helvetica -22 bold}
 set font(Menu)        {Helvetica -22 bold}
 set font(Menubutton)  {Helvetica -22 bold}
 set font(Message)     {Helvetica -22 bold}
 set font(Scale)       {Helvetica -22 bold}
 set font(Text)        {Courier   -20}
wm geometry  .   1300x700+10+10
wm title  .   "Weather App"


destroy .myArea
set f [frame .myArea -borderwidth 5 -background blue]

#setting first text field for today weather 
text $f.t1 -bd 2 -bg white -height 15 -font $font(Text)
pack $f.t1

pack $f -side top -expand true -fill both 


set f5 [open today.txt r]
set dat [read $f5]
puts $dat

$f.t1 insert end $dat tag0

#setting second text field for All weather Predictions

text $f.t -bd 2 -bg white -height 30 -font $font(Text)
pack $f.t

pack $f -side top -expand true -fill both 


set f2 [open loc.txt r]
set d [read $f2]
puts $d
set f3 [open todays.txt r]
set data [read $f3]
puts $data
#putting Location results into window
$f.t insert end "\tCity  Region  Country\n" tag0
$f.t insert end "\t$d\n" tag0
#putting Weather results into window
$f.t insert end "Date \t\tDay \t LowTemp \t HighTemp     Condition \n" tag0
$f.t insert end $data tag0

destroy .menubar
menu .menubar
. config -menu .menubar


set File [menu .menubar.mFile]
.menubar add cascade -label File  -menu  .menubar.mFile

$File add command -label Quit -command exit
#\endcode
