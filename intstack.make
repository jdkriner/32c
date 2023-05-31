CFLAGS = -Wall -Werror


output: intstack.o stackDemo.o
	@echo "Generating the output executable"
	gcc ${CFLAGS} intstack.o stackDemo.o -o output

intstack.o: intstack.c
	@echo "generating the object file for intstack"
	gcc ${CFLAGS} -c intstack.c -o intstack.o

stackDemo.o: stackDemo.c
	@echo "Generating the object file for stackDemo
	gcc ${CFLAGS} -c stackDemo.c -o stackDemo.o

clean:
	@echo "cleaning files..."
	rm *.o output
