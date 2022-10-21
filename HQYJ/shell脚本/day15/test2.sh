#! /bin/bash

#ps -ef | grep init > log.txt
#PINFO=`cat log.txt`
PINFO=`ps -ef | grep init`
echo $PINFO
