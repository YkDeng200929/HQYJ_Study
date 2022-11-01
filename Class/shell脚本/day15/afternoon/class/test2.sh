#! /bin/bash

val1=$1
val2=$2

let val1++
let val2++
((ret1 = val1 * val2))

# printf 打印整形值时需要加上 $ 不然视为未知
printf "val1++ x val2++ = %d\n" $ret1

let ret=val1*val2

printf "val1 * val2 = %d\n" $ret
