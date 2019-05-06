#!/bin/bash

max_num=0
min_num=101
even_num=""
odd_num=""

for num in $*
do
	if [ $num -gt $max_num ]
	then
		max_num=$num
	fi

	if [ $num -lt $min_num ]
	then
		min_num=$num
	fi

	let tmp=$num%2
	if [ $tmp -eq 0 ]
	then
		even_num="$even_num $num"
	fi

	if [ $tmp -eq 1 ]
	then
		odd_num="$odd_num $num"
	fi
done

echo "max: $max_num"
echo "min: $min_num"
echo "even: $even_num"
echo "odd: $odd_num"
