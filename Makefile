CC = gcc
CFLAGS	= -Wall -g
COFLAGS	= -Wall -c -g
OBJFILES = main.o quicksort.o lista.o info.o genrandom.o
LDFLAGS = -lm
TARGET = tp2
all: $(OBJFILES) 
	$(CC) $(CFLAGS) $(OBJFILES) -o $(TARGET) $(LDFLAGS)
main.o: main.c
	gcc $(COFLAGS) main.c
quicksort.o: quicksort.c quicksort.h
	gcc $(COFLAGS) quicksort.c
lista.o: lista.c lista.h
	gcc $(COFLAGS) lista.c
info.o: info.c info.h
	gcc $(COFLAGS) info.c
genrandom.o: genrandom.c genrandom.h
	gcc $(COFLAGS) genrandom.c
clear:
	rm -f $(OBJFILES) $(TARGET) *~
