#!/use/bin/python
import re
import sys
import pylab as pl
import os
positive_words=[]
fpos=open("positive-words.txt","r");
for i in  fpos.read().split('\n'):
	if len(i)>1:
		positive_words.append(i);

negative_words=[]
fneg=open("negative-words.txt","r");
for i in  fneg.read().split('\n'):
	if len(i)>1:
		negative_words.append(i);



fp=open('data.txt');
post=fp.read()
posts=post.split('\n\n')

prog = re.compile('[0-9]?[0-9]:[0-9][0-9][ ]?(pm|am)')


data=[]
time=[]
plc=[]
p=''
for i in post.split('\n'):	
	m=prog.search(i)
	if m:
		pos=i.find("am")
		if pos>0:
			plc.append(i[pos+3:].split(' ')[0])
		pos=i.find("pm")
		if pos>0:
			plc.append(i[pos+3:].split(' ')[0])
		time.append(m.group(0))
		data.append(p)
		p=''
	else :
		p+=i	




hour=[]
min=[]

for i in time:
	aloc=i.find("am")
	if aloc>0:
		tmp=i[0:aloc].split(":")
		hour.append(tmp[0])
		min.append(tmp[1])
	ploc=i.find("pm")
	if ploc>0:
		tmp=i[0:ploc].split(":")
		if int(tmp[0])==12:
			hour.append(tmp[0])
		else:
			hour.append(int(tmp[0])+12)
		min.append(tmp[1])


slot=[]		
for i in range(0,24):
	slot.append([0,0,0])

pos=[]
neg=[]
psum=0
nsum=0

for i in range(0,len(data)):
	p=0
	n=0;	
	for j in positive_words: 
		pc=(data[i].lower()).count(j)
		if pc >0 and len(j)>2:
			p+=pc
	for j in negative_words:
		nc=(data[i].lower()).count(j)
		if nc >0 and len(j)>2:
			n+=nc
	pos.append(p)
	neg.append(n)
	psum+=pos[i]
	nsum+=neg[i]	
	diff=pos[i]-neg[i]
	if diff>0:
		slot[int(hour[i])][0]+=1;
	elif diff<0:
		slot[int(hour[i])][1]+=1;
	else :
		slot[int(hour[i])][2]+=1;
t=0
hmax=-1
smax=-1
nmax=-1

hindex=-1
sindex=-1
nindex=-1

for i in range(0,len(slot)):
	if slot[i][0]>hmax:
		hmax=slot[i][0]
		hindex=i
	if slot[i][1]>smax:
		smax=slot[i][1]
		sindex=i
	if slot[i][2]>nmax:
		nmax=slot[i][2]
		nindex=i	
	


def print_comment(norm):
	if norm>0.0 :
		return "HAPPY!"
	elif norm<0.0	:
		return "SAD!"
	else :
		return "MIXED!"


norm=[]
for i in slot:
	sum=(i[0]+i[1]+i[2]);
	if sum==0:
		norm.append(0);
	else:
		norm.append(float(1*i[0]-1*i[1]+0*i[2])/float(sum))

happy=0
sad=0
mixed=0
for i in slot:
	happy+=i[0]
	sad+=i[1]
	mixed+=i[2]
print "Happy post= ",happy," Sad Post= ",sad," Mixed post= ",mixed

print "Peak post hour for Happy ",hindex,"-",(hindex+1)
print "Peak post hour for Sad ",sindex,"-",(sindex+1)
print "Peak post hour for Neutral ",nindex,"-",(nindex+1)

print "-------------------------------------------------------------------------------------------------------"
print "Interval         |    :)           |       :(       |     ;(    |      Modd       | Normalized Value   |"
print "--------------------------------------------------------------------------------------------------------"
for i in range(0,len(slot)):
	if i<10:
		l1='0'+str(i)
	else:
		l1=str(i)
	if i+1<10:
		l2='0'+str(i+1)
	else :
		l2=str(i+1)
	print l1,":00-",l2,":00   |	  ",slot[i][0],"      |	     ",slot[i][1],"    |	  ",slot[i][2],"	|	",print_comment(norm[i]).ljust(10)," | ",str(norm[i]).ljust(15),"|"
print "-------------------------------------------------------------------------------------------------------"


place=[]
for i in plc:
	if i not in place and len(i)>1:
		place.append(i);
		

pslot=[]		
for i in range(0,len(place)):
	pslot.append([0,0,0])

ppos=[]
pneg=[]
ppsum=0
pnsum=0

for i in range(0,len(data)):
	p=0
	n=0;	
	for j in positive_words: 
		pc=(data[i].lower()).count(j)
		if pc >0 and len(j)>2:
			p+=pc
	for j in negative_words:
		nc=(data[i].lower()).count(j)
		if nc >0 and len(j)>2:
			n+=nc
	ppos.append(p)
	pneg.append(n)
	ppsum+=ppos[i]
	pnsum+=pneg[i]	
	diff=ppos[i]-pneg[i]
	if len(plc[i])>0:
		if diff>0:
			pslot[place.index(plc[i])][0]+=1;
		elif diff<0:
			pslot[place.index(plc[i])][1]+=1;
		else :
			pslot[place.index(plc[i])][2]+=1;


pnorm=[]
for i in pslot:
	sum=(i[0]+i[1]+i[2]);
	if sum==0:
		pnorm.append(0);
	else:
		pnorm.append(float(1*i[0]-1*i[1]+0*i[2])/float(sum))

phappy=0
psad=0
pmixed=0





print "---------------------------------------------------------------------------------------------------------------------"
print "Place                      |       :)       |       :(       |     ;(    |      Modd         | Normalized Value      |"
print "---------------------------------------------------------------------------------------------------------------------"
for i in range(0,len(pslot)):	
	print place[i].ljust(20),"     |	  ",str(pslot[i][0]).ljust(2),"      |	     ",str(pslot[i][1]).ljust(2),"    |	  ",str(pslot[i][2]).ljust(2),"	|	",print_comment(pnorm[i]).ljust(10)," | ",str(pnorm[i]).ljust(20),"|"
print "---------------------------------------------------------------------------------------------------------------------"



x=range(24)
d1=open("hour.data","w")
for i in range(0,24):
	d=str(x[i])+" "+str(norm[i])+"\n";
	d1.write(d);


pl.figure()

pl.plot(x,norm)
pl.xlim(-0.5,23.5)
pl.ylim(-1.2,1.2)
pl.title("sentiment analysis per hour")
pl.xlabel("Hours")
pl.ylabel("Nomalized Feeling")
#pl.show()


pl.figure()
y=range(5)
d2=open("city.data","w")
for i in range(0,len(place)):
	d=str(y[i])+" "+place[i]+" "+str(pnorm[i])+"\n";
	d2.write(d);
pl.bar(y, pnorm, align='center')
pl.xticks(y, place)
pl.ylim(-1.2,1.2)
pl.title("sentiment analysis per city")
pl.xlabel("city")
pl.ylabel("Nomalized Feeling")
pl.show()


