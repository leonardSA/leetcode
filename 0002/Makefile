BINDIR=bin
SRCDIR=src

all: compile

compile: bin
	make -C $(SRCDIR)

.phony: bin
bin:
	if [ ! -d $(BINDIR) ]; then mkdir $(BINDIR); fi

clean:
	rm -rf $(BINDIR)
