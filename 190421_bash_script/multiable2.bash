#!/bin/bash

i=1

while (( i<=9 ))
do
	let multiple=2*i
	echo "2 * $i = $multiple"
	let i=i+1
done
