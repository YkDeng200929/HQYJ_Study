#! /bin/bash

num1=2
num2=3
echo $[num1 * num2]
echo "num1: $num1, num2: $num2"

num3=$1
num4=$2

echo "num3=$num3, num4=$num4"
echo "num3 x num4 = "$[num3 * num4]

num5=$num3
num6=$num4
#ret=`expr $num5 \* $num6`
echo "expr  num3 \* num4  = " `expr $num5 \* $num6` 
ret=$?

if test $ret -eq 0
then
	printf "success\n"
else
	printf "error\n"
fi
