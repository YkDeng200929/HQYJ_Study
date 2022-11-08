#! /bin/bash

read -p "Enter a file name: " file_name

if [ -f /home/linux/$file_name ]
then
	ls -l /home/linux/$file_name
else
	echo "welcome to wuhan" > /home/linux/$file_name.txt
fi
