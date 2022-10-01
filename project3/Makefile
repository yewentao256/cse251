scheduler:	scheduler.o io.o 
	gcc -o scheduler scheduler.o io.o

scheduler.o:	scheduler.c scheduler.h
	gcc -c scheduler.c

io.o:	io.c scheduler.h
	gcc -c io.c

clean:
	rm -f *.o scheduler