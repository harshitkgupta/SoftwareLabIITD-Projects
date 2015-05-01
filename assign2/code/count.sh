#!/bin/bash 
if [ $# != 2 ]
then
	echo usage :`basename $0` "<BigString> <SubString>"
	exit 1
fi
bigString=$1
subString=$2
length1=`expr ${#bigString}`
length2=`expr ${#subString}`
if [ $length1 -lt $length2 ]
then
	echo "Length of subString can not be greater than BigString"
	exit 1
fi

limit=`expr $length1 - $length2 + 1`
c=0
for i in $(seq 0 $limit)
do
	tempString=${bigString:$i:$length2}
	if [ $tempString = $subString ]
	then
	 c=`expr $c + 1`
	fi
done
echo "******   $c  times occurances found ******" 

