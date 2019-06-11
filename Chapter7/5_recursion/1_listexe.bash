#!/bin/bash

# 7장 71페이지
# Recursion 문제
#
# 리커전을 이용하여 명령줄 인수로 받은 디렉터리 이하에 있는
# 모든 실행 가능한 일반 파일들만 리스트하는 bash script를 작성하라.
# 명령줄 인수가 없으면 현재 디렉터리를 대상으로 한다.

if [ $# -eq 0 ]
then
	
	~/Documents/190428_bash_script/listexe.bash .

elif [ -d $1 ]
then

	cd $1
	for file in *
	do
		
		if [ -x  "$file" ]
		then

			if [ -d "$file" ]
			then
		
				~/Documents/190428_bash_script/listexe.bash $file

			elif [ -f "$file" ]
			then

				echo "`pwd`/$file"

			fi
			
		fi
	

	done

fi
