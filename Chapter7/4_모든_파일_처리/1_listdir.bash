#!/bin/bash

# 7장 68페이지
# 모든 파일 처리 문제 1
#
# 명령줄 인수로 주어진 디렉터리 내의 모든 서브디렉터리를 리스트하는
# bash script를 작성하라. 명령줄 인수가 없으면 현재 디렉터리를 대상으로 한다.

if [ $# -eq 0 ]
then
	
	~/Documents/190428_bash_script/listdir.bash .

elif [ -d $1 ]
then

	cd $1
	for file in *
	do
		
		if [ -d  "$file" ]
		then
		
			echo "$file"
			~/Documents/190428_bash_script/listdir.bash $file
			

		fi
	


	done


fi
