all: build run

build:
	gcc VigenereGen.c -o VigenereGen

run:
	./VigenereGen

clean:
	rm -f VigenereGen
