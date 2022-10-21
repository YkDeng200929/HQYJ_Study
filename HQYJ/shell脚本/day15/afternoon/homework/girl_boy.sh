#! /bin/bash

read -p "Enter your sex: " sex

case $sex in
	"girl")
		echo "She is a girl"
		;;
	"boy")
		echo "He is a boy"
		;;
	*)
		echo "I dont know"
esac
