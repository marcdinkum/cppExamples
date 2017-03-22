CC = g++ -g
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -L/usr/local/lib -loctopus -lbear-audio -lgrizzly -lmath

PROG = simpleRead

SRC_OBJS = main.o
OBJS = main.o

all: $(PROG)

$(PROG): $(SRC_OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS) $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f *.h.gch
	rm -f $(PROG)
