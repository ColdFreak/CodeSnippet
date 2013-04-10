#!/bin/bash
file=$1
comment=$2
# $# number of command line arguments
if [ $# -eq 0 ];then
	echo "Usage: ./ul.sh <file> comment"
	exit
fi
git add $1
git commit -m "$2"
git push -u origin master
