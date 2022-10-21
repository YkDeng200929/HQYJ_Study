#! /bin/bash

read -p "Enter year month day: " year month day
printf "date: %d-%d-%d\n" $year $month $day

read -p "Enter name age school_number: " name age number
printf "your name: %s  yout age: %d your school number: %d\n" $name $age $number
