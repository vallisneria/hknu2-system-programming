#!/bin/bash

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
