CFLAGS= -Wall -pedantic -Wno-long-long -ansi -O2 -std=c99
OBJS=$(patsubst %.c, %.o, $(wildcard *.c))
EXEC=teste

$(EXEC): $(OBJS)
		$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)
		rm *.o
limpar:
		rm $(EXEC) *.o

install: teste
