#! /bin/bash

ps -ef | grep init > log.txt
PINFO=`cat log.txt`
echo $PINFO
