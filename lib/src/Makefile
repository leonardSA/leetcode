BINDIR=../bin
INCDIR=../inc
CC=gcc
CFLAGS=-Wall
LFLAGS=-lc

LIBSRC=$(wildcard *.c)
LIBSO=$(patsubst %.c, %.so, $(LIBSRC))

all: $(LIBSO) move

%.so: %.c $(INCDIR)/%.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ $(shell ./requirements.sh $^.c) $(LFLAGS)

move: 
	mv $(LIBSO) $(BINDIR)
