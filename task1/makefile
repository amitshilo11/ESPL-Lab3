all: exec

c-files: bcmp.c task1.c task1b.c
	gcc -g -c -o bcmp.o bcmp.c
	gcc -g -c -o task1.o task1.c
	gcc -g -c -o task1b.o task1b.c

exec: c-files bcmp.o task1.o task1b.o
	gcc -g bcmp.o -o bcmp
	gcc -g task1.o -o task1
	gcc -g task1b.o -o task1b

.PHONY: clean
clean:
	rm -rf ./*.o main