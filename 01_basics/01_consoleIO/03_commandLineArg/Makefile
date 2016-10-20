CC = g++ -g
CFLAGS = -Wall

all: commandLineArg

commandLineArg: commandLineArg.o
	$(CC) -o $@ $(CFLAGS) commandLineArg.o

.cpp.o:
	$(CC) -c $< $(CFLAGS)cd

clean:
	rm -f *.o
	rm -f `find . -perm +111 -type f`
