#! /bin/bash

line=sudo cat /etc/passwd | grep -n "linux" | cut -d ":" -f 1
echo $line
line2=sudo cat /etc/passwd | grep "linux" | cut -d ":" -f 1,3,4
echo $line2
