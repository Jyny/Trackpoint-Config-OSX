tpcfg: tp.cpp hid.o hidapi.h
	g++ -o tpcfg tp.cpp hid.o -framework CoreFoundation -framework IOKit

hid.o: hid.c hidapi.h
	gcc -c -o hid.o hid.c

.PHONY: clean
clean:
	-rm -rf tpcfg *.o
