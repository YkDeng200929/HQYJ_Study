#! /bin/bash

i=0
max=$1
min=$1
count=0
avg=0
for i in $@
do
	if [ $i -gt $max ]
	then
		max=$i
	fi
	if [ $i -lt $min ]
	then
		min=$i
	fi
	let count++ avg+=i
done
let avg/=count
printf "max: %d min: %d avg: %d\n" $max $min $avg
