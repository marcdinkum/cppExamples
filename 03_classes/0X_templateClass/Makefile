CC = g++ -g

all: sum

sum: Point.o main.o
	$(CC) -o $@ Point.o main.o

.cpp.o:
	$(CC) -c $<

clean:
	rm -f *.o
	rm -f sum
