#! /bin/bash

read -p "Enter: " val1 val2

let ret=val1*val1-val2*val2

ret2=`expr $val1 \* $val1 - $val2 \* $val2`

# 当对变量进行运算且需赋值给其他变量时需要在中括号前加上$
ret3=$[val1*val1-val2*val2]

printf "val1^2 - val2^ =or %d  %d or %d\n" $ret3 $ret $ret2
