#!/bin/bash

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

