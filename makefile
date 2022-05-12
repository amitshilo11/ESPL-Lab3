all: exec

c-files: bubblesort.c task0.c
	gcc -g -c -o bubblesort.o bubblesort.c
	gcc -g -c -o task0.o task0.c

exec: c-files bubblesort.o task0.o
	gcc -g bubblesort.o -o bubblesort
	gcc -g task0.o -o task0

.PHONY: clean
clean:
	rm -rf ./*.o main