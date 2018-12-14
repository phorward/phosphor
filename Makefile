CFLAGS    	= -g -I../phorward/src -DUTF8 -DUNICODE -DDEBUG -Wall $(CLOCAL)
LIBPHORWARD	= ../phorward/src/libphorward.a

HEADERS		= \
			vm.h \
			proto.h

SOURCES   	=	\
			prog.c \
			run.c \
			vm.c \
			\
			main.c

OBJECTS		= $(patsubst %.c,%.o,$(SOURCES))

all: pvm

proto.h: $(SOURCES)
	pproto $(SOURCES) >$@

pvm: $(HEADERS) $(OBJECTS) $(LIBPHORWARD)
	$(CC) -g -o $@ $(OBJECTS) $(LIBPHORWARD)

test: pvm
	./pparse json.bnf bla.json

clean:
	-rm $(OBJECTS)
	-rm pvm
