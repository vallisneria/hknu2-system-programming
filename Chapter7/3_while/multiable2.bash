#!/bin/bash

# 7장 54페이지
# while 문제
#
# 구구단 2단을 출력하는 multiable2.bash를 작성하라.

i=1

while (( i<=9 ))
do
	let multiple=2*i
	echo "2 * $i = $multiple"
	let i=i+1
done
