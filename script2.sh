#!/bin/bash
process_data(){
input_file=$1
	output_file=$(cut -f 1,3 $input_file | grep 'jaja' | sort -n)
echo $output_file
}

for file in /home/vboxuser/prac/text.txt; do
	processed_data=$(process_data $file) 	
	echo "$processed_data" > "${file}_processed.txt"	
done
