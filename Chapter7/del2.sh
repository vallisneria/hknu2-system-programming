#!/bin/sh

# 7장 13페이지
# bash script 문제
# 
# 파일을 제거하지 않고 휴지통으로 옮기는 bash script를 작성한다.

mv $* ~/.local/share/Trash/files/
