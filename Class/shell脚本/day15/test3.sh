#! /bin/bash

echo "hello" > log2.txt
num=$1
count=$#
echo "There have $count parameter in this shell script, It's $num" >> log2.txt
cat log2.txt
if ($? == 0)
	echo "Success!"
else
	echo "error"
fi
