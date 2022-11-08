#! /bin/bash

read -p "Enter a year: " year

if [ $(($year%100)) -ne 0 ] && [ $(($year%4)) -eq 0 ] || [ $(($year%400)) -eq 0 ]
then
	echo "Leap year"
else
	echo "Not leap year"
fi
