EXE=read_files ipc 04-exec 04-payload

04-payload: 04-payload.o
	ld -o 04-payload 04-payload.o

04-payload.o: 04-payload.asm
	nasm -o 04-payload.o -felf64 04-payload.asm

.PHONY: all
all: $(EXE)

%: %.c
	gcc -Wall  -o $@ $<

.PHONY: clean
clean: 
	rm -rfv $(EXE) 04-payload.0