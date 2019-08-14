#! /bin/bash

output: main.o openfile.o createmasterarray.o codelength.o compress2.o compress3.o compress4.o compress5.o compress6.o compress7.o init.o unique.o decompress2.o decompress3.o decompress4.o decompress5.o decompress6.o decompress7.o exit.o compression.o decompression.o mainmenu.o 
	gcc -o output main.o openfile.o createmasterarray.o codelength.o compress2.o compress3.o compress4.o compress5.o compress6.o compress7.o init.o unique.o decompress2.o decompress3.o decompress4.o decompress5.o decompress6.o decompress7.o exit.o compression.o decompression.o mainmenu.o



exit.o: exit.c header.h prototype.h
	gcc -c exit.c
mainmenu.o: mainmenu.c header.h prototype.h
	gcc -c mainmenu.c
compression.o: compression.c header.h prototype.h
	gcc -c compression.c
decompression.o: decompression.c header.h prototype.h
	gcc -c decompression.c
decompress2.o: decompress2.c header.h prototype.h
	gcc -c decompress2.c
decompress3.o: decompress3.c header.h prototype.h
	gcc -c decompress3.c
decompress4.o: decompress4.c header.h prototype.h
	gcc -c decompress4.c
decompress5.o: decompress5.c header.h prototype.h
	gcc -c decompress5.c
decompress6.o: decompress6.c header.h prototype.h
	gcc -c decompress6.c
decompress7.o: decompress7.c header.h prototype.h
	gcc -c decompress7.c
unique.o: unique.c header.h prototype.h
	gcc -c unique.c
init.o: init.c header.h prototype.h
	gcc -c init.c
compress7.o: compress7.c header.h prototype.h
	gcc -c compress7.c
compress6.o: compress6.c header.h prototype.h
	gcc -c compress6.c
compress5.o: compress5.c header.h prototype.h
	gcc -c compress5.c
compress4.o: compress4.c header.h prototype.h
	gcc -c compress4.c
compress3.o: compress3.c header.h prototype.h
	gcc -c compress3.c
compress2.o: compress2.c header.h prototype.h
	gcc -c compress2.c
codelength.o: codelength.c header.h prototype.h
	gcc -c codelength.c
createmasterarray.o: createmasterarray.c header.h prototype.h
	gcc -c createmasterarray.c
openfile.o: openfile.c header.h prototype.h
	gcc -c openfile.c
main.o: main.c header.h prototype.h
	gcc -c main.c


close:
	rm *.o
