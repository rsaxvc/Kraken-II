#debian appears to be making the switch to better multiarch support, but until pkgconfig handles it, hardcode away
LFLAGS  = 
CFLAGS  = -g -Wall -Wextra -Wno-unused-parameter -Wshadow -Wmissing-prototypes
SOURCES=`ls *.c`
BUILDS=kraken kasm
KASM_LFLAGS = ${LFLAGS} -ll -lm
KRKN_LFLAGS = ${LFLAGS}

all: .depend kasm kraken

kasm.yy.c: kasm.yy
	flex --outfile=$@ $^

kasm.tab.c: kasm.y
	bison $^

.depend:
	fastdep $(SOURCES) > .depend

-include .depend

kasm:\
	kasm.tab.o\
	kasm.o\
	kasm.yy.o
	gcc -o $@ $^ ${KASM_LFLAGS}

kraken:\
	mem.o\
	main.o\
	instruction.o\
	io.o\
	loader.o\
	vm.o\
	registers.o
	gcc -o $@ $^ ${KRKN_LFLAGS}

clean:
	rm -f *.o .depend $(BUILDS) kasm.tab.c
