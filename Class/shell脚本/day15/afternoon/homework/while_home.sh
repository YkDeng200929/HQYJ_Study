#! /bin/bash

judge=$#

case $judge in
	"1")
		touch ./$1{1..5}.txt
		;;
	"2")
		touch ./$1{1..$2}.txt
		;;
	*)
		echo "error"
esac
