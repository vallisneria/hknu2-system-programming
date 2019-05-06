#!/bin/bash

i=1

while (( i<=9 ))
do
	let multiple=3*i
	echo "3 * $i = $multiple"
	let i=i+1
done
