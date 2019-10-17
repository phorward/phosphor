AWK	= awk
CFLAGS = -g -I. -DUTF8 -DUNICODE -DDEBUG -Wall $(CLOCAL)

HEADERS		= \
			lib/phorward.h \
			any/any.h \
			vm/vm.h \
			phosphor.h \
			proto.h

PHORWARD	= \
			lib/phorward.c

SOURCES   	=	\
			any/any.c \
			any/any.conv.c \
			any/any.get.c \
			any/any.print.c \
			any/any.set.c \
			vm/prog.c \
			vm/run.c \
			vm/vm.c \
			\
			main.c

OBJECTS		= $(patsubst %.c,%.o,$(PHORWARD)) $(patsubst %.c,%.o,$(SOURCES))

all: pvm

pvm: $(HEADERS) $(OBJECTS)
	cc -o $@ $(OBJECTS) $(LDFLAGS)

proto.h: $(SOURCES)
	lib/pproto $(SOURCES) >$@

clean:
	-rm $(OBJECTS)
	-rm pvm

clean_all: clean
	-rm any/any.conv.c
	-rm any/any.get.c
	-rm any/any.print.c
	-rm any/any.set.c

# pany object functions (generated from definitions in any.h comments)

any/any.get.c: any/any.h any/any.gen.awk
	$(AWK) -f any/any.gen.awk -vwith_get=1 any/any.h >$@

any/any.set.c: any/any.h any/any.gen.awk
	$(AWK) -f any/any.gen.awk -vwith_set=1 any/any.h >$@

any/any.conv.c: any/any.h any/any.gen.awk
	$(AWK) -f any/any.gen.awk -vwith_conv=1 any/any.h >$@

any/any.print.c: any/any.h any/any.gen.awk
	$(AWK) -f any/any.gen.awk -vwith_fprint=1 any/any.h >$@

# Test suite
test: all
	lib/ptest -v $(SOURCES)

