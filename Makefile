#debian appears to be making the switch to better multiarch support, but until pkgconfig handles it, hardcode away
LFLAGS  = 
CFLAGS  = -g -Wall -Wextra -Wno-unused-parameter
SOURCES=`ls *.c`
BUILDS=kraken

all: .depend kraken

.depend:
	fastdep $(SOURCES) > .depend

-include .depend

kraken:\
	mem.o\
	main.o\
	instruction.o\
	io.o\
	loader.o\
	vm.o\
	registers.o
	gcc -o $@ $^ ${LFLAGS}

clean:
	rm -f *.o .depend $(BUILDS)
