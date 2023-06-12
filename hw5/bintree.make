CFLAGS = -Wall -Werror


output: bindemo.o bintree.o
	@echo "Generating the output executable"
	gcc ${CFLAGS} bindemo.o bintree.o -o output

bintree.o: bintree.c bintree.h
	@echo "generating the object file for bintree"
	gcc ${CFLAGS} -c bintree.c -o bintree.o

bindemo.o: bindemo.c bintree.h
	@echo "Generating the object file for bindemo"
	gcc ${CFLAGS} -c bindemo.c -o bindemo.o

clean:
	@echo "cleaning files..."
	rm *.o output