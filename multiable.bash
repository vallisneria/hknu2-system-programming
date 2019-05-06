#!/bin/bash

i=3

while (( i<=8 ))
do

	j=1

	while (( j<=9 ))
	do

		let multiple=i*j

		if [[ j -eq 9 ]]
		then
			echo "$i * $j = $multiple"
		else
			echo -n " $i * $j = $multiple |"
		fi

		let j=j+1

	done

	let i=i+1
	echo ""

done
