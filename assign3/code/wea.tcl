#!/usr/bin/wish

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
 set font(Text)        {Courier   -22}
wm title . "Weather Forecast App" 
frame .top -borderwidth 10 
pack .top -side top -fill x

button .top.quit -text Quit -command exit -font $font(Button)
set but [button .top.but -text "Show Weather" -font $font(Button) -command showWeather]
pack .top.quit .top.but -side right

label .top.l -text Location  -padx 0 -font $font(Label)
entry .top.q -width 20 -relief sunken -textvariable query -font $font(Entry)
pack .top.l -side left -fill x -expand true
pack .top.q -side left
focus .top.q 

frame .t
set log [text .t.log -width 80 -height 10 -borderwidth 2 -relief raised -setgrid  true -yscrollcommand {.t.scroll set} ]
scrollbar .t.scroll -command {.t.log yview }
pack .t.scroll -side right -fil y
pack .t.log -side left -fill both -expand true
pack .t -side top -fill both -expand true

proc showWeather {} {
global query
exec ./xml.tcl $query 
	


}





