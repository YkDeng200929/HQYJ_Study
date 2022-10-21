#! /bin/bash

correct_name=linux
correct_pass=1
chance=1
while [ $chance -lt 4 ]
do
	read -p "Enter name and passwd: " name passwd
	if [ "$name" == "$correct_name" ] && [ "$passwd" == "$correct_pass" ]
	then
		echo "correct"
	else
		echo "error"
	fi
	let chance++
done
