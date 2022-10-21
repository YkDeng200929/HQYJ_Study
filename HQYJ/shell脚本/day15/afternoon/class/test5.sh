#! /bin/bash

read -p "Enter two numbers: " num1 num2

# 中括号前后得有空格
[ $num1 -eq $num2 ]

echo "num1 = num2 $?"
