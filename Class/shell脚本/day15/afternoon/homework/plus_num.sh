#! /bin/bash

read -p "Enter a number: " num
i=1
count=0
while [ $i -ne $num ]
do
	let count+=i
	let i++
done

let count+=i

echo "sum: $count"
