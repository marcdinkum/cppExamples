CC = g++ -g
CFLAGS = -std=c++1z

all: synth

synth: main.o
	$(CC) -o $@ $(CFLAGS) main.o

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f synth
