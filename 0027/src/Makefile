BINDIR	= ../bin
# library dir of project
LIBDIR  = ../../lib
# include dir of solution
INCDIR	= ../lib/inc 
# source dir of solution
SRCDIR	= ../lib/src
CFLAGS	= -Wall
LFLAGS  = -lArgumentArray
CC		= gcc

SOLUTION_SRC=$(wildcard *.c)
SOLUTION_EXE=$(patsubst %.c, %.exe, $(SOLUTION_SRC))
SOLUTION_LIB_SRC=$(wildcard $(SRCDIR)/*.c)

all: $(SOLUTION_EXE) move

%.exe: %.c 
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBDIR)/bin $(LFLAGS) -I$(INCDIR) $(SOLUTION_LIB_SRC)

move:
	mv $(SOLUTION_EXE) $(BINDIR)
