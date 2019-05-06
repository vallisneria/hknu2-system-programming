#!/bin/bash

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
