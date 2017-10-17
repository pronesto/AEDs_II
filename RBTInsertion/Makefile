IDIR   = include
CC     = clang
CFLAGS = -I$(IDIR)

ODIR=obj

_DEPS = RBT.h Tree.h TreeGen.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = RBT.o Tree.o TreeGen.o

_OBJ_DOT = DotMain.o $(_OBJ)
OBJ_DOT = $(patsubst %,$(ODIR)/%,$(_OBJ_DOT))

_OBJ_TIME = TimeTreeMain.o $(_OBJ)
OBJ_TIME = $(patsubst %,$(ODIR)/%,$(_OBJ_TIME))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -Wall -c -o $@ $< $(CFLAGS)

DotMain: $(OBJ_DOT)
	$(CC) -Wall -o $@ $^ $(CFLAGS)

TimeTreeMain: $(OBJ_TIME)
	$(CC) -Wall -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
