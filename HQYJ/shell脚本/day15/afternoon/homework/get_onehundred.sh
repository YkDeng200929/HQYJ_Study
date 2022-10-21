#! /bin/bash
i=1
ret=0
for ((i; i <= 100; i++))
do
	let ret+=i
done

echo "$ret"
