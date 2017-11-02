all: devrandom.c
	gcc directory_testing.c

run: all
	./a.out

clean:
	rm *.o
	rm *~
	rm a.out
