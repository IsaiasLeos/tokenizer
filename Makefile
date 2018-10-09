HEADERS = tokenizer.h history.h

all: interface

interface: interface.o tokenizer.o history.o
	gcc interface.o tokenizer.o history.o -o interface

interface.o: interface.c $(HEADER)
	gcc -c interface.c -o interface.o

tokenizer.o: tokenizer.c
	gcc -c tokenizer.c -o tokenizer.o

history.o: history.c
	gcc -c history.c -o history.o
clean:
	-rm *.o
	-rm *~
	-rm *.c#
