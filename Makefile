all:
	gcc -Wall -I/usr/include/webkit-1.0/ -I/usr/include/libsoup-2.4/ -g groovtk.c -o groovtk `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0 webkit-1.0`
