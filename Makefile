CC = gcc
CXX = g++
CFLAGS = `pkg-config --cflags --libs gtk+-2.0`

test: test.c
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
#	-rm *.o test
	-rm test
