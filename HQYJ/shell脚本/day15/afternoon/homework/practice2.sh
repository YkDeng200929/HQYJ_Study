#! /bin/bash

read -p "Enter user name: " username
read -p "Enter passwd: " passwd
correct_user=linux
correct_pass=1

if [ $username = $correct_user -a $passwd -eq $correct_pass ]
then
	printf "账户及密码正确\n"
else
	printf "账户及密码输入错误\n"
fi
