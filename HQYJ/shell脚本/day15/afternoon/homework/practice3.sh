#! /bin/bash

read -p  "Enter your grade: " grade

if [ $grade -ge 0 -a $grade -lt 60 ]
then
	echo "E"
elif [ $grade -ge 60 -a $grade -lt 70 ]
then
	echo "D"
elif [ $grade -ge 70 -a $grade -lt 80 ]
then
	echo "C"
elif [ $grade -ge 80 -a $grade -lt 90 ]
then
	echo "B"
elif [ $grade -ge 90 -a $grade -lt 100 ]
then
	echo "A"
else
	echo "error"

fi
