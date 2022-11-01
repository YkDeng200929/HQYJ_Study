#! /bin/bash

read -p "Enter a path of directoy: " dir_name

if [ -d /home/linux/$dir_name ]
then
	read -p "Do you want to delete?: y/n" input
	case $input in
		"y")
			rm -rf /home/linux/$dir_name
			echo "delete success"
			;;
		"n")
			echo "No thing" > /home/linux/$dir_name/file.txt
			cat /home/linux/$dir_name/file.txt
			;;
		*)
			echo "error"
	esac
fi
