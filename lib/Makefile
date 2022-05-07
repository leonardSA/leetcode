BINDIR = bin
SRCDIR = src

.phony: output

all: compile

compile: output
	make -C $(SRCDIR)

output:
	if [ ! -d $(BINDIR) ]; then mkdir $(BINDIR); fi

clean:
	rm -rf $(BINDIR)
