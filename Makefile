ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

tpkb: src/tp.cpp hid.o src/hidapi.h
	g++ -o tpkb src/tp.cpp hid.o -framework CoreFoundation -framework IOKit

hid.o: src/hid.c src/hidapi.h
	gcc -c -o hid.o src/hid.c

.PHONY: install
install: tpkb
	install -m 0755 $? $(PREFIX)/bin/tpkb

.PHONY: clean
clean:
	git clean -Xf
