CFLAGS = -Wall -Werror


output: selsortls.o dlintlist.o
	@echo "Generating the output executable"
	gcc ${CFLAGS} selsortls.o dlintlist.o -o output

selsortls.o: selsortls.c dlintlist.h
	@echo "generating the object file for selsortls"
	gcc ${CFLAGS} -c selsortls.c -o selsortls.o

dlintlist.o: dlintlist.c dlintlist.h
	@echo "Generating the object file for dlintlist"
	gcc ${CFLAGS} -c dlintlist.c -o dlintlist.o

clean:
	@echo "cleaning files..."
	rm *.o output