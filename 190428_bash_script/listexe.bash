#!/bin/bash

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
