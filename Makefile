#GCC := gcc
#cflag := -std=c20 -march=native -Ofast
#src := initfile.c
#outputname := initfile
#PREFIX ?= /usr/local


#build:
#	$(GCC) $(cflag) $(src) -o $(outputname)

#install:build
#       	install -d $(PREFIX)/bin
#	install -m 755 $(outputname) $(PREFIX)/bin/$(outputname)

#clean:
#	rm -f $(outputname)
GCC := gcc
CFLAGS := -std=c2x -march=native -Ofast
SRC := initfile.c       
OUT := initfile
PREFIX ?= /usr/local

build:
	$(GCC) $(CFLAGS) $(SRC) -o $(OUT)

install: build
	install -d $(PREFIX)/bin
	install -m 755 $(OUT) $(PREFIX)/bin/$(OUT)

clean:
	rm -f $(OUT)

