CFLAGS= -Wall -Wextra -pedantic -Wno-long-long -ansi -O2
OBJS=$(patsubst %.c, %.o, $(wildcard *.c))
EXEC=teste

$(EXEC): $(OBJS)
		$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

limpar:
		rm $(EXEC) *.o

install: teste
