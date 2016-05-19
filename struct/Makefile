CC = gcc

main: struct.o
	${CC} -s -o $@ $<

$.o: %.c
	${CC} -c -o $@ $<

clean:
	/bin/rm -f *.o main

.PHONY: clean
