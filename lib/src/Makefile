BINDIR=../bin
INCDIR=../inc
CC=gcc
CFLAGS=-Wall
LFLAGS=-lc

LIBSRC=$(wildcard *.c)
LIBSO=$(patsubst %.c, %.so, $(LIBSRC))

all: $(LIBSO) move

%.so: %.c $(INCDIR)/%.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ $(LFLAGS)

move: 
	mv $(LIBSO) $(BINDIR)
