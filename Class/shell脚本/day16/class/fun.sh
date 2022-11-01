#! /bin/bash

sum()
{
	list=$@
	local i=0
	local ret=0
	for i in $list
	do
		let ret+=i
	done

	return $ret
}

sum $@

echo $?
