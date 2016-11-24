CC = g++ -g

all: instrument

instrument: Instrument.o StringInstrument.o main.o
	$(CC) -o $@ Instrument.o StringInstrument.o main.o

.cpp.o:
	$(CC) -c $<

clean:
	rm -f *.o
	rm -f instrument
