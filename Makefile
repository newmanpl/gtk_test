ifeq (,$(tg))
  tg=test1
endif

CC = gcc
CXX = g++
CFLAGS = `pkg-config --cflags --libs gtk+-2.0`

ifeq ($(tg),test1)
test: test1.c
	$(CC) -o $@ $^ $(CFLAGS)
	@echo "build test1"
endif
ifeq ($(tg),test2)
test: test2.c
        $(CC) -o $@ $^ $(CFLAGS)
	@echo "build test2"
endif
ifeq ($(tg),test3)
test: test3.c
	$(CC) -o $@ $^ $(CFLAGS)
	@echo "build test3"
endif
.PHONY: clean
clean:
#	-rm *.o test
	-rm test
