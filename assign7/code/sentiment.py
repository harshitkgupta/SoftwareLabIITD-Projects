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
place=[]
p=''
for i in post.split('\n'):	
	m=prog.search(i)
	if m:
		time.append(m.group(0))
		place.append(m.group(1))
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


print "Interval          :)          :(          ;(            Comment    Normalized Value"
for i in range(0,len(slot)):
	if i<10:
		l1='0'+str(i)
	else:
		l1=str(i)
	if i+1<10:
		l2='0'+str(i+1)
	else :
		l2=str(i+1)
	print l1,"-",l2," 	  ",slot[i][0],"	     ",slot[i][1],"	  ",slot[i][2],"		",print_comment(norm[i])," ",norm[i]





f=open("norm.txt","w")
for i in range(0,len(norm)):
	f.write(str(norm[i])+"\n")
x=range(24)
pl.figure()

pl.plot(x,norm)
pl.xlim(-0.5,23.5)
pl.ylim(-1.2,1.2)
pl.title("sentiment analysis per hour")
pl.xlabel("Hours")
pl.ylabel("Nomalized Feeling")
pl.show()



