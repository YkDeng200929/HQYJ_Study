#! /bin/bash

read -p "enter two number: " num1 num2

if [ $num1 -gt $num2 ]
then
	echo "$num1"
elif [ $num1 -lt $num2 ]
then
	echo "$num2"
else
	echo "num1 = num2"
fi

read -p "Enter a number again: " num3

if [ $num3%2 = 1 ]
then
	echo "ji"
else
	echo "ou"
fi
