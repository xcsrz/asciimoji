

default: bin/emot bin/flip

bin/emot: bin
	gcc emot.c pbcopy.c -o bin/emot

bin/flip: bin
	gcc flip.c pbcopy.c -o bin/flip

bin:
	@mkdir -p ./bin

clean:
	@rm -f ./bin/*

install: ~/bin/emot ~/bin/flip

~/bin/emot: bin/emot
	@mv bin/emot ~/bin/emot

~/bin/flip: bin/flip
	@mv bin/flip ~/bin/flip

.PHONY: ~/bin/emot ~/bin/flip