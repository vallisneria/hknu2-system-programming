#!/bin/bash

# 7장 54페이지
# while 문제
#
# 구구단 3단을 출력하는 multiable3.bash를 작성하라.

i=1

while (( i<=9 ))
do
	let multiple=3*i
	echo "3 * $i = $multiple"
	let i=i+1
done
