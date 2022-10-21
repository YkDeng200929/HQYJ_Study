#! /bin/bash

sudo cat /etc/passwd | grep "linux" > log.txt
line=cut -d ":" -f 1 log.txt
echo $line
line2=cut -d ":" -f 1,3,4 log.txt
echo $line2
