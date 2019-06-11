#!/bin/bash

# 7장 54페이지
# while 문제
#
# 중첩 while문을 활용하여 구구단 3단부터 8단까지 출력하는
# multiable.bash를 작성하라.

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
