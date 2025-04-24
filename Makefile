EXE=read_files ipc

.PHONY: all
all: $(EXE)

%: %.c
	gcc -Wall  -o $@ $<

.PHONY: clean
clean: 
	rm -rfv $(EXE)