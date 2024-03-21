#!/bin/bash
SRC_DIR=/home/vboxuser/prac
DST_DIR=/home/vboxuser/Downloads/check
if [ ! -d "$DST_DIR" ];	then
	mkdir -p "$DST_DIR"	
fi 

if [ ! -d "$SRC_DIR" ];	then 
	echo "Error: source directory does not exist"
		
fi

for file in "$SRC_DIR"/*; do
	cp "$file" "$DST_DIR"
done

echo "files successfully copied from '$SRC_DIR' to '$DST_DIR'"
	
