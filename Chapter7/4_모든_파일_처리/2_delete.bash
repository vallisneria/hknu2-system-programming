#!/bin/bash

# 7장 69페이지
# 모든 파일 처리 문제 2
#
# 명령줄 인수로 주어진 디렉터리 내의 모든 파일과 서브디렉터리에 대해서
# 지울지 물은 후 y로 대답하면 지우는 bash script를 작성한다.
# 명령줄 인수가 없으면 현재 디렉터리를 대상으로 한다.

echo -n "delete? > "
read bool

if [ $bool == "y" ]
then


	if [ $# -eq 0 ]
	then

		rm -rf `pwd`   # current dir

	elif [ -d "$1" ]
	then
	
		cd $1/..
		rm -rf $1

	fi

fi
