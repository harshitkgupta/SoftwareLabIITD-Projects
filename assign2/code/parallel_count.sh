#!/bin/bash 

function count_match
{
	bString=$1
	sString=$2
	c=0
	l1=`expr ${#bString}`
	l2=`expr ${#sString}`
	limit=`expr $l1 - $l2`
	for i in $(seq 0 $limit)
	do
		tString=${bString:$i:$l2}
		if [ -n $tString -a  $tString = $sString ]
		then
		let c=`expr $c + 1`
		fi
	done
	echo Thread Id $$ and $c match found at `date -u`
	echo $c >>tmp$3

}
if [ $# != 3 ]
then
	echo usage :`basename $0` "<BigString> <SubString> <NO_OF_THREADS>"
	exit 1
fi
bigString=$1
subString=$2
NO_OF_THREADS=$3
length1=`expr ${#bigString}`
length2=`expr ${#subString}`
if [ $length1 -lt $length2 ]
then
	echo "Length of subString can not be greater than BigString"
	exit 1
fi
if [ $NO_OF_THREADS -lt 1 ]
then 
	echo "Number of threads can not be less than one"
	exit 1
fi

div=`expr $length1 / $NO_OF_THREADS + 1`

while [ $div -lt $length2 ]
do
	NO_OF_THREADS=`expr $NO_OF_THREADS -1`
	div=`expr $length1 / $NO_OF_THREADS + 1`
done

t=`expr $NO_OF_THREADS - 1` 

seg=`expr $length1 - $div \* $t`

if [ $seg -lt $length2 ]
then
		NO_OF_THREADS=`expr $NO_OF_THREADS - 1`
fi

lim=`expr $NO_OF_THREADS - 1`
len=`expr $div + $length2 - 1`
for i in $(seq 0 $lim)
do
	index=`expr $div \* $i`	
	tempString=${bigString:$index:$len}
	count_match $tempString $subString $$ &
done  
wait
count=0    	
while read line
do
	count=`expr $count + $line`
done < tmp$$
echo "******   $count  times occurances found ******" 

