#!/bin/bash

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
