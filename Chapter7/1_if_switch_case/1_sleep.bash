#!/bin/bash

# 7장 47페이지
# 중첩조건문 문제
#
# 피곤한지 물어본 후
# Y라고 응답하면 "수면 시간을 늘려보세요"
# N이라고 응답하면 "건강하시군요" 라고 출력되도록 작성한다.

echo -n "Are you sleep? (y/n): "
read sleepBoolean

if [[ $sleepBoolean != [yYnN] ]]
then
	echo "You entered incorrectly"

elif [[ $sleepBoolean =~ [yY] ]]
then
	echo "You are healthy"

elif [[ $sleepBoolean =~ [nN] ]]
then
	echo "You need more sleep.."
fi

