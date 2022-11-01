#! /bin/bash

LINE=`grep -n "linux" /etc/passwd | cut -d ":" -f 1`
echo $LINE
