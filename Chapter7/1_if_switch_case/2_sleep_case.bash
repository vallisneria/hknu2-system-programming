#!/bin/bash

# 7장 49페이지
# case 문제
#
# 피곤한지 물어본 후
# Y라고 응답하면 "수면 시간을 늘려보세요"
# N이라고 응답하면 "건강하시군요" 라고 출력되도록 작성한다.


declare sleepChar="y"
declare -i exitBoolean=0

while (($exitBoolean==0))
do
	echo -n "Are you sleep? (y/n/q): "
	read sleepChar

	case $sleepChar in
		"y" | "Y" ) echo "You are healthy"; echo "I give you one more question";;
		"n" | "N" ) echo "You need more sleep"; echo "one more question";;
		"q" ) exitBoolean=1;;
		* ) echo "You entered incorrectly";;
	esac
done
