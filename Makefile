HEADERS = tokenizer.h history.h

all: textUI

textUI: textUI.o tokenizer.o history.o
	gcc textUI.o tokenizer.o history.o -o textUI

textUI.o: interface.c $(HEADER)
	gcc -c interface.c -o textUI.o
tokenizer.o: tokenizer.c $(HEADER)
	gcc -c tokenizer.c -o tokenizer.o
history.o: history.c $(HEADER)
	gcc -c history.c -o history.o
clean:
	-rm *.o
	-rm *~
