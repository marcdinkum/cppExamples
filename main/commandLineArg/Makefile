CC = g++
CFLAGS = -I/usr/local/include -Wall


all: commandLineArg

commandLineArg: commandLineArg.o
	$(CC) -o $@ $(CFLAGS) commandLineArg.o -llo

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm +111 -type f`
