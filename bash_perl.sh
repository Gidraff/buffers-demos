#!/bin/bash

echo "About to prints a loop"

for i in $(head exploit_notsearch.c | grep "\"" | cut -d\" -f2); 
do
    echo -en $i
done > shellcode.bin