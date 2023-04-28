CC=clang++

#CFLAGS= -march=rv64g -mepi -O2 -g -fno-vectorize -mcpu=avispado -Rpass=loop-vectorize -Rpass-analysis=loop-vectorize
CFLAGS= -mepi -O3
#CFLAGS= -mepi
#CFLAGS=

#LDFLAGS= -lm

.PHONY: all

all: test01 test02

test01: test01.c
	$(CC) $(CFLAGS) -o $@ $<

test02: test02.cpp
	$(CC) $(CFLAGS) -o $@ $<


.PHONY: clean
	
clean: 
	rm -f *.o
	rm -f test01 test02

